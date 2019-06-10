#include "sem.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>


int main(int argc, char* argv[])
{
    char *name = "/mysem";
    if(argc != 3)
    {
        printf("Nieprawidlowa ilosc argumentow. Prawidlowa skladnia: ./powielacz.x ./prog.x [liczba]\n");
        exit(1);
    }
    int count = atoi(argv[2]);
    
    pid_t pid;
    
    semid sem = semCreate(name, 1);
    
    for(int i = 0; i < count; i++)
    {
        pid = fork();
        switch(pid)
        {
            case -1:
                perror("Fork error");
                exit(-1);
            case 0: //child process
                execl(argv[1], argv[1], NULL);
                break;
            default:    
                break;
        }
    }
    
    for(int i = 0; i < count; i++)
    {
        wait(NULL);
    }
    
    semRemove(name);
}
