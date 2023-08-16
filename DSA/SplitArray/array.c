#include "array.h"
#include <stdlib.h>
#include <stdio.h>

Array *InitialiseArray(int16_t size)
{
    if (size > 0)
    {
        Array *arr = malloc(sizeof(Array));

        if (arr == NULL)
        {
            return NULL;
        }
        arr->array_ptr = malloc(sizeof(int32_t) * size);
        if (arr->array_ptr == NULL)
        {
            return NULL;
        }
        arr->current_size = 0;
        arr->total_size = size;
        return arr;
    }
    return NULL;
}

RetCode InsertData(Array *array, int32_t data)
{
    if (array == NULL)
    {
        printf ("null\n");
        return kRetCodeBadParam;
    }
    if (array->current_size == array->total_size)
    {
        printf ("eq\n");
        return kRetCodeOutOfMem;
    }
    array->array_ptr[array->current_size] = data;
    array->current_size++;
    return kRetCodeOk;
}

RetCode DeleteArray(Array *arr)
{
    if (arr == NULL)
    {
        return kRetCodeBadParam;
    }
    if (arr->array_ptr != NULL)
    {
        free(arr->array_ptr);
    }
    free(arr);
    return kRetCodeOk;
}

RetCode DisplayArray(Array *ar)
{
    if (ar == NULL)
    {
        return kRetCodeBadParam;
    }
    printf("\n Array : %lu, ",(uint64_t)ar);
    for (int i = 0; i < ar->current_size; i++)
    {
        printf("%d ", ar->array_ptr[i]);
    }
    printf(", c_size %d, t_size %d \n", ar->current_size, ar->total_size);
    return kRetCodeOk;
}