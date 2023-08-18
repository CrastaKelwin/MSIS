#include <stdint.h>
#include <stdio.h>

void CheckNumChars(char *arr)
{
    int length = 0;
    int a_count = 0;
    int b_count = 0;
    int alphabet_count = 0;
    char a = ' ';
    char b = '\t';
    while (arr[length] != 0)
    {
        if (arr[length] == a)
        {
            a_count++;
        }
        else if (arr[length] == b)
        {
            b_count++;
        }
        else if ((arr[length] <= 'z' && arr[length] >= 'a') || (arr[length] <= 'Z' && arr[length] >= 'A'))
        {
            alphabet_count++;
        }
        length++;
    }
    printf("found %d numbers of spaces\n", a_count);
    printf("found %d numbers of tabs\n", b_count);
    printf("found %d numbers of alphabets\n", alphabet_count);
    printf("found %d numbers of other characters\n", length - (a_count + b_count + alphabet_count));
}

int main(void)
{
    char arr[] = "sdhhjhjd | ,/? jkds dhj\tj        ";
    CheckNumChars(arr);
    return 0;
}