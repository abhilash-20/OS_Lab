#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>
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
    return 0;
}
