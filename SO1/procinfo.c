#include "procinfo.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int procinfo(const char* name)
{
    printf("Dla procesu o nazwie %s: UID:%d\t GID:%d\t PID:%d\t PPID:%d\t PGID:%d\t\n", name, getuid(), getgid(), getpid(), getppid(), getpgid(getpid())); //%d integer, %s string
    //UID - UserID, GID - GroupID, PID - ProcessID, PPID - ParentProcessID, PGID - ProcessGroupID
    return 0;
}
