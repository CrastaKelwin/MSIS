#include <stdio.h>
#include <assert.h>
#include "array_static.h"

int main(void)
{
    Array ar = InitializeArray(-10);
    assert(ar.t_size == MAX_SIZE);
    ar = InsertData(ar, 24);
    ar = InsertData(ar, 56);
    assert(ar.c_size == 2);
    assert(ar.array[ar.c_size-1] == 56);
    assert(SearchData(ar, 56) == 1);
    assert(SearchData(ar, 40) == SEARCH_RESULT_NOT_FOUND);
    return 0;
}