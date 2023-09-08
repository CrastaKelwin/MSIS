/*
    8. Fork 3 children . One of them executes ls, another date and the third pwd
    command. Run the program and observe the results on each run.
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    int pid = fork();
    if (pid == 0)
    {
        printf("Child 1 Process ID %d\n", getpid());
        printf("Child 1 Process Parent ID %d\n", getppid());
        printf("Child 1 Executing ls\n");
        execl("/bin/ls", "ls", NULL);
    }
    else if (pid > 0)
    {
        int stat = 0;
        // wait((int *)NULL);
        waitpid(pid, &stat, 0);
        printf("Child 1 Process returned %d\n", WEXITSTATUS(stat));
        printf("Main Process ID %d\n", getpid());
        printf("Main Process Parent ID %d\n", getppid());
        pid = fork();
        if (pid == 0)
        {
            printf("Child 2 Process ID %d\n", getpid());
            printf("Child 2 Process Parent ID %d\n", getppid());
            printf("Child 2 Executing date\n");
            execl("/bin/date", "date", NULL);
        }
        else if (pid > 0)
        {
            int stat = 0;
            // wait((int *)NULL);
            waitpid(pid, &stat, 0);
            printf("Child 2 Process returned %d\n", WEXITSTATUS(stat));
            printf("Main Process ID %d\n", getpid());
            printf("Main Process Parent ID %d\n", getppid());
            pid = fork();
            if (pid == 0)
            {
                printf("Child 3 Process ID %d\n", getpid());
                printf("Child 3 Process Parent ID %d\n", getppid());
                printf("Child 3 Executing date\n");
                execl("/bin/pwd", "pwd", NULL);
            }
            else if (pid > 0)
            {
                int stat = 0;
                // wait((int *)NULL);
                waitpid(pid, &stat, 0);
                printf("Child 3 Process returned %d\n", WEXITSTATUS(stat));
                printf("Main Process ID %d\n", getpid());
                printf("Main Process Parent ID %d\n", getppid());
            }
            else
            {
                printf("child 3 process creation failed");
            }
        }
        else
        {
            printf("child 2 process creation failed");
        }
    }
    else
    {
        printf("child 1 process creation failed");
    }
    return 0;
}
