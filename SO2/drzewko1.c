#include <stdio.h>
#include <stdlib.h> //exit
#include <sys/types.h>  //fork
#include <sys/wait.h>   //wait
#include <unistd.h>     //fork & wait
#include "procinfo.h"

//watch -n 1 "ps -HFC drzewko1.x"

int main(int argc, char* argv[])
{
    pid_t f;            //f - pid zwracany przez fork;
    int n = 3;          //liczba iteracji petli
    int counter = n;    //licznik procesow potomnych
    
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
                i = n;      //linijka do programu, wewnatrz procesow macierzystych petla ma sie nie wykonywac
                sleep(1);
                procinfo(argv[0]);
                break;
            }
            default: //parent process
            {
                break;
            }
        }
    }
    
    for(int j = 0; j < counter; j++)
    {
        //printf("---%d---", wait(NULL));
        wait(NULL);
    }
    
    return 0;
}
