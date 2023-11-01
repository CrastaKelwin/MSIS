#include <stdio.h>

// function to swap elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// function to find the partition position
int partition(int array[], int lb, int ub) {
    // select the rightmost element as pivot
    int pivot = array[lb];
    while (lb <= ub) {
        while (array[lb] < pivot) {
            lb++;
        }
        while (array[ub] > pivot) {
            ub--;
        }
        if (lb <= ub) {
            swap(&array[lb], &array[ub]);
            lb++;
            ub--;
        }
    }
    // return the partition point
    return lb;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

// function to print array elements
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// main function
int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6};

    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted Array\n");
    printArray(data, n);

    // perform quicksort on data
    quickSort(data, 0, n - 1);

    printf("Sorted array in ascending order: \n");
    printArray(data, n);
    return 0;
}
