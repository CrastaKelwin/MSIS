#include "insertion_sort.h"

void InserstionSort(int *array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int key = array[i];

        while (j >= 0 && key < array[j])
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}