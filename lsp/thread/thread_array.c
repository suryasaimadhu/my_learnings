// Sum an array using three threads
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
struct task
{
	int *numbers;
	int start;
	int end;
	int result;
	int thread_number;
};
void *calculate_sum(void *arguments)
{
	struct task *data=arguments;
	int result=0;
		for(int i=data->start;i<=data->end;i++)
			data->result+=data->numbers[i];
	return NULL;
}

int main()
{
	int numbers[]={1,2,3,4,5,6,7,8,9,10,11,12};
	pthread_t threads[3];
	struct task tasks[3];
	for(int i=0;i<3;i++)
	{
		tasks[i].numbers=numbers;
		tasks[i].start=i*4;
		tasks[i].end=tasks[i].start+3;
		tasks[i].result=0;
		tasks[i].thread_number=i+1;
	}
	for(int i=0;i<3;i++)
	{
		pthread_create(&threads[i],NULL,calculate_sum,&tasks[i]);
	}
	for(int i=0;i<3;i++)
	{
		pthread_join(threads[i],NULL);
	}
	int final_result=0;
	for(int i=0;i<3;i++)
	{
		final_result+=tasks[i].result;
	}
	printf("The final result was %d\n",final_result);
	return 0;
}



