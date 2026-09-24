#include<stdio.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	int ret;
	char buff[50];
	//read(int fd,void *buff,int count)
	ret=read(0,buff,10);
	if(ret<0)
	{
		printf("Error is %d",errno);
		return -1;
	}
	if(ret==0)
		printf("End of file\n");
	if(buff[ret-1]=='\n')
	{
		ret--;
	}
	buff[ret]='\0';
	printf("ret value is %d\n",ret);
	return 0;
}
