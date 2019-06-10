//gcc sem.c-L. -lsem
#include <semaphore.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h> /* For mode constants */
#include <fcntl.h> /* For O_* constants */
#include <stdlib.h>
#include "sem.h"
#include <unistd.h>

semid semOpen(const char *name)
{
    semid s = sem_open(name, O_CREAT, 0666);
    if(s == SEM_FAILED)
    {
        perror("An error occured while opening semaphore\n");
        exit(-1);
    }
    else
    {
        printf("Semaphore has been opened\n");
        return s;
    }
}

semid semCreate(const char *name, int initial_value)
{
    semid s = sem_open(name, O_CREAT  | O_EXCL, 0666, initial_value);
    if(s == SEM_FAILED)
    {
        perror("Error! Semaphore already exists\n");
        exit(-1);
    }
    else
    {
        printf("Semaphore created successfully. Initial value = %d\n", initial_value);
        return s;
    }
}

void semRemove(const char* name)
{
    int s = sem_unlink(name);
    if(s == -1)
    {
        perror("Error closing semaphore\n");
        exit(-1);
    }
    else
    {
        printf("Semaphore has been closed\n");
    }
}

void semP(semid sem)
{
    sem_wait(sem);
    printf("Success p() operation\n");
}

void semV(semid sem)
{
    int s = sem_post(sem);
    if(s == -1)
    {
        perror("Error v() operation\n");
        exit(-1);
    }
    else
    {
        printf("Success v() operation\n");
    }
}

void semInfo(semid sem)
{
    int val;
    if(sem_getvalue(sem, &val)==-1)
    {
        perror("seminfo error");
    }
    else
    {
        printf("Wartosc semafora: %d\n", val);
    }
}
