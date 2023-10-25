#ifndef _KNAPSACK_H_
#define _KNAPSACK_H_

typedef struct _element
{
    float weight;
    float profit;
    float profit_per_weight;
    struct _element *next;
} Element;

typedef struct _result_element
{
    Element *element;
    float selected_weight;
    struct _result_element *next;
} ResultElement;

ResultElement *KnapsackSolution(float size);
int KnapsackAddElement(float profit, float weight);
void KnapSackPrintElements();
void KnapSackPrintResult(ResultElement *start_element);

#endif //_KNAPSACK_H_