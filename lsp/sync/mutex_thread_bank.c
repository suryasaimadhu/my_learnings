#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
int balance=1000;
pthread_mutex_t mutex;
void *withdraw(void *arg)
{
	int withdraw_amount=*(int *)arg;
	for(int i=0;i<5000;i++)
	{
		pthread_mutex_lock(&mutex);
		balance-=withdraw_amount;
		pthread_mutex_unlock(&mutex);
	}
}
void *deposit(void *arg)
{
	int deposit_amount=*(int *)arg;
	for(int i=0;i<5000;i++)
	{
		pthread_mutex_lock(&mutex);
		balance+=deposit_amount;
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_mutex_init(&mutex,NULL);
	pthread_t thread1,thread2;
	int wdwl=1;
	int dep=1;
	pthread_create(&thread1,NULL,withdraw,&wdwl);
	pthread_create(&thread2,NULL,deposit,&dep);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("the final amount will be %d\n",balance);
	pthread_mutex_destroy(&mutex);
	return 0;
}
