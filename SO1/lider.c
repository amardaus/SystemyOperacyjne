#include <stdio.h>
#include <stdlib.h> //exit
#include <sys/types.h>  //fork
#include <sys/wait.h>   //wait
#include <unistd.h>     //fork & wait
#include "procinfo.h"

int main(int argc, char* argv[])
{
    pid_t f;         //f - pid zwracany przez fork;
    int n = 3;          //liczba iteracji petli
    int x = 0;
    pid_t leader;       //leader pid
    
    for(int i = 0; i < n; i++) //the total number of child processes is 2^n-1. the number of child processess + parent process = 2^n
    {
        f = fork();
        
        switch(f)
        {
            case -1:
            {
                perror("Fork error");
                exit(EXIT_FAILURE);
            }
            case 0: //child process
            {
                leader = getpid();
                setpgid(leader, leader);        //setpgid(pid, pgid); mozna tez wpisac 0 jako pid, wtedy oznacza to aktualny proces
                sleep(1);
                x = 0;
                procinfo(argv[0]);
                break;
            }
            default: //parent process
            {
                x++;
                break;
            }
        }
        
        //fork() return 0 in a child process*/
    }
    
    for(int j = 0; j < x; j++)
    {
        wait(NULL);
    }
    
    
    /*while(wait(NULL) > 0) {}*/
    
    return 0;
}

