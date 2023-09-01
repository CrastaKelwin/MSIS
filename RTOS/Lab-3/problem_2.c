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
        printf("I am child process with PID %d\n", getpid());
        pid = fork();
        if (pid < 0)
        {
            printf("Error creating fork\n");
        }
        else if (pid == 0)
        {
            // child of child of main

            printf("I am child child process with PID %d\n", getpid());
            printf("I am child child process executing pwd\n");
            execl("/bin/pwd", "pwd", NULL);
        }
        else
        {
            // child of main
            wait((int *)NULL);
            printf("I am child process executing ls -l\n");
            execl("/bin/ls", "ls", "-l", NULL);
            printf("I am parent \n");
        }
    }
    else
    {
        // main
        wait((int *)NULL);
        printf("I am main process executing ls\n");
        execl("/bin/ls", "ls", NULL);
        printf("I am parent \n");
    }
    return 0;
}