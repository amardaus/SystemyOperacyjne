#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    //printf("pierwszy komunikat");   //bez znaku nowej lini sie to nie wypisze - dlaczego?
    printf("pierwszy komunikat\n");
    execl("./potomny.x", "potomny.x", NULL);
    printf("drugi komunikat\n");
}
