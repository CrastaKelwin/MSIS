#include "list.h"
#include <stdint.h>
#include <stdlib.h>
#include "retcode.h"
#include <stdio.h>

Node *GetNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node)
    {
        node->data = data;
        node->next = NULL;
    }
    return node;
}
List *InitialiseList()
{
    List *list = (List *)malloc(sizeof(List));
    if (list != NULL)
    {
        list->count = 0;
        list->head = list->tail = NULL;
    }
    return list;
}

RetCode InsertAtBeginning(List *list, int data)
{
    if (list != NULL)
    {
        if (list->count == 0)
        {
            Node *node = GetNode(data);
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
            Node *node = GetNode(data);
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

RetCode InsertAtEnd(List *list, int data)
{
    if (list != NULL)
    {
        if (list->count == 0)
        {
            Node *node = GetNode(data);
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
            Node *node = GetNode(data);
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

RetCode InsertAfterElement(List *list, int data, int element)
{
    if (list != NULL)
    {
        if (list->count == 0)
        {
            return kRetCodeBadParam;
        }
        Node *node;
        for (node = list->head; node != NULL; node = node->next)
        {
            if (node->data == element)
            {
                break;
            }
        }
        if (node != NULL)
        {
            Node *new_node = GetNode(data);
            new_node->next = node->next;
            node->next = new_node;
            list->count++;
            return kRetCodeOk;
        }
        return kRetCodeBadParam;
    }
    return kRetCodeBadParam;
}

RetCode InsertAtPosition(List *list, int data, int pos)
{

    if (list != NULL)
    {
        if (pos == 0)
        {
            return InsertAtBeginning(list, data);
        }
        if (pos == list->count) // 0th position of last position count
        {
            return InsertAtEnd(list, data);
        }
        if (pos > list->count)
        {
            return kRetCodeBadParam;
        }
        Node *temp = list->head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *new_node = GetNode(data);
        if (new_node)
        {
            new_node->next = temp->next;
            temp->next = new_node;
            list->count++;
        }
        return kRetCodeOk;
    }
    return kRetCodeBadParam;
}

void Printlist(List *list, const char *test_msg)
{
    if (list)
    {
        printf("%s, head %p, tail %p List Elements %d : [ ", test_msg, list->head, list->tail, list->count);
        for (Node *temp = list->head; temp != NULL; temp = temp->next)
        {
            printf("%d ", temp->data);
        }
        printf("]\n");
    }
}

RetCode SearchElement(List *list, int element)
{
    Node *temp;
    for (temp = list->head; temp != NULL; temp = temp->next)
    {
        if (temp->data == element)
        {
            return kRetCodeFound;
        }
    }
    return kRetCodeNotFound;
}

RetCode DeleteAtBeginning(List *list)
{
    if (list != NULL)
    {
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
        Node *temp = list->head;
        list->head = list->head->next;
        list->count--;
        free(temp);
        return kRetCodeOk;
    }
    return kRetCodeBadParam;
}
RetCode DeleteAtEnd(List *list)
{
    if (list != NULL)
    {
        if (list->count == 0)
            return kRetCodeNotFound;
        if (list->count == 1)
        {
            free(list->head);
            list->head = list->tail = NULL;
        }
        else
        {
            Node *temp;
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

RetCode DeleteElement(List *list, int element)
{
    if (list != NULL)
    {
        if (list->count == 0)
            return kRetCodeNotFound;
        if (list->head->data == element)
        {
            return DeleteAtBeginning(list);
        }
        if (list->tail->data == element)
        {
            return DeleteAtEnd(list);
        }
        Node *temp;
        Node *prev = NULL;
        for (temp = list->head; temp != NULL; prev = temp, temp = temp->next)
        {
            if (temp->data == element)
            {
                prev->next = temp->next;
                list->count--;
                free(temp);
                return kRetCodeOk;
            }
        }
        return kRetCodeNotFound;
    }
    return kRetCodeBadParam;
}

RetCode FreeList(List *list)
{
    while (kRetCodeNotFound != DeleteAtBeginning(list))
        ;
    free(list);
}

RetCode MergeList(List *list_1, List *list_2)
{
    if (list_1 != NULL && list_2 != NULL)
    {
        if (list_1->count == 0)
        {
            *list_1 = *list_2;
            printf("cont zero\n");
        }
        else
        {
            list_1->tail->next = list_2->head;
            list_1->count = list_1->count + list_2->count;
            list_1->tail = list_2->tail;
        }
        free(list_2);
        return kRetCodeOk;
    }
    printf("error\n");
    return kRetCodeBadParam;
}

List *SpiltList(List *list, int split_index)
{
    if (list)
    {
        if (list->count > split_index && split_index > 0)
        {
            Node *temp = list->head;
            List *new_list = InitialiseList();
            for (int i = 0; i < split_index-1; i++)
            {
                temp = temp->next;
            }
            new_list->head = temp->next;
            new_list->tail = list->tail;
            new_list->count = list->count - split_index;
            temp->next = NULL;
            list->tail = temp;
            list->count = split_index;
            return new_list;
        }
    }
    return NULL;
}