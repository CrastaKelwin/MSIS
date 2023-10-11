#ifndef _DATING_SITE_H_
#define _DATING_SITE_H_

typedef enum _gender{
    kMale,
    kFemale,
    kOthers
}Gender;

typedef struct _user_{
    unsigned int user_id;
    char name[20];
    char occupation[20];
    Gender gender;
    int age;
    struct _user_ *next_user;
}User;

int AddUser( char *name,char *occupation,Gender gender,int age);
void ViewUsers();
void ViewUserDetails(unsigned int user_id);


#endif //_DATING_SITE_H_