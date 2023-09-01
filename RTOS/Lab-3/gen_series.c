#include <stdio.h>

int main()
{
    for (int i = 0; i < 200; i++)
    {
        if (i & 0x1)
        {
            printf("%d\t", i);
        }
    }
    printf("\n");
    return 0;
}