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
		int array1[20],i,j,temp;
		read(arr[0],array1,50);
		for(i=0;i<10;i++)
		{
			for(j=0;j<10-i-1;j++)
			{
				if(array1[j]>array1[j+1])
				{
					temp=array1[j];
					array1[j]=array1[j+1];
					array1[j+1]=temp;
				}
			}
		}
		write(arr1[1],array1,50);
	}
	else
	{
		int array[20]={3,2,44,1,-43,98,11,12,9,10};
		int sorted[20];
		write(arr[1],array,50);
		read(arr1[0],sorted,50);
		for(int i=0;i<10;i++)
		{
			printf("%d ",sorted[i]);
		}

	}
	return 0;
}
