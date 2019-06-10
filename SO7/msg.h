#define SIZE 128
#include <sys/types.h>

typedef struct komunikat
{
    long mtype;
    pid_t sender;
    char mtext[SIZE];
} komunikat;


int msgCreate(int id);
void msgRm(int msgid);
void msgSend(int msgid, komunikat* msg);
void msgRecv(int msgid, komunikat* msg, int mtype);
void msgInfo(int msgid);
