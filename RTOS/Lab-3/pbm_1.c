#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("main PID %d\n", getpid());
    int pid = fork();
    if (pid < 0)
    {
        printf("Error creating fork\n");
    }
    else if (pid == 0)
    {
        // child of main
        printf("I am child1 process with PID %d\n", getpid());
        printf("I am child1 process with PPID %d\n", getppid());
        execl("/bin/pwd", "pwd", NULL);
    }
    else
    {
        // main
        // wait((int *)NULL);
        printf("I am main process executing ls\n");
        printf("I am parent \n");
        pid = fork();
        if (pid < 0)
        {
        }
        else if (pid == 0)
        {

            printf("I am child2 process with PID %d\n", getpid());
            printf("I am child2 process with PPID %d\n", getppid());
        }
        else
        {
             wait((int *)NULL);
        }
    }
    return 0;
}