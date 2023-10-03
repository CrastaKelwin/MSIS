/** Create a 4096 bytes length shared memory segment. Attach it to a process, write hello to it, read from it & display the contents to the screen, detach the process from the memory segment and finally remove the memory segment from
memory***/
#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
int main()
{
    int seg_id;
    char *sm;
    const int len = 4096;
    seg_id = shmget(IPC_PRIVATE, len, S_IRUSR | S_IWUSR); // allocatesm=(char *) shmat(seg_id, NULL, 0); // attach
    sprintf(sm, "hello…");                                // write a msg to the shared segmentprintf(“%s”, sm); // printing the shared memory contentsshmdt(sm); //detatching the segment
    shmctl(seg_id, IPC_RMID, NULL);                       // deallocating th segment from the memory area
    return 0;
}
