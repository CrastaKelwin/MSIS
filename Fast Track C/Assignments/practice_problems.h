#ifndef __PP_H_
#define __PP_H_
#include <stdint.h>
#define CONCAT_INT(x, y) (x##y)
#define SQUARE_OF(x) (x * x)
char ConvertToLowerCase(char c);
float AreaOfCircle(float radius);
int CharacterDifference(char char_1, char char_2);
int CelsiusToFaranheit(int celsius);
int IsOdd(int number);
int IsLeapYear(int year);
uint64_t PowerOfTwo(int n);
int SumOfDigits(int num);
int IsNumberPalindrome(int num);
int Reverse(int num);
int OccuranceOfDigit(int num, int digit);
void GeneratePrimeNumbers(int num);
uint64_t SumOfSeries(uint64_t num);
int IsAmicablePair(int num_1, int num_2);
int ElectricityCharge(int units);
void sketch(int n);
void sketch_tri(int n);
void Print2DigitWithSum9(void);
int Powerofn(int x, int y);
int Factorial(int n);
int IsArmstrong(int num);
int Operation(int num_1, int num_2, int op);
enum
{
    kOperationSum = 1,
    kOperationDifference,
    kOprationProduct
};
enum
{
    kVolumeCube = 1,
    kVolumeCuboid,
    kVolumeSphere,
    kVolumeCylinder,
    kVolumeCone
};
enum
{
    kSortAscending = 1,
    kSortDescending
};
void SortNumbers(int *arr, int size, int type);
void swap(int *a, int *b);
int find_max_min(int arr[], int size, int *max, int *min);
int UnionOfSets(int a[], int size_a, int b[], int size_b, int res[], int size_res);
int DifferenceOfSets(int a[], int size_a, int b[], int size_b, int res[], int act_res_size);
int CalcVolume(int a, int l, int b, int h, int r, int type);
int IntersectionOfSets(int a[], int size_a, int b[], int size_b, int res[], int act_res_size);
int RemoveDuplicate(int arr[], int size);
#endif //__PP_H_
