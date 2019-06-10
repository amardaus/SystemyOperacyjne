#include "shmem.h"
#include "sem.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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


void pull(struct cykliczny* buff)
{
    /*if(buff->head == buff->tail)
    {
        printf("Buffer is empty!\n");
        semid sem = semOpen(name);
        semV(sem);
    }*/
    
    int next = buff->tail+1;
    if(next == N)
    {
        next = 0;
    }
    printf("\tpull[%d]: %c\n", next, buff->data[next]);
    buff->tail = next;
}



int main()
{
    int fd;
    char *file_name = "schowek.txt";
    FILE *output;
    output = fopen(file_name, "r");
    if(output == NULL)
    {
        perror("Error opening output file\n");
        exit(-1);
    }
    
    int sd = shmOpen("/cbuff");
    struct cykliczny* buff;
    buff = (struct cykliczny*)mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, sd, 0);
    
    /*while(1)
    {
        pull(buff);
    }*/
    
    close(fd);
    fclose(output);
}
