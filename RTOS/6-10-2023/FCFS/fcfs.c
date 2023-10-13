// FCFS algorithm (you may assume all processes arrive at time zero).
#include "fcfs.h"
#include <string.h>
#include <sys/time.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
typedef struct process_list
{
    Process *head;
    Process *tail;
    int count;
} ProcessList;

ProcessList process_list = {NULL, NULL, 0};

RetCode ProcessAdd(Process *p_new, ProcessHandler handler, const char *p_name)
{
    strcpy(p_new->pt_name, p_name);
    p_new->handler = handler;
    p_new->next_process = NULL;
    p_new->poll_needed = 0xaa;
    // insert the new process at the end of list
    if (process_list.count == 0)
    {
        process_list.head = process_list.tail = p_new;
    }
    else
    {
        process_list.tail->next_process = p_new;
        process_list.tail = p_new;
    }
    process_list.count++;
    gettimeofday(&p_new->arrival_time, NULL);
}

RetCode ProcessPoll(Process *p_new)
{
    p_new->poll_needed = 0xaa;
    gettimeofday(&p_new->arrival_time, NULL);
}
RetCode ProcessScheduler()
{
    struct timeval scheduler_run_time;
    printf("\n|    Process    |   Burst time  |   Arrival     |   Wait time   |\n");
    gettimeofday(&scheduler_run_time, NULL);
    uint64_t entry_us = (scheduler_run_time.tv_sec * 1000) + (scheduler_run_time.tv_usec);
    for (Process *p = process_list.head; p != NULL; p = p->next_process)
    {
        if (p->poll_needed == 0xaa)
        {
            struct timeval start_time, end_time;
            gettimeofday(&start_time, NULL);
            p->handler();
            gettimeofday(&end_time, NULL);
            p->poll_needed = 0;
            uint64_t burst_time = ((end_time.tv_sec - start_time.tv_sec) * 1000) + (end_time.tv_usec - start_time.tv_usec);
            uint64_t end_us = (end_time.tv_sec * 1000) + (end_time.tv_usec);
            uint64_t start_us = (start_time.tv_sec * 1000) + (start_time.tv_usec);
            uint64_t arrival_us = (p->arrival_time.tv_sec * 1000) + (p->arrival_time.tv_usec);
            printf("|\t%s\t|\t%lu\t|\t%lu\t|\t%lu\t|\t%lu\t| \n", p->pt_name, burst_time, arrival_us, start_us - entry_us, end_us - end_us);
        }
    }
}
