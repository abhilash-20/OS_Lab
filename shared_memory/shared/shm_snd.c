#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>
#include<unistd.h>
int main()
{
    char *p,buf[20];
    int n=shmget(12345,25,IPC_CREAT|0666);
    if(n!=1)
    {
        p=(char*)shmat(n,NULL,0);
        printf("enter your data: ");
        scanf("%[^\n]s",buf);
        strcpy(p,buf);
        printf("data sent is: %s",p);
    }
    sleep(5);
    int m=shmget(12321,25,IPC_CREAT|0666);
    int *q;
    if(m!=1)
    {
        q=(int*)shmat(m,NULL,0);
        printf("\nNumber of vowels: %d",*q);
    }
    return 0;
}
