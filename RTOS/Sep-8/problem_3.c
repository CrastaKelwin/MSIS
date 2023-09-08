/*
    3. (i) Create a child process from a program. Let the child process first sleep for
    8 seconds and then output a message namely “I am the child”. Parent outputs a
    message namely ‘I am the parent’ and then waits for the child to complete.
    Execute the program and observe the result.
    What happens if there is no wait in the parent? Observe.
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
        sleep(8);
        printf("I am the child\n");
        printf("Child Process ID %d\n", getpid());
        printf("Child Process Parent ID %d\n", getppid());
        exit(0);
    }
    else if (pid > 0)
    {
        int stat = 0;
        printf("I am the parent\n");
        wait((int *)NULL);
        // waitpid(pid, &stat, 0);
        // printf("Child Process returned %d\n", WEXITSTATUS(stat));
        printf("Main Process ID %d\n", getpid());
        printf("Main Process Parent ID %d\n", getppid());
    }
    else
    {
        printf("child process creation failed");
    }
    return 0;
}
