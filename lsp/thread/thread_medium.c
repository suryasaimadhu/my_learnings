#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
struct range
{
	int start;
	int end;
	int result;
};
void *worker(void *argument)
{
	printf("worker thread\n");
	int i,j;
	struct range *data=argument;
	for(int i=data->start;i<=data->end;i++)
	{
		data->result+=i;
	}
	return NULL;
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	struct range range1;
	struct range range2;
	range1.start=1;
	range1.end=5;
	range1.result=0;
	range2.start=6;
	range2.end=10;
	range2.result=0;
	pthread_create(&thread1,NULL,worker,&range1);
	pthread_create(&thread2,NULL,worker,&range2);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("the sum result is %d\n",(range1.result+range2.result));

	return 0;
}
