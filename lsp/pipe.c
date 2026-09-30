#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
int main()
{
	int pipefd[2],ret;
	char write1[]="Hi,Hello Madhu";
	char read1[50];
	ret=pipe(pipefd);
	if(ret<0)
		printf("pipe failed\n");
	ret=write(pipefd[1],write1,strlen(write1));
	if(ret<0)
		printf("write failed\n");
	ret=read(pipefd[0],read1,strlen(write1));
	if(ret<0)
		printf("read failed\n");
	read1[ret]='\0';
	printf("The data present in read buffer is %s \n",read1);
	close(pipefd[0]);
	close(pipefd[1]);
	return 0;
}
		

