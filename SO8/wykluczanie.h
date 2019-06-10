#define _REENTRANT
#define THREADS_NUM 10

#define RED "\x1B[31m"
#define NORMAL "\x1B[0m"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int counter = 0;
pthread_mutex_t lock;

void *func(void*);
