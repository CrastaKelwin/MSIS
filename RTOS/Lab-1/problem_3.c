#include <stdint.h>
#include <stdio.h>

int SumOfDigits(int num)
{
    int sum = 0;
    if (num < 0)
        num = -num;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(void)
{
    printf("%d\n",SumOfDigits(435678));
    printf("%d\n",SumOfDigits(430078));
    printf("%d\n",SumOfDigits(4301258));
    printf("%d\n",SumOfDigits(48521100));
}