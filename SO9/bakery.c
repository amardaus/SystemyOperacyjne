#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>    //bool type
#include <unistd.h>
//#include <stdatomic.h>
#define N 4
#define ITERATIONS 1000000
//#define MBAR __sync_synchronize()
#define MBAR asm volatile ("mfence" ::: "memory")
//  membar is used to enforce an ordering constraint on memory operations issued before and after the barrier instruction.
//  this means that operations issued prior to the barrier are guaranteed to be performed before operations issued after the barrier
//  asm volatile ("mfence" ::: "memory") is both a compiler barrier and CPU barrier.

volatile int num[N] = {0};
volatile bool entering[N] = {false};
//entering array is used to indicate that a process wants to enter critical section and is in the middle of selecting a number
//volatile atomic_int licznik = 0;
volatile int licznik = 0;

void lock(long th)
{
    entering[th] = true;
    
    MBAR;
    int max = 1;  
    //finding max
    for(int i = 0; i < N; i++)
    {
        if(num[i] > max)
        {
            max = num[i];
        }
    }
    
    num[th] = max + 1;
    
    entering[th] = false;
    MBAR;
    printf("num[%ld]=%d\n", th, num[th]);
    
    for(int j = 0; j < N; j++)
    {
        while(entering[j] == true) {}
        //czeka, jesli istnieje watek ktory tez wyrazil chec wejscia do sekcji krytycznej i aktualnie ustala swoj numer (bo moze bedzie nizszy!)
        while((num[j] != 0) && ((num[th] > num[j]) || ((num[th] == num[j]) && (th > j)))) {}
        //czeka, jesli watek ktory tez wyrazil chec wejscia do sekcji krytycznej ma nizszy numer (w kolejce lub taki sam numer w kolejce ale niszy id)
    }
}

void unlock(long th)
{
    //printf("Thread %ld left critical section\n", th);
    //MBAR;
    num[th] = 0;
}

void dosomething(long th)
{
     printf("Thread %ld is in critical section!\n", th);
     //usleep(100); 
     //sleep(1);
}

void* func(void* arg)
{
    long th = (long)arg;
    for(int i = 0; i < ITERATIONS; i++)
    {
        lock(th);
        dosomething(th);
        licznik++;
        unlock(th);
    }
    //printf("th %ld done\n", th);
    return NULL;
}

int main()
{
    int i;
    int res;
    int thread_num;
    pthread_t t_arr[N];
    
    
    for(i = 0; i < N; i++)
    {
        res = pthread_create(&t_arr[i], NULL, func, (void*)(long)i);
        
        if(res != 0)
        {
            printf("Error creating thread nr %d", i);
            perror("Error");
            exit(EXIT_FAILURE);
        }
        printf("Thread nr %d created\n", i);
        
    }
    
    
    
    for(i = 0; i < N; i++)
    {
        res = pthread_join(t_arr[i], NULL);
        
        if(res != 0)
        {
            printf("Error waiting for thread nr %d", i);
            perror("Error");
            exit(EXIT_FAILURE);
        }
        //printf("Thread nr %d finished\n", i);
    }
    
    printf("Licznik=%d", licznik);
    printf("\n");
    
}
