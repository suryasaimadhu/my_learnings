#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int ret;
	char buff[50];
	//write(int fd,void *buffer,int count)
	printf("Enter the input\n");
	scanf("%49[^\n]",&buff);
	int len=strlen(buff);
	ret=write(1,buff,len);
	if(ret==-1)
	{
		printf("write failed\n");
	}
	printf("value of ret %d\n",ret);
	return 0;
}
