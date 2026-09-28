#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int ret,fd;
	fd=open("/home/amd/fcntl.txt",O_CREAT|O_RDWR|O_TRUNC,0666);
	if(fd<0)
		printf("file open failed\n");
	char str1[]="first line \n";

	write(fd,str1,sizeof(str1));
	int flags;
	flags=fcntl(fd,F_GETFL);
	printf("Flags are %d\n",flags);
	flags=fcntl(fd,F_SETFL,flags|O_APPEND);
	lseek(fd,0,SEEK_SET);
	char str2[]="seconf line \n";
	write(fd,str2,sizeof(str2));
	return 0;
}

