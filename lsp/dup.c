#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int o_fd,d_fd,ret;
	char buff[100];
	o_fd=open("/home/amd/c.txt",O_CREAT|O_WRONLY|O_TRUNC,0666);
	if(o_fd<0)
		printf("file open failed\n");
	d_fd=dup(o_fd);
	write(o_fd,"Linux",5);
	lseek(o_fd,5,SEEK_SET);
	write(d_fd,"system programming",18);
	close(o_fd);
	close(d_fd);
	return 0;
}
