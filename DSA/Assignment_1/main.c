#include "seat_allotment.h"
#include <assert.h>

int main()
{
    assert(AllocateSeats() == 1);
    ApplyForSeat(kQuotaMerit, (Student){"merit_1", 100, 0});
    ApplyForSeat(kQuotaMerit, (Student){"merit_2", 25, 0});
    ApplyForSeat(kQuotaMerit, (Student){"merit_3", 34, 0});
    ApplyForSeat(kQuotaMerit, (Student){"merit_4", 12, 0});
    ApplyForSeat(kQuotaMerit, (Student){"merit_5", 8, 0});
    ApplyForSeat(kQuotaMerit, (Student){"merit_6", 10, 0});
    ApplyForSeat(kQuotaMerit, (Student){"merit_7", 1, 0});
    ApplyForSeat(kQuotaMerit, (Student){"merit_8", 2, 0});
    ApplyForSeat(kQuotaMerit, (Student){"merit_9", 5, 0});
    ApplyForSeat(kQuotaMerit, (Student){"merit_10", 11, 0});
    ApplyForSeat(kQuotaNRI, (Student){"nri_st_1", 2, 0});
    ApplyForSeat(kQuotaNRI, (Student){"nri_st_2", 200000, 0});
    ApplyForSeat(kQuotaNRI, (Student){"nri_st_3", 2, 0});
    ApplyForSeat(kQuotaManagemnet, (Student){"mana_1 ", 20, 0});
    ApplyForSeat(kQuotaManagemnet, (Student){"mana_2 ", 500, 0});
    ApplyForSeat(kQuotaManagemnet, (Student){"mana_3 ", 400, 0});
    ApplyForSeat(kQuotaManagemnet, (Student){"mana_4 ", 2, 0});
    PrintSeatAllotedStudentsDetails();
    return 0;
}