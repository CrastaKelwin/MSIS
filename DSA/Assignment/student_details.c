#include "student_details.h"
#include <stdint.h>
#include <stdlib.h>
#include "retcode.h"
#include <stdio.h>
#include <string.h>

static LogList _log_list;
static LogList *log_list = &_log_list;
void LogTransaction(TypeOfOperation operation);
Student *GetStudentNode(char *name, int roll_number)
{
    Student *node = (Student *)malloc(sizeof(Student));
    if (node)
    {
        strcpy(node->name, name);
        node->roll_number = roll_number;
        node->next = NULL;
    }
    return node;
}

StudentList *InitialiseList()
{
    StudentList *list = (StudentList *)malloc(sizeof(StudentList));
    if (list != NULL)
    {
        list->count = 0;
        list->head = list->tail = NULL;
    }
    return list;
}

RetCode InsertAtBeginning(StudentList *list, char *name, int roll_number)
{
    if (list != NULL)
    {
        LogTransaction(kOperationInsert);
        if (list->count == 0)
        {
            Student *node = GetStudentNode(name, roll_number);
            if (node != NULL)
            {
                list->head = node;
                list->tail = node;
                list->count++;
                return kRetCodeOk;
            }
        }
        else
        {
            Student *node = GetStudentNode(name, roll_number);
            if (node != NULL)
            {
                node->next = list->head;
                list->head = node;
                list->count++;
                return kRetCodeOk;
            }
        }
    }
    return kRetCodeBadParam;
}

RetCode InsertAtEnd(StudentList *list, char *name, int roll_number)
{
    if (list != NULL)
    {
        LogTransaction(kOperationInsert);
        if (list->count == 0)
        {
            Student *node = GetStudentNode(name, roll_number);
            if (node != NULL)
            {
                list->head = node;
                list->tail = node;
                list->count++;
                return kRetCodeOk;
            }
        }
        else
        {
            Student *node = GetStudentNode(name, roll_number);
            if (node != NULL)
            {
                list->tail->next = node;
                list->tail = node;
                list->count++;
                return kRetCodeOk;
            }
        }
    }
    return kRetCodeBadParam;
}

void Printlist(StudentList *list, const char *test_msg)
{
    if (list)
    {
        printf("%s, head %p, tail %p StudentList Elements %d : [ ", test_msg, list->head, list->tail, list->count);
        for (Student *temp = list->head; temp != NULL; temp = temp->next)
        {
            printf("%u %s", temp->roll_number, temp->name);
        }
        printf("]\n");
    }
}

RetCode SearchStudent(StudentList *list, const char *name)
{
    Student *temp;
    LogTransaction(kOperationSearch);
    for (temp = list->head; temp != NULL; temp = temp->next)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return kRetCodeFound;
        }
    }
    return kRetCodeNotFound;
}

RetCode DeleteAtBeginning(StudentList *list)
{
    if (list != NULL)
    {
        LogTransaction(kOperationDelete);
        if (list->count == 0)
        {
            return kRetCodeNotFound;
        }
        if (list->count == 1)
        {
            free(list->head);
            list->head = list->tail = NULL;
            list->count--;
            return kRetCodeOk;
        }
        Student *temp = list->head;
        list->head = list->head->next;
        list->count--;
        free(temp);
        return kRetCodeOk;
    }
    return kRetCodeBadParam;
}
RetCode DeleteAtEnd(StudentList *list)
{
    if (list != NULL)
    {
        LogTransaction(kOperationDelete);
        if (list->count == 0)
            return kRetCodeNotFound;
        if (list->count == 1)
        {
            free(list->head);
            list->head = list->tail = NULL;
        }
        else
        {
            Student *temp;
            for (temp = list->head; temp->next->next != NULL; temp = temp->next)
                ;
            free(temp->next);
            temp->next = NULL;
            list->tail = temp;
        }
        list->count--;
        return kRetCodeOk;
    }
    return kRetCodeBadParam;
}

RetCode FreeList(StudentList *list)
{
    while (kRetCodeNotFound != DeleteAtBeginning(list))
        ;
    free(list);
}

void LogTransaction(TypeOfOperation operation)
{
    if (operation == kOperationInsert)
    {
        log_list->insert_count++;
    }
    else if (operation == kOperationDelete)
    {
        log_list->delete_count++;
    }
    if (log_list->log_count == 0)
    {
        Log *log = (Log *)malloc(sizeof(Log));
        if (log != NULL)
        {
            log->type_of_operation = operation;
            log->time = time(NULL);
            log_list->head = log;
            log_list->tail = log;
            log_list->log_count++;
        }
    }
    else
    {
        Log *log = (Log *)malloc(sizeof(Log));
        if (log != NULL)
        {
            log->type_of_operation = operation;
            log->time = time(NULL);
            log->next = log_list->head;
            log_list->head = log;
            log_list->log_count++;
        }
    }
}

void PrintTransactionLog()
{
    const char *txn[kOperationMax] =
        {
            [kOperationInsert] = "Insert",
            [kOperationSearch] = "Search",
            [kOperationDelete] = "Delete"};
    printf("head %p, tail %p log count %d : [ \n", log_list->head, log_list->tail, log_list->log_count);
    for (Log *temp = log_list->head; temp != NULL; temp = temp->next)
    {
        struct tm *_time;
        _time = localtime(&temp->time);
        printf("%d-%d-%d %d:%d:%d %s \n", _time->tm_mday, _time->tm_mon+1, _time->tm_year+1900, _time->tm_hour, _time->tm_min, _time->tm_sec, txn[temp->type_of_operation]);
    }
    printf("]\n");
}