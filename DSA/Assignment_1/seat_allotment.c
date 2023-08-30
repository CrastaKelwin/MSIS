#include "seat_allotment.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
Seat *seats[kTotalQuota];

static Seat *InitializeSeats(int seat_count)
{
    Seat *seats = (Seat *)malloc(sizeof(Seat));
    if (seats)
    {
        seats->student = (Student *)malloc(sizeof(Student) * seat_count);
        if (seats->student)
        {
            seats->available_seat_count = seat_count;
            return seats;
        }
        free(seats);
        return NULL;
    }
    return NULL;
}

int ApplyForSeat(Quota applying_quota, Student student)
{
    int seat_alloted = 0;
    switch (applying_quota)
    {
    case kQuotaMerit:
        if (seats[applying_quota]->available_seat_count > 0)
        {
            memcpy(&seats[applying_quota]->student[seats[applying_quota]->available_seat_count - 1],
                   &student,
                   sizeof(student));
            seats[applying_quota]->student[seats[applying_quota]->available_seat_count - 1].quota = applying_quota;
            seats[applying_quota]->available_seat_count--;
            seat_alloted = 1;
        }
        else
        {
            for (int i = 0; i < MERIT_SEATS_AVAILABLE; i++)
            {
                if (seats[applying_quota]->student[i].rank > student.rank)
                {
                    // check for least rank student
                    int highest_rank_student_index = i;
                    int highest_rank = seats[applying_quota]->student[0].rank;
                    for (int j = 0; j < MERIT_SEATS_AVAILABLE; j++)
                    {
                        if (seats[applying_quota]->student[j].rank > highest_rank)
                        {
                            highest_rank_student_index = j;
                            highest_rank = seats[applying_quota]->student[j].rank;
                        }
                    }
                    memcpy(&seats[applying_quota]->student[highest_rank_student_index],
                           &student,
                           sizeof(student));
                    seats[applying_quota]->student[highest_rank_student_index].quota = applying_quota;
                    seat_alloted = 1;
                    break;
                }
            }
        }
        break;
    case kQuotaManagemnet:
    case kQuotaNRI:
        if (seats[applying_quota]->available_seat_count > 0)
        {
            memcpy(&seats[applying_quota]->student[seats[applying_quota]->available_seat_count - 1],
                   &student,
                   sizeof(student));
            seats[applying_quota]->student[seats[applying_quota]->available_seat_count - 1].quota = applying_quota;
            seats[applying_quota]->available_seat_count--;
            seat_alloted = 1;
        }
        else
        {
            seat_alloted = 0;
        }
        break;
    default:
        break;
    }

    return seat_alloted;
}

int AllocateSeats(void)
{
    seats[kQuotaManagemnet] = InitializeSeats(MANAGEMENT_QUOTA_SEATS);
    seats[kQuotaMerit] = InitializeSeats(MERIT_SEATS_AVAILABLE);
    seats[kQuotaNRI] = InitializeSeats(NRI_QUOTA_SEATS);
    if (seats[kQuotaManagemnet] == NULL || seats[kQuotaMerit] == NULL || seats[kQuotaNRI] == NULL)
    {
        return -1;
    }
    return 1;
}

static void PrintStudentDetails(Student student)
{
    const char *qt[kTotalQuota] = {"None", "Merit", "Management", "NRI"};
    printf("| Name : %s\t| Rank : %d\t| Quota : %s   \t|\n", student.name, student.rank, qt[student.quota]);
}

void PrintSeatAllotedStudentsDetails()
{
    printf(".---------------------------------------------------------------.\n");
    printf("| Seat Allocated Student List:                                  |\n");
    printf("|---------------------------------------------------------------|\n");
    for (int i = MERIT_SEATS_AVAILABLE - 1; i >= 0; i--)
    {
        PrintStudentDetails(seats[kQuotaMerit]->student[i]);
    }
    for (int i = MANAGEMENT_QUOTA_SEATS - 1; i >= 0; i--)
    {
        PrintStudentDetails(seats[kQuotaManagemnet]->student[i]);
    }
    for (int i = NRI_QUOTA_SEATS - 1; i >= 0; i--)
    {
        PrintStudentDetails(seats[kQuotaNRI]->student[i]);
    }
    printf("'---------------------------------------------------------------'\n");
}