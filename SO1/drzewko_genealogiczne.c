#include <stdio.h>
#include <stdlib.h> //exit
#include <sys/types.h>  //fork
#include <sys/wait.h>   //wait
#include <unistd.h>     //fork & wait
#include "procinfo.h"
#include <string.h>

int main(int argc, char* argv[])
{
    pid_t f;         //f - pid zwracany przez fork;
    int n = 3;          //liczba iteracji petli
    
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
                strcpy(argv[0], "child");
                sleep(1);
                procinfo(argv[0]);
                break;
            }
            default: //parent process
            {
                strcpy(argv[0], "parent");
                sleep(2);           //dlaczego tu dwa razy dluzej niz dla child? (inaczej procinfo wypisuje niepokolei)
                break;
            }
        }
        
        //fork() return 0 in a child process*/
    }
    sleep(10);
    system("ps u");
    
    while(wait(NULL) > 0)
    {
        //czekanie na wszysytkie procesy potomne
    }
    
    return 0;
}
