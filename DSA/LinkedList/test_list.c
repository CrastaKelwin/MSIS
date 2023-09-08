#include "list.h"
#include <stdlib.h>
#include "retcode.h"
#include <assert.h>

int main(void) {
    List *test_list = InitialiseList();
    Printlist(test_list, "After Init");
    assert(test_list->count == 0);  // Assert that the list count is 0 after initialization

    InsertAtBeginning(test_list, 19);
    InsertAtBeginning(test_list, 36);
    Printlist(test_list, "After two insert at beginning");
    assert(test_list->count == 2);  // Assert that the list count is 2 after insertions

    InsertAtEnd(test_list, 56);
    InsertAtEnd(test_list, 46);
    Printlist(test_list, "Two insert at end");
    assert(test_list->count == 4);  // Assert that the list count is 4 after insertions

    InsertAfterElement(test_list, 44, 56);
    Printlist(test_list, "Insert after 56");
    assert(test_list->count == 5);  // Assert that the list count is 5 after insertion

    InsertAfterElement(test_list, 56, 40);
    Printlist(test_list, "Insert after 40");
    assert(test_list->count == 5);  // Assert that the list count is 6 after insertion

    InsertAtPosition(test_list, 77, 0);
    Printlist(test_list, "Insert at pos 0");
    assert(test_list->count == 6);  // Assert that the list count is 7 after insertion

    InsertAtPosition(test_list, 75, 1);
    Printlist(test_list, "Insert at pos 1");
    assert(test_list->count == 7);  // Assert that the list count is 8 after insertion

    InsertAtPosition(test_list, 10, 6);
    Printlist(test_list, "Insert at pos 6");
    assert(test_list->count == 8);  // Assert that the list count is 9 after insertion

    InsertAtPosition(test_list, 15, 8);
    Printlist(test_list, "Insert at pos 8");
    assert(test_list->count == 9);  // Assert that the list count is 10 after insertion

    InsertAtPosition(test_list, 115, 2);
    Printlist(test_list, "Insert at pos 2");
    assert(test_list->count == 10);  // Assert that the list count is 11 after insertion

    assert(SearchElement(test_list, 36) == kRetCodeFound);
    assert(SearchElement(test_list, 15) == kRetCodeFound);
    assert(SearchElement(test_list, 77) == kRetCodeFound);
    assert(SearchElement(test_list, 0) == kRetCodeNotFound);
    assert(SearchElement(test_list, 20) == kRetCodeNotFound);

    DeleteAtBeginning(test_list);
    DeleteAtBeginning(test_list);
    DeleteAtBeginning(test_list);
    Printlist(test_list, "Delete at beginning");
    assert(test_list->count == 7);  // Assert that the list count is 8 after deletions

    InsertAtEnd(test_list, 46);
    Printlist(test_list, "46 inserted");
    assert(test_list->count == 8);  // Assert that the list count is 9 after insertion

    InsertAtEnd(test_list, 34);
    Printlist(test_list, "34 inserted");
    assert(test_list->count == 9);  // Assert that the list count is 10 after insertion

    InsertAtEnd(test_list, 67);
    Printlist(test_list, "67 inserted");
    assert(test_list->count == 10);  // Assert that the list count is 11 after insertion

    DeleteAtBeginning(test_list);
    DeleteAtBeginning(test_list);
    DeleteAtBeginning(test_list);
    DeleteAtBeginning(test_list);
    DeleteAtBeginning(test_list);
    Printlist(test_list, "Delete beginning");
    assert(test_list->count == 5);  // Assert that the list count is 6 after deletions

    InsertAtEnd(test_list, 78);
    InsertAtEnd(test_list, 234);
    InsertAtEnd(test_list, 768);
    Printlist(test_list, "Insert at end");
    assert(test_list->count == 8);  // Assert that the list count is 9 after insertions

    DeleteAtEnd(test_list);
    Printlist(test_list, "Delete end");
    assert(test_list->count == 7);  // Assert that the list count is 8 after deletion

    DeleteElement(test_list, 234);
    Printlist(test_list, "Delete 234");
    assert(test_list->count == 6);  // Assert that the list count is 7 after deletion

    DeleteElement(test_list, 46);
    Printlist(test_list, "Delete 46");
    assert(test_list->count == 5);  // Assert that the list count is 6 after deletion

    DeleteElement(test_list, 67);
    Printlist(test_list, "Delete 67");
    assert(test_list->count == 4);  // Assert that the list count is 5 after deletion

    DeleteElement(test_list, 34);
    Printlist(test_list, "Delete 34");
    assert(test_list->count == 3);  // Assert that the list count is 4 after deletion

    DeleteElement(test_list, 78);
    Printlist(test_list, "Delete 78");
    assert(test_list->count == 2);  // Assert that the list count is 3 after deletion

    List *merge_list = InitialiseList();
    InsertAtBeginning(merge_list, 99);
    InsertAtBeginning(merge_list, 89);
    InsertAtBeginning(test_list, 66);
    Printlist(merge_list, "After two insert at beginning merge_list");
    Printlist(test_list, "Before merge test_list");
    MergeList(merge_list, test_list);
    Printlist(merge_list, "Merged list");
    assert(merge_list->count == 5);  // Assert that the merged list count is 11

    FreeList(merge_list);

    return 0;
}
