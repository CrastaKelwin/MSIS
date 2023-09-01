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
        if (pid == 0)
        {
            execl("/bin/gcc", "gcc", "-o", "gen_series", "gen_series.c", NULL);
        }
        else if (pid > 0)
        {
            wait((int *)NULL);
            execl("./gen_series", "gen_series", NULL);
        }
        else
        {
            printf("fork failed\n");
        }
    }
    else
    {
        // main
        wait((int *)NULL);
        pid = fork();
        if (pid == 0)
        {
            execl("/bin/rm", "rm", "gen_series", NULL);
        }
        else if (pid > 0)
        {
            wait((int *)NULL);
        }
        printf("Hello World!\n");
    }
    return 0;
}