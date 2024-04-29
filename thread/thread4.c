#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
pthread_mutex_t lock;
int x=100;
void *test()
{
    if(x==100)
    {
        pthread_mutex_lock(&lock);
    }
    if(x==50)
    {
        pthread_mutex_unlock(&lock);
         x=x+20;
    }
   
}
void *test1()
{
    if(x==100)
    {
        pthread_mutex_lock(&lock);
    }
    if(x==70)
    {
        pthread_mutex_unlock(&lock);
        
    }
    x=x*10;
    
    
}
void *test2()
{
    if(x==100)
    {
        pthread_mutex_unlock(&lock);
         x=x-50;
    }
   
}

int main()
{
    pthread_t id[3];
    pthread_mutex_lock (&lock);
    pthread_create(&id[0],NULL,&test,0);
    pthread_create(&id[1],NULL,&test1,0);
    pthread_create(&id[2],NULL,&test2,0);
    sleep(3);
    printf("Final result: %d ",x);
}