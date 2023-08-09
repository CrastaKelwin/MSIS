#ifndef ARRAY_STATIC_H
#define ARRAY_STATIC_H

#define MAX_SIZE (20)

struct _array_
{
    int array[MAX_SIZE];
    int c_size;
    int t_size;
};

#define SEARCH_RESULT_NOT_FOUND (-1)

typedef struct _array_ Array;

Array InitializeArray(int size);
Array InsertData(Array array, int data);
int SearchData(Array array, int data);
#endif