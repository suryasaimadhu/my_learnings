#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int source_fd,dest_fd,ret;
	char buff[1000];
	source_fd=open(argv[1],O_RDONLY);
	if(source_fd<0)
		printf("source file fd failed \n");
	dest_fd=open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,0666);
	if(dest_fd<0)
		printf("dest fd failed\n");
	ret=read(source_fd,buff,sizeof(buff));
	while(ret>0)
	{
		write(dest_fd,buff,ret);
		ret=read(source_fd,buff,sizeof(buff));
	}
	close(source_fd);
	close(dest_fd);
	return 0;
}

