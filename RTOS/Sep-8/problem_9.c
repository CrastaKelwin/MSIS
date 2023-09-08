/*
    9. Write a program which forks a new process. Let the child process compute the
    summation of first n natural numbers, and let it output the result. Pass ‘n’ as a
    commandline argument. The parent waits for the child to complete and finally
    the parent process too outputs the result.
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(const int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("Input error\n");
        exit(-1);
    }
    int pid = fork();
    if (pid == 0)
    {
        printf("Child 1 Process ID %d\n", getpid());
        printf("Child 1 Process Parent ID %d\n", getppid());
        printf("Child 1 Executing summation of first %lu natural numbers\n", strtoul(argv[1], NULL, 10));
        unsigned int sum = 0;
        for (int i = 0; i < strtoul(argv[1], NULL, 10); i++)
        {
            sum += i;
        }
        printf("Sum of %lu natural Numbers = %u\n", strtoul(argv[1], NULL, 10), sum);
        exit(sum);
    }
    else if (pid > 0)
    {
        int stat = 0;
        // wait((int *)NULL);
        waitpid(pid, &stat, 0);
        printf("Child 1 Process computed and returned sum of %lu natural numbers = %d\n", strtoul(argv[1], NULL, 10), WEXITSTATUS(stat));
        printf("Main Process ID %d\n", getpid());
        printf("Main Process Parent ID %d\n", getppid());
        pid = fork();
    }
    else
    {
        printf("child 1 process creation failed");
    }
    return 0;
}
