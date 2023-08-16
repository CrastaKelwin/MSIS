#include "split_array.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

SplitArray *SplitArrayTo_N_Parts(Array *array, int16_t no_of_splits)
{
    if (array == NULL || array->array_ptr == NULL)
    {
        return NULL;
    }
    int32_t min_split_size = array->current_size / no_of_splits;
    SplitArray *sp_arr = malloc(sizeof(SplitArray));
    sp_arr->array_ptr = malloc(sizeof(Array)*no_of_splits);
    if (sp_arr == NULL)
    {
        return NULL;
    }
    sp_arr->total_size = no_of_splits; //  this may lead to freeing all structure at ones when we all free on first struct member

    int i = 0;
    for (i = 0; i < no_of_splits - 1; i++)
    {
        sp_arr->array_ptr[i] = InitialiseArray(min_split_size);
        for (int j = 0; j < min_split_size; j++)
        {
            InsertData(sp_arr->array_ptr[i], array->array_ptr[(i * min_split_size) + j]);
        }
    }
    sp_arr->array_ptr[i] = InitialiseArray(array->current_size - (min_split_size * (no_of_splits - 1)));

    printf("rem %d \n", (array->current_size - (min_split_size * (no_of_splits - 1))));

    for (int j = 0; j < (array->current_size - (min_split_size * (no_of_splits - 1))); j++)
    {
        assert(InsertData(sp_arr->array_ptr[i], array->array_ptr[((no_of_splits - 1) * min_split_size) + j]) == kRetCodeOk);
    }
    return sp_arr;
}