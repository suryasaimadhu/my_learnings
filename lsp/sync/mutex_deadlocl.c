#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex_A = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_B = PTHREAD_MUTEX_INITIALIZER;

void *thread_one(void *argument)
{
    (void)argument;

    pthread_mutex_lock(&mutex_A);
    printf("Thread 1 acquired mutex A\n");

    sleep(1);

    printf("Thread 1 waiting for mutex B\n");
    pthread_mutex_lock(&mutex_B);

    printf("Thread 1 acquired mutex B\n");

    pthread_mutex_unlock(&mutex_B);
    pthread_mutex_unlock(&mutex_A);

    return NULL;
}

void *thread_two(void *argument)
{
    (void)argument;

    pthread_mutex_lock(&mutex_B);
    printf("Thread 2 acquired mutex B\n");

    sleep(1);

    printf("Thread 2 waiting for mutex A\n");
    pthread_mutex_lock(&mutex_A);

    printf("Thread 2 acquired mutex A\n");

    pthread_mutex_unlock(&mutex_A);
    pthread_mutex_unlock(&mutex_B);

    return NULL;
}

int main(void)
{
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, thread_one, NULL);
    pthread_create(&thread2, NULL, thread_two, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex_A);
    pthread_mutex_destroy(&mutex_B);

    return 0;
}
