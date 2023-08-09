#include <math.h>
#include "practice_problems.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
// Convert upper to lower case
char ConvertToLowerCase(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c = c - 'A' + 'a';
    }
    return c;
}

float AreaOfCircle(float radius)
{
    return (M_PI * radius * radius);
}

int CharacterDifference(char char_1, char char_2)
{
    int letters = 0;
    letters = (ConvertToLowerCase(char_1) - ConvertToLowerCase(char_2));
    letters = letters < 0 ? -letters : letters;
    return letters - 1;
}

int CelsiusToFaranheit(int celsius)
{
    return ((celsius * (9.0 / 5)) + 32);
}

int IsOdd(int number)
{
    return (number & 0x01);
}
int IsLeapYear(int year)
{
    return ((year % 400 == 0) ? 1 : ((year % 100 == 0) ? 0 : (year % 4 == 0) ? 1
                                                                             : 0));
}

uint64_t PowerOfTwo(int n)
{
    return ((uint64_t)0x01 << n);
}
int sum(int a, int b)
{
    return (a + b);
}

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
int Reverse(int num)
{
    int digits = 0;
    int sign = 0;
    if (num < 0)
    {
        num = -num;
        sign = 1;
    }
    int numcpy = num;
    while (num > 0)
    {
        digits++;
        num /= 10;
    }
    int multiplier = numcpy % 10;
    numcpy /= 10;
    for (int i = 1; i < digits; i++)
    {
        multiplier *= 10;
        multiplier += numcpy % 10;
        numcpy /= 10;
    }
    if (sign)
        multiplier = -multiplier;
    return multiplier;
}

int OccuranceOfDigit(int num, int digit)
{
    if (digit < 0 || digit > 9)
    {
        return 0;
    }

    int occurance = 0;
    if (num < 0)
        num = -num;
    while (num > 0)
    {
        if (num % 10 == digit)
        {
            occurance++;
        }
        num /= 10;
    }
    return occurance;
}
int IsNumberPalindrome(int num)
{
    return (Reverse(num) == num);
}

void GeneratePrimeNumbers(int num)
{
    bool is_prime[1000];
    memset(is_prime, 1, sizeof(is_prime));
    for (int p = 2; p * p <= num; p++)
    {
        if (is_prime[p] == true)
        {
            for (int i = p * p; i <= num; i += p)
            {
                is_prime[i] = false;
            }
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= num; p++)
    {
        if (is_prime[p])
        {
            printf("%d ", p);
        }
    }
    printf("\n");
}

uint64_t SumOfSeries(uint64_t num)
{
    uint64_t sum = 0;
    for (uint64_t i = 1; i <= num; i++)
    {
        uint64_t value = 0;
        for (uint64_t j = 0; j < i; j++)
        {
            value += pow(10, j);
        }
        printf("%llu ", (unsigned long long)value);
        sum += value;
    }
    printf("sum = %llu\n", (unsigned long long)sum);
    return sum;
}

int IsArmstrong(int num)
{
    int digits = 0;
    int sum = 0;
    if (num < 0)
        num = -num;
    int numcpy = num;

    while (num > 0)
    {
        digits++;
        num /= 10;
    }
    num = numcpy;
    while (num > 0)
    {
        sum += pow((num % 10), digits);
        num /= 10;
    }
    return (sum == numcpy);
}
int IsAmicablePair(int num_1, int num_2)
{
    int sum_1 = 0, sum_2 = 0;
    for (int i = 1; i <= num_1 / 2; i++)
    {
        if (num_1 % i == 0)
        {
            sum_1 = sum_1 + i;
        }
    }
    for (int i = 1; i <= num_2 / 2; i++)
    {
        if (num_2 % i == 0)
        {
            sum_2 += i;
        }
    }
    return ((sum_1 == num_2) && (num_1 == sum_2));
}

int Operation(int num_1, int num_2, int op)
{
    switch (op)
    {
    case kOperationSum:
        return num_1 + num_2;
        break;
    case kOperationDifference:
        return num_1 - num_2;
        break;
    case kOprationProduct:
        return num_1 * num_2;
        break;
    default:
        printf("invalid_input\n");
    }
    return 0;
}
int CalcVolume(int a, int l, int b, int h, int r, int type)
{
    switch (type)
    {
    case kVolumeCube:
        return (a * a * a);
    case kVolumeCuboid:
        return (l * b * h);
    case kVolumeSphere:
        return ((4.0 / 3) * M_PI * r * r * r);
    case kVolumeCylinder:
        return (M_PI * r * r * h);
    case kVolumeCone:
        return ((1 / 3.0) * M_PI * r * r * h);
    default:
        return 0;
    }
}
int ElectricityCharge(int units)
{
    int charge = 0;
    if (units > 200)
    {
        charge = 200 * 5;
        units -= 200;
        if (units > 100)
        {
            charge = charge + (100 * 7);
            units -= 100;
            if (units > 0)
            {
                charge = charge + (units * 10);
            }
        }
        else
        {
            charge = charge + (units * 7);
        }
        printf("charge %d\n", charge);
        return charge;
    }
    else
    {
        return units * 5;
    }
}

void sketch(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
            {
                printf("*");
            }
            else
            {

                printf(" ");
            }
        }
        printf("\n");
    }
}
void sketch_tri(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                printf("*");
            }
            else
            {

                printf(" ");
            }
        }
        printf("\n");
    }
}

