#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
int main()
{
        char *p,buf[20];
	int c=0;
        int n=shmget(12325,25,IPC_CREAT|0666);
        if(n!=1)
        {
                p=(char *)shmat(n,NULL,0);
                printf("your data is: %s ",p);
		for(int i=0;i<strlen(p);p++)
		{
			if(p[i]=='a' || p[i]=='e' || p[i]=='o' || p[i]=='i' || p[i]=='u')
			{
				c++;
			}
		}
		printf("The number of vowels is: %d",c);
        }
        return 0;
}

