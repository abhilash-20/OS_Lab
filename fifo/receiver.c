#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	const char *ch="/tmp/myfifo01";
	int n,m;
	char buf[10];
	m=open(ch,O_RDONLY);
	if(m!=-1)
	{
		read(m,buf,10);
	}
	printf("\n data=%s",buf);
	return 0;
}
