#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define SIZE 128

int main(int argc, char* argv[])
{
    int fd;
    char *file_name = "magazyn.txt";
    char *pipe_name = "potok";
    FILE *input;
    char buff[SIZE] = "";
    
    input = fopen(file_name, "r");
    fd = open(pipe_name, O_WRONLY);
    
    if(input == NULL)
    {
        perror("Error opening file\n");
        exit(-1);
    }
    
    while(fgets(buff, SIZE, input) != NULL)
    {
        printf("[P]: %s", buff);
        write(fd, buff, SIZE);
    }
    
    close(fd);
    fclose(input);
    
}
