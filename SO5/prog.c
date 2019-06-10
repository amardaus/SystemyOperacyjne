#include "sem.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int random_time;
    srand(time(0));
    random_time = rand() % 100000;
    random_time *= 10; 
    
    semid sem = semOpen("/mysem");
    
    printf("Proces %d oczekuje na sekcje krytyczna\n", getpid());
    semP(sem);
    
    printf("Proces %d jest w sekcji krytycznej\n", getpid());
    usleep(random_time);    
    //proces "jest" w sekcji krytycznej przez randomowy czas
    
    semV(sem);
    printf("Proces %d opuscil sekcje krytyczna\n", getpid());
}
