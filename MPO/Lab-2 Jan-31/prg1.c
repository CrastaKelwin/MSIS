/*
--------------------------------
1. (i) Write a C program to search for a given element in a
matrix. The program should take a matrix and a target
element as input, and it should output whether the element
is present in the matrix or not.
(ii) Modify your code so that you convert the code into a
function called search().
 Signature of search() can be as below:
 int search(int mat[][], int rows, int cols, int
key).
 Let the search function return 0 on finding the key,
and return -1 if the key is not present in the
matrix. Write a suitable main function which invokes
search() and observe your results.

*/
#include <assert.h>
#include <stdio.h>
int search(int *mat, int rows, int cols, int key)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(*(mat+(i*3)+j)==key){
                return 0;
            }
        }
        
    }
    return -1;
}

void main(){
    int mat[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j]=i+j;
            printf("%d\t",mat[i][j]);
        }
        
            printf("\n");
    }
    assert(search((int*)mat,3,3,4)==0);
    assert(search((int*)mat,3,3,9)==-1);
    assert(search((int*)mat,3,3,5)==-1);
    assert(search((int*)mat,3,3,1)==0);
}