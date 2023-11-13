#include "yoga.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BMI_UNDERWEIGHT_LEVEL (18.5)
#define BMI_OBESE_LEVEL (30.0)
static int AssignParticipantID(YogaBatch *batch)
{
    batch->participant_id_max++;
    return batch->participant_id_max;
}
static float GetBMI(float weight_kg, float height_cm)
{
    return (weight_kg * 10000 / (height_cm * height_cm));
}

static Participant *GetParticipant(char *name, int age, float weight_kg,
                                   float height_cm)
{
    Participant *participant = (Participant *)malloc(sizeof(Participant));
    if (participant != NULL)
    {
        strcpy(participant->name, name);
        participant->age = age;
        participant->height_cm = height_cm;
        participant->weight_kg = weight_kg;
        participant->bmi = GetBMI(weight_kg, height_cm);
        participant->next = NULL;
    }
    return participant;
}
YogaBatch *InitialiseBatch()
{
    YogaBatch *batch = (YogaBatch *)malloc(sizeof(YogaBatch));
    if (batch != NULL)
    {
        batch->head = batch->tail = NULL;
        batch->participant_count = batch->obese = batch->under_weight = 0;
    }
    return batch;
}

int AddParticipant(YogaBatch *batch, char *name, int age, float weight_kg,
                   float height_cm)
{
    if (batch != NULL)
    {
        Participant *new_participant = GetParticipant(name, age, weight_kg, height_cm);
        if (new_participant)
        {
            new_participant->participant_id = AssignParticipantID(batch);
            if (batch->participant_count == 0)
            {
                batch->head = batch->tail = new_participant;
            }
            else
            {
                if (new_participant->bmi <= batch->head->bmi)
                {
                    // insert at start
                    new_participant->next = batch->head;
                    batch->head = new_participant;
                }
                else if (new_participant->bmi >= batch->tail->bmi)
                {
                    // insert at end
                    batch->tail->next = new_participant;
                    batch->tail = new_participant;
                }
                else
                {
                    Participant *node;
                    Participant *prev_node;
                    for (node = batch->head; node != NULL; node = node->next)
                    {
                        if (node->bmi > new_participant->bmi) //
                        {
                            new_participant->next = node;
                            prev_node->next = new_participant;
                            break;
                        }
                        prev_node = node;
                    }
                }
            }
            if (new_participant->bmi > BMI_OBESE_LEVEL)
            {
                batch->obese++;
            }
            else if (new_participant->bmi < BMI_UNDERWEIGHT_LEVEL)
            {
                batch->under_weight++;
            }
            batch->participant_count++;
            return new_participant->participant_id;
        }
    }
    return -1;
}

void PrintBatchDetails(YogaBatch *list, const char *test_msg)
{
    if (list)
    {
        // printf("%s, head %p, tail %p List Elements %d : [ ", test_msg, list->head, list->tail, list->count);
        for (Participant *temp = list->head; temp != NULL; temp = temp->next)
        {
            printf("participant name: %s, Age:%d, weight :%f, height :%f BMI: %f , id %d \n", temp->name, temp->age, temp->weight_kg, temp->height_cm, temp->bmi, temp->participant_id);
        }
        // printf("]\n");
    }
}

int GetParticipantCount(YogaBatch *batch) { return batch->participant_count; }
int GetObeseCount(YogaBatch *batch) { return batch->obese; }
int GetUnderweightCount(YogaBatch *batch) { return batch->under_weight; }

int AddUpdateParticipant(YogaBatch *batch, Participant *new_participant)
{
    if (batch != NULL)
    {
        if (new_participant)
        {
            new_participant->bmi = GetBMI(new_participant->weight_kg, new_participant->height_cm);
            if (batch->participant_count == 0)
            {
                batch->head = batch->tail = new_participant;
            }
            else
            {
                if (new_participant->bmi <= batch->head->bmi)
                {
                    // insert at start
                    new_participant->next = batch->head;
                    batch->head = new_participant;
                }
                else if (new_participant->bmi >= batch->tail->bmi)
                {
                    // insert at end
                    batch->tail->next = new_participant;
                    batch->tail = new_participant;
                }
                else
                {
                    // insert intermediate
                    Participant *node;
                    Participant *prev_node;
                    for (node = batch->head; node != NULL; node = node->next)
                    {
                        if (node->bmi > new_participant->bmi) //
                        {
                            new_participant->next = node;
                            prev_node->next = new_participant;
                            break;
                        }
                        prev_node = node;
                    }
                }
            }
            if (new_participant->bmi > BMI_OBESE_LEVEL)
            {
                batch->obese++;
            }
            else if (new_participant->bmi < BMI_UNDERWEIGHT_LEVEL)
            {
                batch->under_weight++;
            }
            batch->participant_count++;
            return new_participant->participant_id;
        }
    }
    return -1;
}

YogaBatch *UpdateHightWeight(YogaBatch *batch, int Participant_ID, float height, float weight)
{

    Participant *node;
    for (node = batch->head; node != NULL; node = node->next)
    {
        if (node->participant_id == Participant_ID)
        {
            break;
        }
    }
    if (node != NULL)
    {
        node->height_cm = height;
        node->weight_kg = weight;
        YogaBatch *updated_batch = InitialiseBatch();
        // need to sort
        for (Participant *temp = batch->head; temp != NULL; temp = temp->next)
        {
            AddParticipant(updated_batch, temp->name,temp->age,temp->weight_kg,temp->height_cm);
        }
        return 1;
    }
    return -1;
}