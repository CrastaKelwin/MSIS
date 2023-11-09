#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
void *Thread_1(void *);
void *Thread_2(void *);
void *Thread_3(void *);
int main()
{
    int count = 0;

    pthread_t t1, t2, t3;
    printf("Main: Process id is %d\n", getpid());
    printf("Main: Main thread id is %lu\n", pthread_self());
    printf("\nEnter the n limit:\n");
    scanf("%d", &count);

    pthread_create(&t1, NULL, Thread_1, &count);
    pthread_create(&t2, NULL, Thread_2, &count);
    pthread_create(&t3, NULL, Thread_3, &count);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("\nMain thread is exiting...\n");
}
void *Thread_1(void *in)
{
    int max_lim = *((int *)in);
    int i;
    char string[10] = "";
    printf("Thread1: Process id is %d\n", getpid());
    printf("Thread1: Thread id is %lu\n", pthread_self());

    printf("Enter input for Thread 1\n");
    fflush(stdin);
    scanf("%s",string);
    for (i = 0; i < max_lim; i++)
    {
        printf("%d %s\n", i, string);
    }
    pthread_exit(NULL);
}

void *Thread_2(void *in)
{
    int max_lim = *((int *)in);
    int i;
    char string[10] = "";
    printf("Thread2: Process id is %d\n", getpid());
    printf("Thread2: Thread id is %lu\n", pthread_self());
    fflush(stdin);
    printf("Enter input for Thread 2\n");
    scanf("%s",string);
    for (i = 0; i < max_lim; i++)
    {
        printf("%d %s\n", i, string);
    }
    pthread_exit(NULL);
}

void *Thread_3(void *in)
{
    int max_lim = *((int *)in);
    int i;
    char string[10] = "";
    printf("Thread3: Process id is %d\n", getpid());
    printf("Thread3: Thread id is %lu\n", pthread_self());
    
    fflush(stdin);
    printf("Enter input for Thread 3\n");
    scanf("%s",string);
    for (i = 0; i < max_lim; i++)
    {
        printf("%d %s\n", i, string);
    }
    pthread_exit(NULL);
}