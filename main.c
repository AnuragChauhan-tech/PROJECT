#include <stdio.h>
#include "./student.h"

int main()
{
    int choice;
    while (1)
    {
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            break;
        }
    }

    return 0;
}