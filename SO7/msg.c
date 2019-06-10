#include "msg.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int msgCreate(int id)
{
    int msgid;
    key_t key;
    key = ftok(".", id);
    //printf("key: %d\n", key);
    msgid = msgget(key, IPC_CREAT | 0666);
    //printf("msgid: %d\n", msgid);
    if(msgid > 0)    
    {
        printf("Utworzono kolejke komunikatow o id=%d\n", msgid);
        return msgid;
    }
    else
    {
        printf("Blad tworzenia kolejki komunikatow\n");
        perror("Error");
        exit(EXIT_FAILURE);
    }
}

void msgRm(int msgid)
{
    if(msgctl(msgid, IPC_RMID, NULL) == 0)
    {
        printf("Usunieto kolejke komunikatow o id=%d\n", msgid);
    }
    else
    {
        printf("Blad usuwania kolejki komunikatow\n");
        perror("Error");
        exit(EXIT_FAILURE);
    }
}

void msgSend(int msgid, komunikat* msg)
{
    int len = sizeof(*msg);
    int res = msgsnd(msgid, msg, len, 0);
    if(res < 0)
    {
        printf("Błąd wysyłania do kolejki komunikatów!\n");
        perror("Error");
        exit(EXIT_FAILURE);
    }
}

void msgRecv(int msgid, komunikat * msg, int mtype)
{
    int len = sizeof(*msg);
    int res = msgrcv(msgid, msg, len, mtype, 0);

    if (res < 0)
    {
        perror("Błąd odbioru z kolejki komunikatów!\n");
        exit(EXIT_FAILURE);
    }
}

void msgInfo(int msgid)
{
    struct msqid_ds buff;
    msgctl(msgid, IPC_STAT, &buff);
    printf("UID: %d\n", buff.msg_perm.uid);
    printf("GID: %dmsgSend()\n", buff.msg_perm.gid);
    printf("Time of last msgsnd: %ld\n", buff.msg_stime);
    printf("Time of last msgrcv: %ld\n", buff.msg_rtime);
    printf("Time of last change: %ld\n", buff.msg_ctime);
    printf("Current number of bytes in queue: %ld\n", buff.__msg_cbytes);
    printf("Current number of messages in queue: %ld\n", buff.msg_qnum);
    printf("Maximum number of bytes allowed in queue %ld\n", buff.msg_qbytes);
    printf("PID of last msgsnd: %d\n", buff.msg_lspid);
    printf("PID of last msgrcv: %d\n", buff.msg_lrpid);
}







