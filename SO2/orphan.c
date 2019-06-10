#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    pid_t f;
    f = fork();
    
    switch(f)
    {
        case -1:
            perror("Fork error");
            break;
        case 0:
            sleep(100);
            exit(0);
        default:
            exit(0);
            break;
    }
}

/*
 * 
 * An orphan process is a process that is still executing, but whose parent has died. They do not become zombie processes; instead, they are adopted by init (process ID 1), which waits on its children.
 */
