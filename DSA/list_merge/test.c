#include "list_merge.h"
#include <assert.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    List *test_list_1 = initialiseList();
    assert(test_list_1 != NULL);
    InsertAtListEnd(test_list_1, 10);
    InsertAtListEnd(test_list_1, 20);
    InsertAtListEnd(test_list_1, 30);
    InsertAtListEnd(test_list_1, 40);
    InsertAtListEnd(test_list_1, 50);
    InsertAtListEnd(test_list_1, 500);
    InsertAtListEnd(test_list_1, 600);
    InsertAtListEnd(test_list_1, 700);
    assert(test_list_1->count == 8);
    assert(test_list_1->head->data == 10);
    assert(test_list_1->tail->data == 700);
    Printlist(test_list_1, "");

    List *test_list_2 = initialiseList();
    assert(test_list_2 != NULL);
    InsertAtListEnd(test_list_2, 1);
    InsertAtListEnd(test_list_2, 2);
    InsertAtListEnd(test_list_2, 3);
    InsertAtListEnd(test_list_2, 5);
    InsertAtListEnd(test_list_2, 8);
    InsertAtListEnd(test_list_2, 13);
    InsertAtListEnd(test_list_2, 26);
    InsertAtListEnd(test_list_2, 45);
    assert(test_list_2->count == 8);
    assert(test_list_2->head->data == 1);
    assert(test_list_2->tail->data == 45);
    Printlist(test_list_2, "");

    List *res = MergeSortedListInSortedOrder(test_list_1, test_list_2);
    Printlist(res, "");

    return 0;
}