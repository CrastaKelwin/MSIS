/*
    6. Spawn a child process which executes ls command with option –l
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
        printf("Child Process ID %d\n", getpid());
        printf("Child Process Parent ID %d\n", getppid());
        printf("Executing ls -l\n");
        execl("/bin/ls","ls","-l",NULL);
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
