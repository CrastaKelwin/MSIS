#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
void *Thread_1(void *);
int main()
{
    int count = 0;

    pthread_t t1;
    printf("Main: Process id is %d\n", getpid());
    printf("Main: Main thread id is %lu\n", pthread_self());
    printf("\nEnter the Max limit for Summation:\n");

    scanf("%d", &count);
    pthread_create(&t1, NULL, Thread_1, &count);
    pthread_join(t1, NULL);

    printf("\nMain thread is exiting...\n");
}
void *Thread_1(void *in)
{
    int max_lim = *((int *)in);
    int sum = 0, i, num;
    printf("Thread1: Process id is %d\n", getpid());
    printf("Thread1: Thread id is %lu\n", pthread_self());
    for (i = 0; i < max_lim; i++)
    {
        sum += num;
    }
    printf("\nThread1: The sum of first %d numbers %d\n",max_lim, sum);
    pthread_exit(0);
}