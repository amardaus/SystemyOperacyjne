#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h> //EXIT_FAILURE
#include <ctype.h>  //is_digit
#include <sys/wait.h>
#include <errno.h>

//volatile int running = 1; //to byloby lepsze niz exit(0);

void custom_handler(int sig)
{
    //running = 0;
    printf("Sygnal %d przechwycony!\n", sig);
    exit(0);
}

int main(int argc, char* argv[])
{
    int sig_num;
    
    if(argc != 2)
    {
        perror("Niewlasciwa ilosc argumentow");
        exit(EXIT_FAILURE);
    }
    if(!isdigit(*argv[1]))
    {
        perror("Argument powinien byc liczba");
        exit(EXIT_FAILURE);
    }
    sig_num = atoi(argv[1]);
    
    if(sig_num < 1 || sig_num > 64)
    {
        perror("Argument powinien byc liczba z zakresu 1-64");
        exit(EXIT_FAILURE);
    }
    
    pid_t pid, grouppid, parent_pid;
    pid = getpid();
    grouppid = getpgid(pid);
    parent_pid = getpid();
    int n = 3;
    printf("Parent process: %d %d\n", getpid(), getpgid(getpid()));
    
    for(int i = 0; i < n; i++)
    {
        pid = fork();
        if(pid == 0)
        {
            i = n;
        }
    }
    
    sleep(1);
    
    if(getpid() != parent_pid)
    {
        printf("Child process: %d %d\n", getpid(), getpgid(getpid()));
        signal(sig_num, custom_handler);
    }
    else
    {
        signal(sig_num, SIG_IGN);
    }
    
    
    sleep(2);
    
    if(getpid() == parent_pid)
    {
        kill(-grouppid, sig_num);
        printf("Wewnatrz procesu macierzystego (pid=%d)\n", parent_pid);
    }
    
    sleep(2);
    for(int i = 0; i < n; i++)
    {
        wait(NULL);
    }
    
    printf ("Koncze %d\n", getpid());
}
