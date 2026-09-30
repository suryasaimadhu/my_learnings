//Now combine pipe() with fork() so the parent sends data to the child
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
int main()
{
	int pipefd[2],ret,fork_pid;
	char buffer1[]="Hello world,This is parent";
	char buffer2[50];
	ret=pipe(pipefd);
	if(ret<0)
		printf("pipe failed\n");
	fork_pid=fork();
	if(fork_pid<0)
		printf("fork failed\n");
	else if(fork_pid==0)
	{
		printf("child process\n");
		close(pipefd[1]);
		ret=read(pipefd[0],buffer2,strlen(buffer1));
		if(ret<0)
			printf("child read failed\n");
		printf("child ret value is %d\n",ret);
		printf("the data in child is %s\n",buffer2);
		close(pipefd[0]);


	}
	else
	{
		printf("Parent proces\n");
		close(pipefd[0]);
				ret=write(pipefd[1],buffer1,strlen(buffer1));
				if(ret<0)
				printf("pipe write failed\n");
				printf("the ret value from parent is %d\n",ret);
				close(pipefd[1]);
				wait(NULL);
				}
				return 0;
				}


