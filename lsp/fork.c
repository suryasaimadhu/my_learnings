#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int pid;
	pid=fork();
	if(pid<0)
		printf("fork failed\n");
	else if (pid==0)
		printf("child process and pid is %d ppid is %d\n",getpid(),getppid());
	else
	{
		int status;
		int terminated_pid;
		printf("parent process pid is %d and ppid is %d\n",getpid(),getppid());
		terminated_pid=wait(&status);
		printf("terminated pid is %d\n",terminated_pid);
		if(WIFEXITED(status))
		{
			printf("child exited normally\n");
			printf("child exit status is %d\n",WEXITSTATUS(status));
		}
		printf("Child has terminated\n");
	}
	return 0;
}
