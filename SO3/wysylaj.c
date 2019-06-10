#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    pid_t pid;
    pid = fork();
    int sig = atoi(argv[2]);
    
    if(argc != 3)
    {
        printf("Nieprawdlowa ilosc argumentow\n");
        exit(EXIT_FAILURE);
    }
    
    switch(pid)
    {
        case -1:    //error
            perror("Fork error");
            exit(-1);
            
        case 0:     //child process
            execl("./obsluga.x", "./obsluga.x", argv[1], argv[2], NULL);
            break;
        default:    //parent process
            /*[ESRCH] - no process or process group can be found corresponding to that specified by pid.*/
            sleep(1);
            kill(pid, 0);
            if(errno != ESRCH)
            {
                kill(pid, sig);
                printf("Wyslano sygnał do procesu (pid=%d)\n", pid);
            }
            break;
    }
    
    wait(NULL);
}
