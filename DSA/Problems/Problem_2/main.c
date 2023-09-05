#include "dating_site.h"
#include <stddef.h>

int main()
{
    AddUser("user 1", "engineer", kMale, 25);
    AddUser("user 2", "Sales", kFemale, 28);
    AddUser("user 3", "Techie", kMale, 27);
    AddUser("user 4", "Tester", kFemale, 30);
    AddUser("user 5", "Manager", kMale, 45);
    ViewUsers();
    ViewUserDetails(0);
    ViewUsers();
    ViewUserDetails(3);
    ViewUsers();
    ViewUserDetails(4);
    ViewUsers();
    ViewUserDetails(1);
    ViewUsers();
    return 0;
}