void Print2DigitWithSum9(void)
{
    /*for(int i =10;i<100;i++)
    {
        if((i%10)+((i/10)%10)==9)
        {
            printf("%d, ",i);
        }
    }*/

    for (int i = 2; i < 11; i++)
    {
        printf("%d, ", i * 9);
    }
    printf("\n");
}

int Powerofn(int x, int y)
{
    int power = 0;
    if (y == 0)
    {
        return 1;
    }
    power = Powerofn(x, y - 1) * x;
    printf("%d\n", power);
    return power;
}
int Factorial(int n)
{
    int factorial = 0;
    if (n == 0)
    {
        return 1;
    }
    factorial = Factorial(n - 1) * n;
    printf("%d\n", factorial);
    return factorial;
}
void SortNumbers(int *arr, int size, int type)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            switch (type)
            {
            case kSortAscending:
                if (arr[i] < arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                break;
            case kSortDescending:
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                break;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_max_min(int arr[], int size, int *max, int *min)
{
    *max = arr[0];
    *min = arr[0];
    for (int i = 0; i < size; i++)
    {
        // max
        if (*max < arr[i])
        {
            *max = arr[i];
        }
        // min
        if (*min > arr[i])
        {
            *min = arr[i];
        }
    }
}
int UnionOfSets(int a[], int size_a, int b[], int size_b, int res[], int act_res_size)
{
    printf("\n");
    int size_res = 0;
    memcpy(res, a, size_a * sizeof(int));
    size_res = size_a;
    for (int i = 0; i < size_b; i++)
    {
        int element_exist = 0;
        for (int j = 0; j < size_res; j++)
        {
            if (b[i] == res[j])
            {
                element_exist = 1;
                break;
            }
        }
        if (!element_exist)
        {
            if (size_res > act_res_size)
            {
                return 0;
            }
            res[size_res] = b[i];
            size_res++;
        }
    }
    return size_res;
}

int IntersectionOfSets(int a[], int size_a, int b[], int size_b, int res[], int act_res_size)
{
    printf("\n");
    int size_res = 0;
    memset(res, 0, act_res_size * sizeof(res[0]));
    for (int i = 0; i < size_b; i++)
    {
        for (int j = 0; j < size_a; j++)
        {
            if (b[i] == a[j])
            {
                if (size_res > act_res_size)
                {
                    return 0;
                }
                res[size_res] = b[i];
                size_res++;
                break;
            }
        }
    }
    return size_res;
}

int DifferenceOfSets(int a[], int size_a, int b[], int size_b, int res[], int act_res_size)
{
    printf("\n");
    int size_res = 0;
    memcpy(res, a, size_a * sizeof(int));
    size_res = size_a;
    for (int i = 0; i < size_b; i++)
    {
        for (int j = 0; j < size_res; j++)
        {
            if (b[i] == res[j])
            {
                for (int k = j; k < size_res - 1; k++)
                {
                    res[k] = res[k + 1];
                }
                size_res--;
                break;
            }
        }
    }
    return size_res;
}

int RemoveDuplicate(int arr[], int size)
{
    int res_size = size;
    for (int i = 0; i < res_size; i++)
    {
        for (int j = (i + 1); j < res_size; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < (res_size - 1); k++)
                {
                    arr[k] = arr[k + 1];
                }
                res_size--;
                j--;
            }
        }
    }
    return res_size;
}
