#include "array.h"
#include <assert.h>
#include <stdlib.h>
#include "split_array.h"

int main(void)
{
    Array *a = InitialiseArray(10);
    assert(a != NULL);
    assert(a->array_ptr != NULL);
    assert(a->current_size == 0);
    assert(a->total_size == 10);

    assert(InsertData(a, 10) == kRetCodeOk);
    assert(InsertData(NULL, 10) == kRetCodeBadParam);
    assert(InsertData(a, 20) == kRetCodeOk);

    assert(a->current_size == 2);

    assert(InsertData(a, 30) == kRetCodeOk);
    assert(InsertData(a, 40) == kRetCodeOk);
    assert(InsertData(a, 50) == kRetCodeOk);
    assert(InsertData(a, 60) == kRetCodeOk);
    assert(InsertData(a, 70) == kRetCodeOk);
    assert(InsertData(a, 80) == kRetCodeOk);
    assert(InsertData(a, 90) == kRetCodeOk);
    assert(InsertData(a, 100) == kRetCodeOk);

    assert(a->current_size == 10);

    DisplayArray(a);
    int splits =3;
    SplitArray *b = SplitArrayTo_N_Parts(a, splits);
    for (int i = 0; i < splits; i++)
    {
        DisplayArray(b->array_ptr[i]);
    }

    return 0;
}