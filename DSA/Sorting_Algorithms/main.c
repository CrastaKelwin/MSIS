#include "bubble_sort.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "selection_sort.h"
#include "insertion_sort.h"

#include <time.h>

int main(void)
{
    int input_test_data[] = {9, 5, 3, 6, 4, 1, 0, 6, 4, 3};
    printf("Bubble Sort\n");
    printf("%ld\n",clock());
    BubbleSort(input_test_data, sizeof(input_test_data) / sizeof(input_test_data[0]));
    printf("%ld\n",clock());
    for (int i = 0; i < sizeof(input_test_data) / sizeof(input_test_data[0]); i++)
    {
        printf("%d\t", input_test_data[i]);
    }
    printf("\n");
    memcpy(input_test_data, (int []){9, 5, 3, 6, 4, 1, 0, 6, 4, 3}, sizeof(input_test_data));

    printf("Eff Bubble Sort\n");
    printf("%ld\n",clock());
    BubbleSortEfficient(input_test_data, sizeof(input_test_data) / sizeof(input_test_data[0]));
    printf("%ld\n",clock());
    for (int i = 0; i < sizeof(input_test_data) / sizeof(input_test_data[0]); i++)
    {
        printf("%d\t", input_test_data[i]);
    }
    printf("\n");
    memcpy(input_test_data, (int []){9, 5, 3, 6, 4, 1, 0, 6, 4, 3}, sizeof(input_test_data));
    for (int i = 0; i < sizeof(input_test_data) / sizeof(input_test_data[0]); i++)
    {
        printf("%d\t", input_test_data[i]);
    }
    printf("\n");
    printf("Selection Sort\n");
    printf("%ld\n",clock());
    SelectionSort(input_test_data, sizeof(input_test_data) / sizeof(input_test_data[0]));
    printf("%ld\n",clock());
    for (int i = 0; i < sizeof(input_test_data) / sizeof(input_test_data[0]); i++)
    {
        printf("%d\t", input_test_data[i]);
    }
    printf("\n");

        memcpy(input_test_data, (int []){9, 5, 3, 6, 4, 1, 0, 6, 4, 3}, sizeof(input_test_data));

    printf("Insertion Sort\n");
    printf("%ld\n",clock());
    InserstionSort(input_test_data, sizeof(input_test_data) / sizeof(input_test_data[0]));
    printf("%ld\n",clock());
    for (int i = 0; i < sizeof(input_test_data) / sizeof(input_test_data[0]); i++)
    {
        printf("%d\t", input_test_data[i]);
    }
    printf("\n");
}