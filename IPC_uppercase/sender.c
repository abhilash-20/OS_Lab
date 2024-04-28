#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
struct msgbuf
{
    long mtype;
    char mtext[100];
}buf,buf1;

int main()
{
    int key_snd=40;
    int key_rcv=41;
    int msgid_snd,msgid_rcv;
    msgid_snd=msgget(key_snd,IPC_CREAT|0666);
    msgid_rcv=msgget(key_rcv,IPC_CREAT|0666);
    buf.mtype=1;
    printf("Enter the string: ");
    //scanf("%s",buf.mtext);
    gets(buf.mtext);
    msgsnd(msgid_snd,&buf,sizeof(buf),0);
    printf("Data sent: %s ",buf.mtext);
    msgrcv(msgid_rcv,&buf1,sizeof(buf1),1,0);
    printf("\nData received: %s ",buf1.mtext);
    return 0;
}
