#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
void *Thread_1(void *);
void *Thread_2(void *);
int main()
{
    int count_1 = 0, count_2;

    pthread_t t1, t2;
    printf("Main: Process id is %d\n", getpid());
    printf("Main: Main thread id is %lu\n", pthread_self());
    printf("\nEnter the n limit:\n");
    scanf("%d %d", &count_1, &count_2);

    pthread_create(&t1, NULL, Thread_1, &count_1);
    pthread_create(&t2, NULL, Thread_2, &count_2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\nMain thread is exiting...\n");
}
void *Thread_1(void *in)
{
    int max_lim = *((int *)in);
    int i;
    printf("Thread1: Process id is %d\n", getpid());
    printf("Thread1: Thread id is %lu\n", pthread_self());

    for (i = 0; i < max_lim; i++)
    {
        printf("%d Hello, thread1 here!\n", i);
    }
    pthread_exit(NULL);
}

void *Thread_2(void *in)
{
    int max_lim = *((int *)in);
    int i;
    printf("Thread2: Process id is %d\n", getpid());
    printf("Thread2: Thread id is %lu\n", pthread_self());
    for (i = 0; i < max_lim; i++)
    {
        printf("%d Hello, thread2 here!\n", i);
    }
    pthread_exit(NULL);
}
