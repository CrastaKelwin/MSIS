
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t file_mutex;
void *Thread_r1(void *);
void *Thread_r2(void *);
void *Thread_r3(void *);
void *Thread_w4(void *);
void *Thread_w5(void *);

FILE *fp = NULL;

int main()
{

    pthread_t tr1, tr2, tr3, tw4, tw5;
    printf("Main: Process id is %d\n", getpid());
    printf("Main: Main thread id is %lu\n", pthread_self());

    if (pthread_mutex_init(&file_mutex, NULL) != 0)
    {
        printf("\n mutex init has failed\n");
        return 1;
    }
    pthread_create(&tr1, NULL, Thread_1, NULL);
    pthread_create(&tr2, NULL, Thread_2, NULL);
    pthread_create(&tr3, NULL, Thread_1, NULL);
    pthread_create(&tw4, NULL, Thread_2, NULL);
    pthread_create(&tw4, NULL, Thread_2, NULL);
    pthread_join(tr1, NULL);
    pthread_join(tr2, NULL);

    printf("\nMain thread is exiting...\n");
}
void *Thread_1(void *in)
{
    FILE *fp_new = NULL;
    printf("T1\n");
    pthread_mutex_lock(&file_mutex);
    printf("T1 m\n");
    fp = fopen("sample.txt", "r");
    fp_new = fopen("result.txt", "w");
    char ch = getc(fp);
    while (ch != EOF)
    {
        putc(ch, fp_new);
        ch = getc(fp);
    }
    printf("Copy complete\n");
    fclose(fp);
    fclose(fp_new);
    pthread_mutex_unlock(&file_mutex);
    pthread_exit(NULL);
}

void *Thread_2(void *in)
{
    FILE *fp_new = NULL;
    sleep(2);
    printf("T2\n");
    pthread_mutex_lock(&file_mutex);
    printf("T2 m\n");
    fp_new = fopen("result.txt", "a+");
    char input[10] = "";
    int count = 0;
    scanf("%s", input);
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        int index = 0;
        while (input[index] != '\0')
        {
            putc(input[index], fp_new);
            index++;
        }
    }

    fclose(fp_new);
    pthread_mutex_unlock(&file_mutex);
    pthread_exit(NULL);
}
