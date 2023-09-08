/*
    4. Create a child process which outputs your name to the screen and exits with a
    value 255. Use wait() system call in the parent, for the child to complete 
    execution. Also use the WEXITSTATUS macro to display the status value returned by the child.
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
        printf("I am Kelwin\n");
        printf("Child Process ID %d\n", getpid());
        printf("Child Process Parent ID %d\n", getppid());
        exit(255);
    }
    else if (pid > 0)
    {
        int stat = 0;
        // wait((int *)NULL);
        waitpid(pid, &stat, 0);
        printf("Child Process returned %d\n", WEXITSTATUS(stat));
        printf("Main Process ID %d\n", getpid());
        printf("Main Process Parent ID %d\n", getppid());
    }
    else
    {
        printf("child process creation failed");
    }
    return 0;
}
