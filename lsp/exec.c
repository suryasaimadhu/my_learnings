#include<stdio.h>
#include<unistd.h>
int main()
{
	int ret;
	printf("Before exec\n");
	fflush(stdout);
	printf("After exec\n");
	ret=execl("/bin/ls","ls","-l",NULL);
	if(ret<1)
		printf("error\n");
	return 0;
}

