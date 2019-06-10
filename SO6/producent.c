#include "shmem.h"
#include "sem.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#define SIZE 1024
#define N 5
char* name = "/mysem";

struct cykliczny
{
    int size;
    int head;
    int tail;
    char data[N];
};

void push(struct cykliczny* buff, char element)
{
    
    int next = buff->head+1;
    if(next == N)
    {
        //printf("End of buffer\n");
        next = 0;
    }
    
    /*if(next == buff->tail)
    {
        printf("Buffer is full!\n");
        semid sem = semOpen(name);
        semP(sem);
        semInfo(sem);
    }*/
    
    buff->data[next] = element;
    printf("push[%d]: %c\n", next, buff->data[next]);
    buff->head = next;
}

int main()
{
    int fd;
    char *file_name = "magazyn.txt";
    FILE *input;
    input = fopen(file_name, "r");
    if(input == NULL)
    {
        perror("Error opening file\n");
        exit(-1);
    }
    
    //shmCreate("/cbuff", SIZE);
    int sd = shmOpen("/cbuff");
    struct cykliczny* buff;
    
    buff = (struct cykliczny*)mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, sd, 0);
    buff->size = N;
    buff->head = 0;
    buff->tail = 0;
    
    char c;
    int i = 0;
    while((c = fgetc(input)) != EOF)
    {
        push(buff, c);
        //printf("%c", c);
        i++;
        i%5;
    }
    
    close(fd);
    fclose(input);
}
