#include "msg.h"
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>

int main()
{
    while(1)
    {
        char wiadomosc[SIZE];
        printf("Podaj wiadomosc: \n");
        fgets(wiadomosc, SIZE, stdin);
        //printf("Wiadomosc ktora przesylasz: %s\n", wiadomosc);
        int type = 1;
        int pid = getpid();
        
        komunikat k;
        k.mtype = type;
        k.sender = pid;
        strcpy(k.mtext, wiadomosc);
        
        int msgid = msgCreate(98);
        msgSend(msgid, &k);
        
        msgRecv(msgid, &k, pid);
        //printf("Klient otrzymal odpowiedz od procesu %d, recv= %d\n", k.sender, k.receiver);
        printf("Odpowiedz od serwera: %s\n", k.mtext);
    }
}
