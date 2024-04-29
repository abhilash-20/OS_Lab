#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
pthread_mutex_t lock;
int x=5;
void *test()
{
	pthread_mutex_lock(&lock);
	x=x+10;
}
void *test1()
{
	x=x*10;
	pthread_mutex_unlock(&lock);
}

int main()
{
	pthread_t id[2];
	pthread_mutex_lock(&lock);
	pthread_create(&id[0],NULL,&test,0);
	pthread_create(&id[1],NULL,&test1,0);
	sleep(1);
	printf("Final result: %d ",x);
}
