#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main ()
{
    pid_t f;
    
    f = fork();
    
    switch(f)
    {
        case -1:
            perror("Fork error");
            exit(-1);
        case 0:     //child process
            exit(0);
        default:
            sleep(100);
            exit(0);
    }
}


//watch -n 1 "ps -HFC zombie.x"

/*after the fork(), the child-process should exit(), and the parent-process should sleep() before exiting, 
giving you time to observe the output of ps (ps aux | grep zombie)*/
