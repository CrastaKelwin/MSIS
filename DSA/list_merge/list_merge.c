#include "list_merge.h"
#include <stdlib.h>
#include <stdio.h>

List *initialiseList()
{
    List *list = (List *)malloc(sizeof(List));
    if (list)
    {
        list->head = list->tail = NULL;
        list->count = 0;
    }
    return list;
}

static Node *GetNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node)
    {
        node->data = data;
        node->nxt = NULL;
    }
    return node;
}
int InsertAtListEnd(List *list, int data)
{
    if (list)
    {
        if (list->count == 0)
        {
            Node *new_node = GetNode(data);
            if (new_node)
            {
                list->head = list->tail = new_node;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            Node *new_node = GetNode(data);
            if (new_node)
            {
                list->tail->nxt = new_node;
                list->tail = new_node;
            }
            else
            {
                return -1;
            }
        }
        list->count++;
        return 0;
    }
    return -1;
}
int InsertAtListBegining(List *list, int data);

void Printlist(List *list, const char *test_msg)
{
    if (list)
    {
        printf("%s, head %p, tail %p List Elements %d : [ ", test_msg, list->head, list->tail, list->count);
        for (Node *temp = list->head; temp != NULL; temp = temp->nxt)
        {
            printf("%02d ", temp->data);
        }
        printf("]\n");
    }
}

List *MergeSortedListInSortedOrder(List *list_1, List *list_2)
{
    List *list_result = initialiseList();
    if (list_result && list_1 && list_2)
    {
        Node *i = list_1->head;
        Node *j = list_2->head;

        while ((i != NULL) && (j != NULL))
        {
            if (i->data < j->data)
            {
                InsertAtListEnd(list_result, i->data);
                i = i->nxt;
            }
            else
            {
                InsertAtListEnd(list_result, j->data);
                j = j->nxt;
            }
        }
        while (i != NULL)
        {
            InsertAtListEnd(list_result, i->data);
            i = i->nxt;
        }
        while (j != NULL)
        {
            InsertAtListEnd(list_result, j->data);
            j = j->nxt;
        }
    }
    return list_result;
}