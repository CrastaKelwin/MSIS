#include "fcfs.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void f1()
{
    // printf("f1.. executing\n");
    sleep(1);
    // printf("f1.. ending\n");

}

void f2()
{
    // printf("f2.. executing\n");
    usleep(100);
}


void f3()
{
    // printf("f3.. executing\n");
    usleep(100);
}

int main(int argc, const char * argv[])
{
    Process p1,p2,p3;
    ProcessAdd(&p1,&f1,"p1");
    ProcessAdd(&p2,&f2,"p2");
    ProcessAdd(&p3,&f3,"p3");
    ProcessScheduler();
}