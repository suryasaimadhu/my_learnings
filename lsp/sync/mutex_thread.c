#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
int value=0;
pthread_mutex_t mutex;
void *increment(void * arg)
{
	int thread_number=*(int *)arg;
	for(int i=0;i<5;i++)
	{
		pthread_mutex_lock(&mutex);
		value++;
		printf("the value in thread %d ,value is %d\n",thread_number,value);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}


int main()
{
	pthread_t thread1,thread2;
	int thread_number1=1;
	int thread_number2=2;
	pthread_create(&thread1,NULL,increment,&thread_number1);
	pthread_create(&thread2,NULL,increment,&thread_number2);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("The final value is %d\n",value);
	pthread_mutex_destroy(&mutex);
	return 0;
}

