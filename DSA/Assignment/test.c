#include "student_details.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main(int argc, const char **argv)
{
    StudentList *std = InitialiseList();
    InsertAtBeginning(std, "hio", 1);
    sleep(10);
    InsertAtBeginning(std, "hi", 1);
    SearchStudent(std,"dfh");
    sleep(10);
    InsertAtBeginning(std, "ho", 1);
    sleep(10);
    DeleteAtEnd(std);
    SearchStudent(std,"dfh");
    DeleteAtEnd(std);
    Printlist(std, "jhfchb");
    PrintTransactionLog();
    return 0;
}