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
	msgid_snd=msgget(key_snd,IPC_CREAT|0666); // msgget creates a message queue and returns an indetifier.
	msgid_rcv=msgget(key_rcv,IPC_CREAT|0666);
	buf.mtype=1;
	printf("Enter data: ");
	scanf("%s",buf.mtext);
	msgsnd(msgid_snd,&buf,sizeof(buf),0);
	/*
	 * msgsnd(indentifier,address of the buffer/message struct containing the data you want to send,
	 */
	printf("Data sent: %s",buf.mtext);
	msgrcv(msgid_rcv,&buf1,sizeof(buf1),1,0);
	printf("\nnumber of vowels :%s ",buf1.mtext);
	return 0;
}
