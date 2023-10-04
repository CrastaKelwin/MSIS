#ifndef __LIST_MERGE_H__
#define __LIST_MERGE_H__

typedef struct _node
{
    int data;
    struct _node *nxt;
} Node;

typedef struct _list
{
    Node *head;
    Node *tail;
    int count;
}List;

List *initialiseList();
int InsertAtListEnd(List *list,int data);
int InsertAtListBegining(List *list,int data);
void Printlist(List *list, const char *test_msg);

List *MergeSortedListInSortedOrder(List *list_1, List *list_2);
#endif //__LIST_MERGE_H__