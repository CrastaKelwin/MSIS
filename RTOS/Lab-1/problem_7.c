#include <stdint.h>
#include <stdio.h>

void CheckNumChars(char *arr, char a, char b)
{
    int length = 0;
    int a_count = 0;
    int b_count = 0;
    while (arr[length] != 0)
    {
        if (arr[length] == a)
        {
            a_count++;
        }

        if (arr[length] == b)
        {
            b_count++;
        }
        length++;
    }
    printf("found %d numbers of %c characters\n", a_count, a);
    printf("found %d numbers of %c characters\n", b_count, b);
}

int main(void)
{
    char arr[] = "yeriuweytrtweui";
    CheckNumChars(arr, 'e', 'y');
    return 0;
}