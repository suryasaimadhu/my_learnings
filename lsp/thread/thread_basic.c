#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
void *worker_thread(void * arguments)
{
	printf("worker thread started working\n");
	printf("worker thread doing some work\n");
	printf("worker thread completed the work\n");
	return NULL;
}
int main()
{
	pthread_t thread;
	int ret;
	printf("Main thread started \n");
	ret=pthread_create(&thread,NULL,worker_thread,NULL);
	printf("main  thread :waiting for worker\n");
	pthread_join(thread,NULL);
	printf("main thread work completed\n");

	return 0;
}
