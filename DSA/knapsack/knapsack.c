#include "knapsack.h"
#include <stdlib.h>
#include <stdio.h>
void PrintEement(Element *p);
static Element *start_element = NULL;
ResultElement *KnapsackSolution(float size)
{
    // printf("--------------------solution ---------------\n");
    Element *p = start_element;
    ResultElement *start_result = NULL;
    ResultElement *loop_result = NULL;
    while (size > 0 && p != NULL)
    {
        ResultElement *result_next = (ResultElement *)malloc(sizeof(ResultElement));
        result_next->element = p;
        result_next->selected_weight = 0;
        result_next->next = NULL;
        if (start_result == NULL)
        {
            start_result = loop_result = result_next;
        }
        else
        {
            loop_result->next = result_next;
            loop_result = result_next;
        }
        result_next->element = p;
        if (size >= p->weight)
        {
            result_next->selected_weight = p->weight;
            size -= p->weight;
        }
        else
        {
            result_next->selected_weight = size;
            size = 0;
        }
        if (size <= 0)
        {
            return start_result;
        }
        p = p->next;
    }
}

int KnapsackAddElement(float profit, float weight)
{
    Element *p = start_element;
    Element *new_element = (Element *)malloc(sizeof(Element));
    new_element->profit = profit;
    new_element->weight = weight;
    new_element->profit_per_weight = profit / weight;
    new_element->next = NULL;
    if (start_element == NULL || start_element->profit_per_weight <= new_element->profit_per_weight)
    {
        new_element->next = start_element;
        start_element = new_element;
    }
    else
    {
        Element *current = start_element;
        /* Locate the node before the point of insertion
         */
        while (current->next != NULL && current->next->profit_per_weight > new_element->profit_per_weight)
        {
            current = current->next;
        }
        new_element->next = current->next;
        current->next = new_element;
    }
    return 0;
}
void PrintEement(Element *p)
{
    printf("p %f , w %f, p/w %f\n", p->profit, p->weight, p->profit_per_weight);
}

void KnapSackPrintElements()
{
    Element *p = start_element;
    while (p != NULL)
    {
        PrintEement(p);
        p = p->next;
    }
}

void KnapSackPrintResult(ResultElement *start)
{
    ResultElement *p = start;
    printf("printing result\n");
    while (p != NULL)
    {
        printf("Weight %f, ", p->selected_weight);
        PrintEement(p->element);
        p = p->next;
    }
}