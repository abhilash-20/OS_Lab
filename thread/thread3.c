#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
pthread_mutex_t lock;
int x=50;
void *add()
{
	x=x+10;
}
void *sub()
{
	x=x-5;
}
void *mul()
{
	x=x*10;
}
void *div()
{
	x=x/25;
}

int main()
{
	pthread_t id[5];
//	pthread_mutex_lock(&lock);
	pthread_create(&id[0],NULL,&add,0);
	 pthread_create(&id[1],NULL,&sub,0);
         pthread_create(&id[2],NULL,&mul,0);
        pthread_create(&id[3],NULL,&div,0);
	sleep(1);
	printf("value of x=%d",x);
	return 0;
}
