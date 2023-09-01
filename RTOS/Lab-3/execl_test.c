#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("Hii\n");
    execl("/bin/pwd", "pwd", NULL);
    printf("This wil not execute because execl will end the process after the execution\n");
    return 0;
}