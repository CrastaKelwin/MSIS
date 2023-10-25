/*
Let a parent process create a segment of length 2k and write n strings to the area.
Let the value of n be passed as a commandline argument. Next, let the parent fork a child.
Let the child capitalise the first character of each string.Once the child completes
let the parent access the shared area and display their contents to the screen.
*/


#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <ctype.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int seg_id;
    char *sm;
    const int len = 2048;
    seg_id = shmget(IPC_PRIVATE, len, S_IRUSR | S_IWUSR); // allocatesm=(char *) shmat(seg_id, NULL, 0); // attach
    sm = (char *)shmat(seg_id, NULL, 0);

    int i = 0;
    for (i = 0; i < 10; i++)
    {
        sm[i] = i;
    }
    char a = 'a';
    for (; i < 100 && a <= 'z'; i++)
    {
        sm[i] = a++;
    }

    int pid = fork();
    if (pid == 0)
    {
        printf("I am the child\n");
        printf("Child Process ID %d\n", getpid());
        printf("Child Process Parent ID %d\n", getppid());
        for (int i = 0; i < len; i++)
        {
            if (isalpha(sm[i]))
            {
                sm[i] = toupper(sm[i]);
            }
            else if (i < 10)
            {
                sm[i] += 100;
            }
        }

        exit(0);
    }
    else if (pid > 0)
    {
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
    for (int i = 0; i < len; i++)
    {
        printf("sm[%d] = 0x%02X,\t", i, sm[i]);
    }
    printf("\n%s\n", &sm[10]);
    shmdt(sm); // write a msg to the shared segmentprintf(“%s”, sm); // printing the shared memory contentsshmdt(sm); //detatching the segment

    shmctl(seg_id, IPC_RMID, NULL); // deallocating th segment from the memory area
    return 0;
}
