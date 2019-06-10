#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define SIZE 128

int main(int argc, char* argv[])
{
    int fd;
    char* file_name = "schowek.txt";
    char* pipe_name = "potok";
    FILE *output;
    char buff[SIZE] = "";
    
    fd = open(pipe_name, O_RDONLY);
    output = fopen(file_name, "w");
    
    if(output == NULL)
    {
        perror("Error opening input file\n");
        exit(-1);
    }
    
    while(read(fd, buff, SIZE) > 0)
    {
        printf("[K]: %s", buff);
        fputs(buff, output);
    }
    
    close(fd);
    fclose(output);
    
}
