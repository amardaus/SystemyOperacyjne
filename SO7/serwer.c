#include "msg.h"
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>

int main()
{
    komunikat k;
    int type = 1;
    int msgid = msgCreate(98);
    
    while(1)
    {
        msgRecv(msgid, &k, type);
        printf("Serwer komunikat od procesu %d\n", k.sender);
            
        char *c = k.mtext;
        while(*c)
        {
            *c = toupper(*c);
            c++;
        }
                
        //printf("Odpowiedz z serwera: %s", k.mtext);
        
        k.mtype = k.sender;
        k.sender = getpid();
        printf("Serwer wysyla odpowiedz do procesu %ld\n", k.mtype);
        msgSend(msgid, &k);
    }
}
