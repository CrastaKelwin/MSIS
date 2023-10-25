
#ifndef _YOGA_CLASSES_H_
#define _YOGA_CLASSES_H_

typedef struct _participant
{
    int participant_id;
    char name[20];
    int age;
    float weight_kg;
    float height_cm;
    float bmi;
    struct _participant *next;
} Participant;

typedef struct _yoga_batch
{
    int participant_id_max;
    Participant *head;
    Participant *tail;
    int participant_count;
    int under_weight;
    int obese;
} YogaBatch;

YogaBatch *InitialiseBatch();

int AddParticipant(YogaBatch *batch, char *name, int age, float weight_kg,
                   float height_cm);
void PrintBatchDetails(YogaBatch *list, const char *test_msg);
int GetParticipantCount(YogaBatch *batch);
int GetObeseCount(YogaBatch *batch);
int GetUnderweightCount(YogaBatch *batch);

YogaBatch * UpdateHightWeight(YogaBatch *batch, int Participant_ID, float height, float weight);
#endif //_YOGA_CLASSES_H_