#include <stdio.h>
#include "cykliczny.h"

void push(struct cykliczny* buff, char element)
{
    int next = buff->head+1;
    if(next == N)
    {
        //printf("buffer is full\n");
        next = 0;
        buff->tail++;
        
    }
    
    buff->data[next] = element;
    printf("%d: %d\n", next, buff->data[next]);
    buff->head++;
}

void pull(struct cykliczny* buff)
{
    printf("pull: %d\n", buff->data[buff->tail]);
    buff->tail++;
    if(buff->tail == N)
    {
        buff->tail = 0;
    }
}

int main()
{
    struct cykliczny buff;
    buff.size = N;
    buff.head = 0;
    buff.tail = 0;
    
    
    
    push(&buff, 'a');
    push(&buff, 'b');
    push(&buff, 'c');
    push(&buff, 'd');
    push(&buff, 'e');
    pull(&buff);
    pull(&buff);
    pull(&buff);    
    push(&buff, 'f');
    push(&buff, 'g');
    push(&buff, 'h');
    push(&buff, 'i');
    push(&buff, 'j');
    pull(&buff);
    pull(&buff);
    pull(&buff);
    
    printf("%d", buff.size);
}















/*char name[] = "whatever";
    
    int fd;
    char* filename = "magazyn.txt";
    FILE *input;
    char buff[SIZE] = "";
    char* ptr;
    
    input = fopen(filename, "r");
    fd = shmOpen(name);
    //fd = shmCreate(name, SIZE);
    
    ptr = shmMap(fd, SIZE);
    
    if(input == NULL)
    {
        perror("Error opening file\n");
        exit(-1);
    }
    
    while(fgets(buff, BUFF_SIZE, input) != NULL)
    {
        printf("[P]: %s", buff);
        strcpy(ptr, buff);
    }
    
    close(fd);*/

//producent copy
