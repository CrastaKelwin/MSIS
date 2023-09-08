/*
    2. WAP which forks a new process. Let the child process initiate a counter to
    zero and keep incrementing it until it reaches 999. Let it exit with a
    value 255. 
    Let the parent use the waitpid() system for the child to complete. And once the 
    child completes the parent displays a message namely “Parent: Child 
    processcompleted". Also let the parent output the exit value (exit status) of the 
    child. 
    What happens if there is no waitpid() in the parent? Observe.
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
        for (int i = 0; i < 1000; i++)
        {
            printf("%d, ", i);
        }
        printf("Child Process ID %d\n", getpid());
        printf("Child Process Parent ID %d\n", getppid());
        exit(255);
    }
    else if (pid > 0)
    {
        int stat = 0;
        waitpid(pid, &stat, 0);
        printf("Parent: Child process completed\n");
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
