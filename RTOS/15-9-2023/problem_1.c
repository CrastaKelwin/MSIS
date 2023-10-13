#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <ctype.h>
int main()
{
    int seg_id;
    char *sm;
    const int len = 100;
    seg_id = shmget(IPC_PRIVATE, len, S_IRUSR | S_IWUSR); // allocatesm=(char *) shmat(seg_id, NULL, 0); // attach
    sm = (char *)shmat(seg_id, NULL, 0);
    for (char i = 'A'; i <= 'Z'; i++)
    {
        sm[i - 'A'] = i;
    }

    for (int i = 0; i < len; i++)
    {
        printf("sm[%d] = 0x%02X,\t", i, sm[i]);
    }

    printf("\n%s\n", sm); // write a msg to the shared segmentprintf(“%s”, sm); // printing the shared memory contentsshmdt(sm); //detatching the segment
    for (int i = 0; i < len; i++)
    {
        sm[i] = tolower(sm[i]);
    }

    for (int i = 0; i < len; i++)
    {
        printf("sm[%d] = 0x%02X,\t", i, sm[i]);
    }
    printf("\n%s\n", sm);
    shmdt(sm); // write a msg to the shared segmentprintf(“%s”, sm); // printing the shared memory contentsshmdt(sm); //detatching the segment

    shmctl(seg_id, IPC_RMID, NULL); // deallocating th segment from the memory area
    return 0;
}
