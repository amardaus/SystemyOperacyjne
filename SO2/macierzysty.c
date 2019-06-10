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
    
    for(int i = 0; i < n; i++)
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
                sleep(1);
                char *arr[] = {"potomny.x", NULL};
                execv("./potomny.x", arr);
                break;
            }
            default:
            {   
                //printf("%d", i);
                wait(NULL);
                break;
            }
        }
    }    
    return 0;
}
