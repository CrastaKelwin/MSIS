#include "selection_sort.h"

void SelectionSort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i; j < size; j++)
        {
            if (array[min_index] > array[j])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = array[min_index];
            array[min_index] = array[i];
            array[i] = temp;
        }
    }
}