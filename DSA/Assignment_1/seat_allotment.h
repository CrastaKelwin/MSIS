#ifndef _SEAT_ALLOTMENT_H_
#define _SEAT_ALLOTMENT_H_

#define MAX_NAME_CHAR (20U)

#define TOTAL_SEATS_AVAILABLE (8U)

#define MERIT_SEATS_AVAILABLE (6U)

#define MANAGEMENT_QUOTA_SEATS (2U)

#define NRI_QUOTA_SEATS (2U)

typedef enum 
{
    kQuotaNone =0,
    kQuotaMerit,
    kQuotaManagemnet,
    kQuotaNRI,
    kTotalQuota
}Quota;

typedef struct _student{
    char name[MAX_NAME_CHAR];
    int rank;
    Quota quota;
}Student;

typedef struct _seat{
    Student *student;
    int available_seat_count;
}Seat;

int AllocateSeats(void);
int ApplyForSeat(Quota quota, Student student );
void PrintSeatAllotedStudentsDetails();
#endif// _SEAT_ALLOTMENT_H_
