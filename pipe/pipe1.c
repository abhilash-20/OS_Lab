#include<stdio.h>
#include<unistd.h>
#include<string.h>
int a=5,b=7;
int main()
{
        int arr[2];
        int p=pipe(arr);
        int f=fork();
        int id1,id2;
        if(f==0)
        {
                id1=getpid();
                printf("child's id: %d\n",id1);
                id2=getppid();
                printf("Child's parent id: %d\n",id2);
                b=a+b;
                char sum[20];
                sprintf(sum,"%d",b);
                write(arr[1],sum,strlen(sum));
        }
        else
        {
                id1=getpid();
                printf("Process id of Parent: %d",id1);
                printf("\n");
                char s[20];
                read(arr[0],s,20);
                printf("sum is: %s\n",s);

        }
        return 0;

}

