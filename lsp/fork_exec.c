#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int pid;
	pid=fork();
		if(pid<0)
			printf("fork failed\n");
		else if(pid==0)
		{
			printf("child process\n");
			execl("/bin/ls","ls","-lh",NULL);
		}
		else
		{
			printf("parent process\n");
			wait(NULL);
		}

	return 0;
}
