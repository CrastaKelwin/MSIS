#include <stdint.h>
#include <stdio.h>

int Smallest(int *arr, int len)
{
    int smallest = 0;
    if (arr <= 0)
        return 0;
    smallest = arr[0];
    for (int i = 1; i < len; i++)
    {
        if(smallest>arr[i])
        {
            smallest = arr[i];
        }
    }
    
    return smallest;
}

int main(void)
{
    printf("Smallest value %d\n", Smallest((int []){2,45,76,4,2,5},6));
    printf("Smallest value %d\n", Smallest((int []){2,0,76,4,2,5},6));
    printf("Smallest value %d\n", Smallest((int []){25,56,76,48,25,57},6));
    printf("Smallest value %d\n", Smallest((int []){32,495,766,48,23,58},6));
}