#include <stdio.h>
#include <stdlib.h> //exit
#include <sys/types.h>  //fork
#include <sys/wait.h>   //wait
#include <unistd.h>     //fork & wait
#include "procinfo.h"

//watch -n 1 "ps -HFC drzewko2.x"

int main(int argc, char* argv[])
{
    pid_t f;             //f - pid zwracany przez fork;
    int n = 3;           //liczba iteracji petli
    
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
                procinfo(argv[0]);
                break;
            }
            default: //parent process
            {
                i = n;  //wewnatrz procesow potomnych petla ma sie nie wykonywac
                break;
            }
        }
        
        //fork() returns 0 in a child process*/
    }
    
    wait(NULL);
    return 0;
}
