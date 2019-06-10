#include "sem.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    semid s;
    char* name = "/mysem";
    char c = 'x';
    
    if(argc == 2)
    {
        c = *argv[1];
    }
    else
    {
        printf("Niepoprawna liczba argumentow. Podaj litere i, r, p, v, z lub q.\n");
        exit(-1);
    }
    
    switch(c)
    {
        case 'i':
            s = semCreate(name, 3);
            semInfo(s);
            break;
        case 'r':
            semRemove(name);
            break;
        case 'p':
            s = semOpen(name);
            semP(s);
            semInfo(s);
            break;
        case 'v':
            s = semOpen(name);
            semV(s);
            semInfo(s);
            break;
        case 'q':
            s = semOpen(name);
            semInfo(s);
            break;
        default:
            printf("Nieprawidlowy argument. Podaj litere i, r, p, v, z lub q.\n");
            break;
            
    }
}
