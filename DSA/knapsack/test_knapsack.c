#include "knapsack.h"

void main(){
    KnapsackAddElement(25,5);
    KnapsackAddElement(12,2);
    KnapsackAddElement(6,3);
    KnapsackAddElement(24,6);
    KnapsackAddElement(21,6);
    KnapSackPrintElements();
    ResultElement *res =KnapsackSolution(18);
    KnapSackPrintResult(res);

}