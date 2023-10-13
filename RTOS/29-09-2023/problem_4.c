#define RAND_MAX 100
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <stdlib.h>

void *Thread_1(void *);
void *Thread_2(void *);

int arr[10];
int main()
{
    int count;

    pthread_t t1, t2;
    printf("This Code is not working as Intended...!!");
    printf("Main: Process id is %d\n", getpid());
    printf("Main: Main thread id is %lu\n", pthread_self());

    count = sizeof(arr) / sizeof(arr[0]);

    printf("[");
    for (int i = 0; i < count; i++)
    {
        arr[i] = (rand() % (101)) + i;
        printf("%d ", arr[i]);
    }
    printf("]\n");
    pthread_create(&t1, NULL, Thread_1, &count);
    pthread_create(&t2, NULL, Thread_2, &count);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\nMain thread is exiting...\n");
}
void *Thread_1(void *in)
{
    int max_lim = *((int *)in);
    int i;
    int sum = 0;
    printf("Thread1: Process id is %d\n", getpid());
    printf("Thread1: Thread id is %lu\n", pthread_self());

    printf("Thread 1 computing sum\n");
    for (i = 0; i < max_lim; i++)
    {
        sum += arr[i];
    }
    printf("Thread 1 computed sum = %d\n", sum);
    pthread_exit(NULL);
}

void *Thread_2(void *in)
{
    int max_lim = *((int *)in);
    int i;
    printf("Thread2: Process id is %d\n", getpid());
    printf("Thread2: Thread id is %lu\n", pthread_self());
    printf("Thread 1 printing odd\n");

    printf("[");
    for (int i = 0; i < max_lim; i++)
    {
        if (arr[i] & 0x1)
            printf("%d ", arr[i]);
    }
    printf("]\n");
    pthread_exit(NULL);
}
