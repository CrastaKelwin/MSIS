#include <stdint.h>
#include <stdio.h>
#include <string.h>

void CheckNumChars(char *arr)
{
    int length = 0;
    int a_count = 0;
    int b_count = 0;
    int c_count = 0;
    int alphabet_count = 0;
    char a = ' ';
    char b = '\t';
    char c = '\n';
    char new_str[100];
    int new_str_length=0;
    memset(new_str, 0, sizeof(new_str));
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
        else if (arr[length] == c)
        {
            c_count++;
        }
        else if ((arr[length] <= 'z' && arr[length] >= 'a') || (arr[length] <= 'Z' && arr[length] >= 'A'))
        {
            alphabet_count++;
            new_str[new_str_length] = arr[length];
            new_str_length++;
        }
        length++;
    }

    printf("string length %d \n", length);
    printf("found %d numbers of spaces\n", a_count);
    printf("found %d numbers of tabs\n", b_count);
    printf("found %d numbers of newlines\n", c_count);
    printf("found %d numbers of alphabets\n", alphabet_count);
    printf("found %d numbers of other characters\n", length - (a_count + b_count + c_count +alphabet_count));

    printf("New string %s \n", new_str);
}

int main(void)
{
    int length = 0;
    char str[100];
    memset(str, 0, sizeof(str));
    printf("Enter the number of characters you want to enter\n");
    scanf("%d\n", &length);
    if (length > 100)
    {
        printf("Value cant be larger than 100\n");
        return 0;
    }
    int i = 0;
    while (i < length)
    {
        str[i] = getchar();
        i++;
    }
    printf("\nInput String is %s\n", str);
    CheckNumChars(str);
    return 0;
}