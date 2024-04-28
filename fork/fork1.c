#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int j=fork();
	int p,q;
	if(j==0)
	{
		//child
		p=getppid(); //parent process id. 
		printf("Process ID of p: %d\n",p);
		q=getpid();
		printf("Process ID of q: %d",q);
	        printf("\n");	
	}
	else // at first the id of the child is sent to the fork and therefore else part is executed first ie the parent process
	{
		p=getpid();
		printf("ID: %d\n",p);
		printf("\n");
	}
	return 0;
}

