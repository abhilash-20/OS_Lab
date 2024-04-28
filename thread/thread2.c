#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
pthread_mutex_t lock;
void *test()
{
	pthread_mutex_lock(&lock);
	printf("hello\n");
}

void *test1()
{
	pthread_mutex_unlock(&lock);
	printf("world\n");
}
int main()
{
	pthread_t id[2];
	pthread_mutex_lock (&lock);
	pthread_create(&id[0],NULL,&test,0);
	pthread_create(&id[1],NULL,&test1,0);
	sleep(1);
	return 0;
}

