#include <stdint.h>
#include <stdio.h>

int GetStrLength(char *arr)
{
    int length= 0;
    while(arr[length]!=0){length++;}
    return length;
}

int main(void)
{
    char arr[] = "54564545";
    printf("String length = %d\n",GetStrLength(arr));
    return 0;
 }