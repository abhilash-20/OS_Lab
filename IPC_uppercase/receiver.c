#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
#include<ctype.h>
struct msgbuf
{
    long mtype;
    char mtext[100];
}buf,buf1;

int main()
{
    int key_rcv=40,key_snd=41;
    int msgid_rcv,msgid_snd;
    msgid_rcv=msgget(key_rcv,IPC_CREAT|0666);
    msgrcv(msgid_rcv,&buf,sizeof(buf),1,0);
    printf("Data received: %s ",buf.mtext);
    char temp[100];
    strcpy(temp,buf.mtext);
    int i=0;
    while(temp[i]!='\0')
    {
        if(i==0 || temp[i-1]==' ')
        {
            temp[i]=toupper(temp[i]);
        }
        i++;
    }
    buf1.mtype=1;
    strcpy(buf1.mtext,temp);
    msgid_snd=msgget(key_snd,IPC_CREAT|0666);
    msgsnd(msgid_snd,&buf1,sizeof(buf),0);
    printf("\nData sent: %s ",buf1.mtext);
}