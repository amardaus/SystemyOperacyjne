#include <fcntl.h> 
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#define SIZE 64

void parent(int file_descriptor[2])  //konsument
{
    int r;
    time_t t;
    srand((unsigned) time(&t));
    r = rand() % 1000000;
    usleep(r);
    
    char buff[SIZE];
    close(file_descriptor[1]);
    FILE *file_w;
    file_w = fopen("schowek.txt", "w");
    
    while(read(file_descriptor[0], buff, SIZE) != '\0')
    {
        /* read pipe */
        printf("[K]: %s", buff);
        fputs(buff, file_w);
    }
}

void child(int file_descriptor[2])   //producent
{
    int r;
    time_t t;
    srand((unsigned) time(&t));
    r = rand() % 1000000;
    usleep(r);
     
    char buff[SIZE];
    close(file_descriptor[0]);
    FILE *file_r;
    file_r = fopen("magazyn.txt", "r");
    
    while(fgets(buff, SIZE, file_r))
    {
        printf("[P]: %s", buff);
        write(file_descriptor[1], buff, SIZE);
    }
}

int main()
{
    pid_t pid;
    int fd[2];  //pipe
    //fd[0] - read end
    //fd[1] - write end
        
    if(pipe(fd) < 0)
    {
        perror("Pipe error");
        exit(1);
    }
    
    pid = fork();
    
    if(pid == -1)
    {
        perror("Fork error");
        exit(1);
    }
    
    if(pid == 0)
    {
        child(fd);
    }
    
    else
    {
        parent(fd);
        wait(NULL);
    }
    
    //diff -s magazyn.txt schowek.txt
    
    return 0;
}
