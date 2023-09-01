#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("main PID %d\n",getpid());
    int pid = fork();
    if(pid<0){
        printf("Error creating fork\n");
    }
    else if(pid==0)
    {
        printf("I am child process with PID %d\n",getpid());
    }
    else{
        wait((int *)NULL);
        printf("I am parent \n");
    }
    return 0;
}