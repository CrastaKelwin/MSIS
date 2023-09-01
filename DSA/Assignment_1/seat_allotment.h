#ifndef _SEAT_ALLOTMENT_H_
#define _SEAT_ALLOTMENT_H_

#define MAX_NAME_CHAR (20U)

#define TOTAL_SEATS_AVAILABLE (8U)

#define MERIT_SEATS_AVAILABLE (6U)

#define MANAGEMENT_QUOTA_SEATS (2U)

#define NRI_QUOTA_SEATS (2U)

typedef enum
{
    kQuotaNone = 0,
    kQuotaMerit,
    kQuotaManagemnet,
    kQuotaNRI,
    kTotalQuota
} Quota;

typedef struct _student
{
    char name[MAX_NAME_CHAR];
    int rank;
    Quota quota;
} Student;

typedef struct _seat
{
    Student *student;
    int available_seat_count;
} Seat;

/**
 * @brief Allocates memory and initialises the Seats available
 *
 * @return int 0 - success, -1 - failed
 */
int AllocateSeats(void);

/**
 * @brief Application function to apply for seat
 *
 * @param quota quota in which a student wants to apply
 * @param student a structure containing student details
 *
 * @note the return of this function is not reliable for a student applying for merit seat since his seat allotment depends on the later applying student
 * @return int momentory seat allotment status 1 - allotted, 0 - not alloted
 */
int ApplyForSeat(Quota quota, Student student);

/**
 * @brief Prints the details of seat alloted students 
 * 
 */
void PrintSeatAllotedStudentsDetails();
#endif // _SEAT_ALLOTMENT_H_
