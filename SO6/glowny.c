#include <sys/types.h>
#include <unistd.h>
#include "producent.h"
#include "konsument.h"
#include "shmem.h"
#include "sem.h"
#include "cykliczny.h"

int main()
{    
    pid_t pid;
    
    //cykliczny buff;
    //buff.add();
    
    
    //semOpen("test");
    pid = fork();
    if(pid == 0)
    {
        execl("./konsument.x", "./konsument.x", NULL);
    }
    else
    {
        
        execl("./producent.x", "./producent.x", NULL);
    }
}
