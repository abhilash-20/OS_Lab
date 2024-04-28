#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
struct msgbuf
{
    long mtype;
    char mtext[10];
}buf,buf1;

int main()
{
    int key_rcv=20,key_snd=21;
    int msgid_rcv,msgid_snd;
    msgid_rcv=msgget(key_rcv,IPC_CREAT|0666);
    msgrcv(msgid_rcv,&buf,sizeof(buf),1,0);
    printf("Data Received: %s",buf.mtext);

    int c=0;
    msgid_snd=msgget(key_snd,IPC_CREAT|0666);
    for(int i=0;i<strlen(buf.mtext);i++)
    {
        c++;
    }
    char temp[10];
    sprintf(temp,"%d",c);
    strcpy(buf1.mtext,temp);
    buf1.mtype=1;
    msgsnd(msgid_snd,&buf1,sizeof(buf1),0);
    printf("\nData sent: %s",buf1.mtext);
    return 0;
}
