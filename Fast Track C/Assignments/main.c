#include <stdio.h>
#include <stdlib.h>
#include "practice_problems.h"
#include <assert.h>
#include <math.h>

int main()
{
    for (char i = 'A'; i <= 'Z'; i++)
    {
        // printf("in %c out %c\n",i,ConvertToLowerCase(i));
        assert(ConvertToLowerCase(i) == (i - 'A' + 'a'));
    }

    assert(CharacterDifference('A', 'B') == 0);
    assert(CharacterDifference('A', 'Z') == 24);
    assert(CharacterDifference('A', 's') == 17);
    assert(CharacterDifference('Z', 'A') == 24);

    assert(CelsiusToFaranheit(0) == 32);
    assert(CelsiusToFaranheit(25) == 77);
    assert(CelsiusToFaranheit(100) == 212);
    assert(CelsiusToFaranheit(-100) == -148);

    assert(IsOdd(-100) == 0);
    assert(IsOdd(-3) == 1);
    assert(IsOdd(3) == 1);
    assert(IsOdd(300) == 0);

    assert(IsLeapYear(2000) == 1);
    assert(IsLeapYear(2023) == 0);
    assert(IsLeapYear(2024) == 1);
    assert(IsLeapYear(2100) == 0);
    assert(IsLeapYear(2400) == 1);
    assert(IsLeapYear(3000) == 0);

    assert(PowerOfTwo(0) == 1);
    assert(PowerOfTwo(2) == 4);
    assert(PowerOfTwo(63) == ((uint64_t)0x1 << 63));

    assert(SumOfDigits(12345) == 15);
    assert(SumOfDigits(-12345) == 15);
    assert(SumOfDigits(2345) == 14);
    assert(SumOfDigits(1111111111) == 10);

    assert(Reverse(125) == 521);
    assert(Reverse(-45689) == -98654);

    assert(OccuranceOfDigit(10000, 0) == 4);
    assert(OccuranceOfDigit(1546586, 4) == 1);

    assert(IsNumberPalindrome(123456) == 0);
    assert(IsNumberPalindrome(65656) == 1);
    assert(IsNumberPalindrome(56788765) == 1);

    GeneratePrimeNumbers(500);

    assert(SumOfSeries(5) == 12345);
    assert(SumOfSeries(15) == 123456790123455);

    assert(IsArmstrong(153) == 1);
    assert(IsArmstrong(200) == 0);
    assert(IsArmstrong(1634) == 1);
    assert(IsArmstrong(1654) == 0);
    assert(IsArmstrong(371) == 1);

    assert(IsAmicablePair(220, 284) == 1);
    assert(IsAmicablePair(1184, 1210) == 1);

    assert(Operation(1, 4, kOperationSum) == 5);
    assert(Operation(20, 30, kOperationDifference) == -10);
    assert(Operation(20, 30, kOprationProduct) == 600);

    assert(CalcVolume(10, 0, 0, 0, 0, kVolumeCube) == 1000);
    assert(CalcVolume(0, 5, 4, 6, 0, kVolumeCuboid) == 120);
    assert(CalcVolume(0, 0, 0, 0, 5, kVolumeSphere) == 523);
    assert(CalcVolume(0, 0, 0, 10, 5, kVolumeCylinder) == 785);
    assert(CalcVolume(0, 0, 0, 10, 5, kVolumeCone) == 261);

    assert(ElectricityCharge(50) == 250);
    assert(ElectricityCharge(250) == (1000 + 350));
    assert(ElectricityCharge(550) == (1000 + 700 + 2500));

    sketch(5);

    sketch_tri(7);

    Print2DigitWithSum9();

    assert(Powerofn(2, 10) == 1024);
    assert(Powerofn(5, 10) == 9765625);

    assert(Factorial(10) == 3628800);
    assert(Factorial(7) == 5040);

    assert(CONCAT_INT(12, 56) == 1256);

    assert(SQUARE_OF(5) == 25);

    int arr[10] = {2, 5, 3, 77, 32, 67, 5, 8, 45, 56};
    SortNumbers(arr, sizeof(arr) / sizeof(arr[0]), kSortDescending);
    SortNumbers(arr, sizeof(arr) / sizeof(arr[0]), kSortAscending);

    int k = 5, g = 10;
    swap(&k, &g);
    assert(k == 10 && g == 5);

    int max, min;
    find_max_min(arr, sizeof(arr) / sizeof(arr[0]), &max, &min);
    assert(max == 77 && min == 2);

    int a[] = {1, 2, 5, 6, 3};
    int b[] = {10, 5, 23, 8, 6};
    int res[(sizeof(a) / sizeof(a[0])) + sizeof(b) / sizeof(b[0])];
    int res_size = UnionOfSets(a, (sizeof(a) / sizeof(a[0])), b, (sizeof(b) / sizeof(b[0])), res, (sizeof(a) / sizeof(a[0])) + sizeof(b) / sizeof(b[0]));
    printf("Union \n");
    for (int i = 0; i < res_size; i++)
    {
        printf("%d ", res[i]);
    }
    res_size = IntersectionOfSets(a, (sizeof(a) / sizeof(a[0])), b, (sizeof(b) / sizeof(b[0])), res, (sizeof(a) / sizeof(a[0])) + sizeof(b) / sizeof(b[0]));
    printf("IntersectionOfSets \n");
    for (int i = 0; i < res_size; i++)
    {
        printf("%d ", res[i]);
    }
    res_size = DifferenceOfSets(a, (sizeof(a) / sizeof(a[0])), b, (sizeof(b) / sizeof(b[0])), res, (sizeof(a) / sizeof(a[0])) + sizeof(b) / sizeof(b[0]));
    printf("Difference A-B \n");
    for (int i = 0; i < res_size; i++)
    {
        printf("%d ", res[i]);
    }
    res_size = DifferenceOfSets(b, (sizeof(b) / sizeof(b[0])), a, (sizeof(a) / sizeof(a[0])), res, (sizeof(a) / sizeof(a[0])) + sizeof(b) / sizeof(b[0]));
    printf("Difference B-A \n");
    for (int i = 0; i < res_size; i++)
    {
        printf("%d ", res[i]);
    }
    int duplicate[10] = {1, 1, 1, 1, 1, 2, 7, 4, 1, 6};
    res_size = RemoveDuplicate(duplicate, 10);
    printf("\nDuplicate \n");
    for (int i = 0; i < res_size; i++)
    {
        printf("%d ", duplicate[i]);
    }
    return 0;
}
/* Skipped
day 1 ) 10
day 3 ) 1 2 8 11

*/
