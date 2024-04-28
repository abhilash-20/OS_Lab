#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>
int main()
{
    char *p;
    int *q;
    int n=shmget(12345,25,IPC_CREAT|0666);
    if(n!=1)
    {
        p=(char *)shmat(n,NULL,0);
        printf("Data received: %s",p);
        int c=0;
        for(int i=0;i<strlen(p);i++)
        {
            char ch=p[i];
            if(ch=='a' || ch=='i'|| ch=='e'|| ch=='o'||ch=='u')
            {
                c++;
            }
        }
    int m=shmget(12321,25,IPC_CREAT|0666);
    if(m!=1)
    {
        q=(int*)shmat(m,NULL,0);
        *q=c;
    }

        //printf("\n%d",c);
    }
    return 0;
}