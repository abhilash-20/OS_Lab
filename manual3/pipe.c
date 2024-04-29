#include<stdio.h>
#include<unistd.h>
int main()
{
	int arr[2],arr1[2];
	int n=pipe(arr);
	int m=pipe(arr1);
	int f=fork();
	if(f==0)
	{
		int array1[10],max=0;
		read(arr[0],array1,50);
		for(int i=0;i<10;i++)
		{
			if(array1[i]>max)
			{
				max=array1;
			}
		}
		write(arr1[1],array1,50);
	}
	else
	{
		int array[10]={23,1,22,44,22,12,-9,8,34,55};
		int m[20];
		write(arr[1],array,50);
		read(arr1[0],m,50);
		printf("%d",m);
	}
	return 0;
}
