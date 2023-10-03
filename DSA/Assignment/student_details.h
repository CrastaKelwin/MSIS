#ifndef _STUDENT_DETAILS_H_
#define _STUDENT_DETAILS_H_

#include <stdint.h>
#include <time.h>
#include "retcode.h"

#define MAX_NAME_LENGTH 20

typedef  struct _student{
    char name[MAX_NAME_LENGTH];
    uint32_t roll_number;
    struct _student *next;
}Student;



typedef struct _student_list{
    Student *head;
    Student *tail;
    int count;
}StudentList;

typedef enum {
    kOperationInsert,
    kOperationSearch,
    kOperationDelete,
    kOperationMax
}TypeOfOperation;

typedef  struct _log{
    time_t time; // from time.h
    TypeOfOperation type_of_operation;
    struct _log *next;
}Log;

typedef  struct _log_list{
    Log *head;
    Log *tail;
    int log_count;
    int insert_count;
    int delete_count;
}LogList;

StudentList *InitialiseList();

RetCode InsertAtBeginning(StudentList *list, char *name, int roll_number);
RetCode InsertAtEnd(StudentList *list,  char *name, int roll_number);

void Printlist(StudentList *list,const char *test_msg);

RetCode SearchStudent(StudentList *list, const char *name);

RetCode DeleteAtBeginning(StudentList *list);
RetCode DeleteAtEnd(StudentList *list);
RetCode DeleteElement(StudentList *list, Student *student);

RetCode FreeList(StudentList *list);

void PrintTransactionLog();

#endif