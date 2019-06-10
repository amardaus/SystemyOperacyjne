#include <stdio.h>
#include "cykliczny.h"
#include "sem.h"

char* name = "/mysem";

void push(struct cykliczny* buff, char element)
{
    int next = buff->head+1;
    if(next == N)
    {
        printf("End of buffer\n");
        //semid sem = semOpen(name);
        //semP(sem);
        next = 0;
    }
    
    if(next == buff->tail)
    {
        printf("Buffer is full!\n");
    }
    
    buff->data[next] = element;
    printf("push[%d]: %c\n", next, buff->data[next]);
    buff->head = next;
}

void pull(struct cykliczny* buff)
{
    int next = buff->tail+1;
    if(next == N)
    {
        //semid sem = semOpen(name);
        //semV(sem);
        next = 0;
    }
    printf("\tpull[%d]: %c\n", next, buff->data[next]);
    buff->tail = next;
}

int main()
{
    struct cykliczny buff;
    buff.size = N;
    buff.head = 0;
    buff.tail = 0;
    
    
    semCreate(name, 1);
    //semOpen(name);
    
    
    
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
    
    semRemove(name);
}
