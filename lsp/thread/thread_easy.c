#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
void *worker(int *limit)
	{
		for(int i=0;i<*limit;i++)
			{
				printf("worker :%d\n",i);
			}
	}
int main()
{
	int ret;
	int limit=5;
	pthread_t thread;
	printf("main thread started\n");
	pthread_create(&thread,NULL,&worker,&limit);
	pthread_join(thread,NULL);
	printf("main thread completd\n");
	return 0;
}
	
