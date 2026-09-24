#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char buff[50];
	int fd,ret;
	//open(const char *pathname,int flags,mode_t mode)
	fd=open("/home/amd/abc.txt",O_CREAT|O_WRONLY|O_TRUNC,0666);
	
	printf("fd is %d\n",fd);
	if(fd<0)
	{
		printf("creation of fd failed\n");
	}
	return 0;
}
