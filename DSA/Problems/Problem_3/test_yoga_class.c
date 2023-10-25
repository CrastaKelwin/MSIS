#include "yoga.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define NUMBER_OF_BATCHES (2U)

void main()
{
    YogaBatch *batch[NUMBER_OF_BATCHES];

    for (int i = 0; i < NUMBER_OF_BATCHES; i++)
    {
        batch[i] = InitialiseBatch();
        assert(batch[i] != NULL);
    }

    AddParticipant(batch[0], "person 1", 10, 60, 100);
    AddParticipant(batch[0], "person 2", 20, 70, 110);
    AddParticipant(batch[0], "person 3", 30, 80, 125);
    AddParticipant(batch[0], "person 4", 40, 70, 90);
    AddParticipant(batch[0], "person 5", 50, 70, 110);
    AddParticipant(batch[0], "person 6", 60, 75, 185);
    AddParticipant(batch[0], "person 7", 70, 70, 165);
    AddParticipant(batch[0], "person 5", 80, 40, 110);
    AddParticipant(batch[0], "person 6", 75, 50, 185);
    AddParticipant(batch[0], "person 7", 46, 45, 165);

    AddParticipant(batch[1], "person 1", 54, 45, 130);
    AddParticipant(batch[1], "person 2", 32, 99, 184);
    AddParticipant(batch[1], "person 3", 43, 50, 199);
    AddParticipant(batch[1], "person 4", 22, 80, 180);
    AddParticipant(batch[1], "person 5", 27, 35, 178);
    AddParticipant(batch[1], "person 6", 30, 90, 187);
    AddParticipant(batch[1], "person 7", 32, 90, 167);
    AddParticipant(batch[1], "person 5", 34, 80, 145);
    AddParticipant(batch[1], "person 6", 42, 60, 169);
    AddParticipant(batch[1], "person 7", 40, 47, 170);

printf("*******************************************************\n");
    for (int i = 0; i < NUMBER_OF_BATCHES; i++)
    {
        printf("batch %d participant count = %d\n", i, GetParticipantCount(batch[i]));
        printf("batch %d obese count = %d\n", i, GetObeseCount(batch[i]));
        printf("batch %d underweight count = %d\n", i, GetUnderweightCount(batch[i]));
        PrintBatchDetails(batch[i], "");
        
printf("*******************************************************\n");
    }
    
    // UpdateHightWeight(batch[0],10,80,60);

    // printf("after update \n");

    // for (int i = 0; i < 1; i++)
    // {
    //     printf("batch %d participant count = %d\n", i, GetParticipantCount(batch[i]));
    //     printf("batch %d obese count = %d\n", i, GetObeseCount(batch[i]));
    //     printf("batch %d underweight count = %d\n", i, GetUnderweightCount(batch[i]));
    //     PrintBatchDetails(batch[i], "");
    // }
}