#ifndef SEM_H
#define SEM_H
#include <semaphore.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */

typedef sem_t *semid;

semid semCreate(const char *name, int val); //Tworzy semafor z wartością początkową val.
semid semOpen(const char *name); //Uzyskuje dostęp do istniejącego semafora.
void semRemove(const char* name);
void semP(semid sem);
void semV(semid sem);
void semInfo(semid sem);
void semClose(semid sem);

#endif
