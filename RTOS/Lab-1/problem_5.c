#include <stdint.h>
#include <stdio.h>

int Scale(int *arr, int len, int factor)
{
    if (arr <= 0)
        return 1;
    for (int i = 0; i < len; i++)
    {
        arr[i] *= factor;
    }
    return 0;
}

int Display(int *arr, int len)
{
    if (arr <= 0)
        return 1;
    printf("\n[");
    for (int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("]\n");
}

int main(void)
{
    int arr[] = {2, 45, 76, 4, 2, 5};
    Display(arr,sizeof(arr)/sizeof(arr[0]));
     Scale(arr, sizeof(arr)/sizeof(arr[0]),2);
    Display(arr,sizeof(arr)/sizeof(arr[0]));
 }