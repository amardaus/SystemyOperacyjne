#include <stdio.h>
#include <stdlib.h>  //atoi
#include <string.h>  //strlen
#include <ctype.h>   //isdigit
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


void custom_handler(int sig)
{
    printf("Sygnal %d przechwycony!\n", sig);
    exit(0);
}

int main(int argc, char* argv[])
{
    if(argc == 3)
    {
        if(strlen(argv[1])!=1)   
        //jesli argument nie jest char'em
        {
            printf("Pierwszy argument powinien byc char'em\n");
            exit(0);
        }
        
        if(!isdigit(*argv[2]))
        {
            printf("Drugi argument powinien byc numerem sygnalu\n");
            exit(0);
        }
        
        char c = *argv[1];
        int num = atoi(argv[2]);
        printf("Dla procesu o nazwie %s: UID:%d\t GID:%d\t PID:%d\t PPID:%d\t PGID:%d\t\n", argv[0], getuid(), getgid(), getpid(), getppid(), getpgid(getpid())); 
        
        switch(c)
        {
            case 'd':   //default action
                signal(num, SIG_DFL);
                break;
            case 'i':   //ignore
                signal(num, SIG_IGN);
                break;
            case 'p':   //custom handler
                signal(num, custom_handler);
                //./obsluga.x p 2 przyklad dla ctrl c
                break;
            default:
                printf("Nieprawidlowy argument, wpisz d, i lub p\n");
                break;
        }
        pause();
    }
    else
    {
        printf("Nieprawdlowa ilosc argumentow\n");
        exit(EXIT_FAILURE);
    }
}
