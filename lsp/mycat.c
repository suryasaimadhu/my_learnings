///* WAP implement your own version of cat program */
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int ret,fd;
	char buff[100];
	fd=open(argv[1],O_RDONLY,0666);
	if(fd<0)
		printf("File open failed\n");
	printf("file fd is %d\n",fd);
	ret=read(fd,buff,10);
	while(0!=ret)
	{
		write(1,buff,ret);
		ret=read(fd,buff,10);
	}
	close(fd);
	return 0;
}
