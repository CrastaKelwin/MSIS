#include "dating_site.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct _user_list_
{
    User *end_user;
    User *first_user;
    int user_count;
} UserList;

UserList user_list = {.end_user = NULL, .first_user = NULL, .user_count = 0};
static User *CreateNewUser()
{
    return (User *)malloc(sizeof(User));
}
int AddUser(char *name, char *occupation, Gender gender, int age)
{
    User *new_user = CreateNewUser();
    if (new_user)
    {
        strncpy(new_user->name, name, 20);
        strncpy(new_user->occupation, occupation, 20);
        new_user->age = age;
        new_user->gender = gender;
        new_user->user_id = user_list.user_count;
        if (user_list.user_count == 0)
        {
            user_list.first_user = user_list.end_user = new_user;
        }
        else
        {
            user_list.end_user->next_user = new_user;
            user_list.end_user = new_user;
        }
        user_list.user_count++;
        return 0;
    }
    return -1;
}

void ViewUsers()
{
    printf("Users: \n");
    for (User *u = user_list.first_user; u != NULL; u = u->next_user)
    {
        printf("ID : %d, ", u->user_id);
        printf("Name : %s\n", u->name);
    }
}

void ViewUserDetails(unsigned int user_id)
{
    User *current_user = user_list.first_user;
    User *prev_user = NULL;
    while (current_user != NULL && current_user->user_id != user_id)
    {
        prev_user = current_user;
        current_user = current_user->next_user;
    }
    if (current_user != NULL)
    {
        printf("ID : %d, ", current_user->user_id);
        printf("Name : %s, ", current_user->name);
        printf("Gender : %d, ", current_user->gender);
        printf("Occ : %s, ", current_user->occupation);
        printf("Age : %d\n", current_user->age);
        // user with user id found
        if (prev_user != NULL)
        {
            prev_user->next_user = current_user->next_user;
            current_user->next_user = user_list.first_user;
            user_list.first_user = current_user;
        }
    }
}