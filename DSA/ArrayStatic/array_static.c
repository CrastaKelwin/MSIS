#include "array_static.h"

Array InitializeArray(int size)
{
    Array var;
    var.c_size = 0;
    var.t_size = size <= MAX_SIZE && size > 0 ? size : MAX_SIZE;
    return var;
}

Array InsertData(Array array, int data)
{
    if (array.c_size < array.t_size)
    {
        array.array[array.c_size] = data;
        array.c_size++;
    }
    return array;
}

int SearchData(Array array, int data)
{
    for (int i = 0; i < array.c_size; i++)
    {
        if (array.array[i] == data)
        {
            return i;
        }
    }
    return SEARCH_RESULT_NOT_FOUND;
}