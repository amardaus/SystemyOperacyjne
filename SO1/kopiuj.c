#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        perror("Wrong number of arguments. The correct syntax to run the program: ./kopiuj.x [input file] [output file name]\n");
        return EXIT_FAILURE;
        //"Success" is printed after the message, because errno value is 0
    }
    
    int input_file = open(argv[1], O_RDONLY, 0666);
    int output_file = open(argv[2], O_WRONLY | O_CREAT, 0666);
    
    if(input_file < 0)
    {
        perror("Error opening input file %s" + input_file);
        return EXIT_FAILURE;
    }
    
    if(output_file < 0)
    {
        perror("Error opening or creating output file %s" + output_file);
        return EXIT_FAILURE;
    }
    
    char* buffer;
    buffer = (char*)malloc(BUFFER_SIZE);
    if(buffer == NULL)
    {
        perror("Error allocating memory for the buffer");
        return EXIT_FAILURE;
    }
    
    int bytes_read, write_bytes;
    do
    {
        bytes_read = (int)read(input_file, buffer, BUFFER_SIZE);
        if(bytes_read > 0)
        {
            write_bytes = (int)write(output_file, buffer, (ssize_t)bytes_read);
            //ssize_t - signed size_t, size in bytes, or -1 when error (range: [-1, SSIZE_MAX])
            if(write_bytes < 0)
            {
                perror("Error writing to output file");
            }
        }
    }
    while(bytes_read >= BUFFER_SIZE);
    
    close(input_file);
    close(output_file);
    free(buffer);
    
}
