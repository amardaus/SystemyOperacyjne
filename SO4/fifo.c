#include <fcntl.h> 
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char *myfifo = "potok3";
    
    pid_t pid1, pid2;
    
    mkfifo(myfifo, 0666); //rwrwrw    
    pid1 = fork();
    
    if(pid1 < 0)
    {
        perror("Fork error");
        exit(0);
    }
    else if(pid1 == 0)
    {
        execl("./producent.x", "producent.x", myfifo, NULL);
        printf("prod\n");
    }
    
    pid2 = fork();
    if(pid2 < 0)
    {
        perror("Fork error");
        exit(0);
    }
    else if(pid2 == 0)
    {
        execl("./konsument.x", "konsument.x", myfifo, NULL);
    }
    
    wait(NULL);
    wait(NULL);
    sleep(2);
    unlink(myfifo); //unlink removes a link to a file
}
