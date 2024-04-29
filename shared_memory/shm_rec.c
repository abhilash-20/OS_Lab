#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
int main()
{
        char *p;
        int n=shmget(12325,25,IPC_CREAT|0666);
        if(n!=1)
        {
                p=(char *)shmat(n,NULL,0);
                printf("your data is: %s ",p);
        }
        return 0;
}


