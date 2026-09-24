#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int fd,ret;
	char buff[50];
	printf("enter the data to buff\n");
	scanf("%49[^\n]",buff);
	//open a file
       //open(const char * pathname,int flags,int mode)	
	fd=open("/home/amd/xyz.txt",O_CREAT|O_RDWR|O_TRUNC,0666);
	if(fd<0)
		printf("file open failed \n");
	//write into  file
	//write(int fd,void *buff,int count)
	ret=write(fd,buff,strlen(buff));
	lseek(fd, 0, SEEK_SET);
	//read(int fd,void * buff,int size)
	ret=read(fd,buff,strlen(buff));
	printf("no of bytes is %d\n",ret);
	return 0;
}
