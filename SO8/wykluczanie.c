#include "wykluczanie.h"

void *func(void* arg)
{
    int id = *(int*)arg;
    int priv_counter = counter;
    int res;
    
    //printf("\033[%d;%dHbeczka\n", 1,1);
    //printf("Jestem w sekcji prywatnej\n");
    printf("\033[%d;%dHx\n",id+1,40);
    
    res = pthread_mutex_lock(&lock);
    if(res == 0)
    {
        priv_counter++;
        int row = counter +1;
        sleep(1);
        printf("\033[%d;%dHx\n",id + 1,80);
        printf("\033[%d;%dH%10s \n", id + 1, 40, "");
        //printf("Counter=%d\n", counter);
        sleep(1);
        printf("\033[%d;%dH%10s \n", id + 1, 80, "");
        printf("\033[%d;%dHx\n",id+1,40);
        sleep(1);
        counter++;
        
        pthread_mutex_unlock(&lock);
    }
    else
    {
        printf("Error locking mutex\n");
    }
    
}

int main(int argc, char* argv[])
{ 
    
    int res;
    
    if(pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Error initializing mutex");
        exit(EXIT_FAILURE);
    }
    
    //printf("%sred%s\n", RED, NORMAL);
    printf("\033c");
    
    //printf("\033[%d,%dSekcja krytyczna",1000,100);
    printf("\033[%d;%dHSekcja prywatna",1,40);
    printf("\033[%d;%dHSekcja krytyczna",1,80);
    
    int ids[THREADS_NUM];    
    for(int i = 1; i <= THREADS_NUM; i++)
    {
        printf("\033[%d;%dHWatek %d pozdrawia\n",i+1,1,i);
        ids[i-1] = i;
    }
    
    
    pthread_t th_arr[THREADS_NUM];
    for(int i = 0; i < THREADS_NUM; i++)
    {
        res = pthread_create(&th_arr[i], NULL, func, (void*)&ids[i]);
        if(res != 0)
        {
            printf("Blad tworzenia watku\n");
            perror("Error");
            exit(EXIT_FAILURE);
        }
    }
    
    //to musza byc dwie osobne petle bo inaczej by czekal na zakonczenie wczesniejszego z utworzeniem kolejnego watku
    for(int i = 0; i < THREADS_NUM; i++)
    {
        pthread_join(th_arr[i], NULL);
    }
    
    pthread_mutex_destroy(&lock);
    //zeby kazdy watek mial numer okreslajacy numer wiersza w ktorym beda informacje o nim
    // 
}

