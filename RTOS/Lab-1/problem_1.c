#include <stdio.h>

int SumOfNnumbers(int n)
{
    return (n*(n+1))/2;
}

int main(void){
    int input=0;
    printf("Enter N\n");
    scanf("%d",&input);
    printf("num of first %d numbers is %d\n", input, SumOfNnumbers(input));
    return 0;
}