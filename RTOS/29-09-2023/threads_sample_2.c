/********************************************************************
***************************
 (Q) Main program defines an array(Assume array size =5) and creates
2 threads.
One thread computes the sum of array elements.
 The second thread displays all odd numbers present in the array.
 (Pass the array as a parameter while creating the threads.)
Aso Publish the process id and thread-id in every thread
*********************************************************************
**************************/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#define LEN 5
void *f1(void *);
void *f2(void *);
int main()
{
    int i;
    int arr1[] = {11, 12, 13, 14, 15};

    pthread_t t1, t2;
    // pthread_attr_t a1;
    printf("Main: Process id is %d\n", getpid());
    printf("Main: Main thread id is %lu\n", pthread_self());
    printf("\nMain thread: Here's the original array:\n");

    for (i = 0; i < LEN; i++)
        printf("%d\t", arr1[i]);
    printf("\n");
    // pthread_attr_init(&a1);
    pthread_create(&t1, NULL, f1, arr1);
    pthread_create(&t2, NULL, f2, arr1);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\nMain thread is exiting...\n");
}
void *f1(void *arr1)
{
    int sum = 0, i, num;
    printf("Thread1: Process id is %d\n", getpid());
    printf("Thread1: Thread id is %lu\n", pthread_self());
    for (i = 0; i < LEN; i++)
    {
        num = ((int *)arr1)[i]; // num = arr[i];
        sum += num;
    }
    printf("\nThread1: The sum of all elements of the array is %d\n", sum);
}
void *f2(void *arr1)
{
    int sum = 0, i, num;
    printf("Thread2: Process id is %d\n", getpid());
    printf("Thread2: Thread id is %lu\n", pthread_self());
    printf("\nThread2: Here are the odd numbers:\n");
    for (i = 0; i < LEN; i++)
    {
        num = ((int *)arr1)[i];
        if ((num % 2) != 0)
            printf("%d\t", num);
    }

    printf("\n");
}