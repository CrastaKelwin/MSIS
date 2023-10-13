#ifndef _FCFS_H_
#define _FCFS_H_

#include "../retcode.h"
#include <stdlib.h>

typedef void (*ProcessHandler)(void);
typedef struct _process
{
    ProcessHandler handler;
    struct _process *next_process;
    char pt_name[20];
    struct timeval arrival_time;
    int poll_needed;
} Process;

RetCode ProcessAdd(Process *p, ProcessHandler handler, const char * p_name);

RetCode ProcessScheduler();

#endif //_FCFS_H_