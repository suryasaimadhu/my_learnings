/*input: Linux system programming
output: Linux kernel programming
Write a C program that performs these operations:

Create/open a file named practice.txt.
Write this text into it:
Linux system programming
Use lseek() to move to the beginning of the word system.
Replace system with kernel.
Use lseek() again to return to the beginning.
Read the complete file into a buffer.
Print the final contents. */
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int fd,ret;
	char buff[50];
	fd=open("/home/amd/practice.txt",O_CREAT|O_RDWR|O_TRUNC,0666);
	if(fd<0)
	{
		printf("fd failed to open");
	}
	printf("Enter the text into file \n");
	scanf("%49[^\n]",buff);
	ret=write(fd,buff,strlen(buff));
	lseek(fd,6,SEEK_SET);
	ret=read(fd,buff,strlen(buff));
	printf("ret value is %d\n",ret);
	printf("the buff is %s\n",buff);
	char buff1[]="kernel";
	lseek(fd,6,SEEK_SET);
	ret=write(fd,buff1,strlen(buff1));
	printf("The ret value after replace is %d\n",ret);
	lseek(fd,0,SEEK_SET);
	ret=read(fd,buff,strlen(buff));
	printf("The ret value after replace2 is %d\n",ret);
	printf("final : %s\n",buff);



	return 0;
}
