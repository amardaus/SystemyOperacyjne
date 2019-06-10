#include "shmem.h"

int main()
{
    shmCreate("cokolwiek", 2);
    shmOpen("cokolwiek");
    shmRm("cokolwiek");
    return 0;
}
