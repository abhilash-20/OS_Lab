#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
struct msgbuf
{
	long mtype;
	char mtext[10];
} buf,buf1;

int main()
{
    int key_snd=20;
    int key_rcv=21;
    int msgid_snd,msgid_rcv;
    msgid_snd=msgget(key_snd,IPC_CREAT|0666);
    msgid_rcv=msgget(key_rcv,IPC_CREAT|0666);
    buf.mtype=1;
    
    return 0;
}