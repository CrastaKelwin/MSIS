#ifndef _LIST_H_
#define _LIST_H_

#include "retcode.h"

typedef struct _node{
    int data;
    struct _node *next;
}Node;

typedef struct _list{
    Node *head;
    Node *tail;
    int count;
}List;

List *InitialiseList();

RetCode InsertAtBeginning(List *list, int data);

RetCode InsertAtEnd(List *list, int data);
RetCode InsertAfterElement(List *list, int data, int element);
RetCode InsertAtPosition(List *list, int data, int pos);

void Printlist(List *list,const char *test_msg);

RetCode SearchElement(List *list, int element);
RetCode MergeList(List *list_1, List *list_2);
List *SpiltList(List *list, int split_index);

RetCode DeleteAtBeginning(List *list);
RetCode DeleteAtEnd(List *list);
RetCode DeleteElement(List *list, int element);

RetCode FreeList(List *list);

#endif //_LIST_H_