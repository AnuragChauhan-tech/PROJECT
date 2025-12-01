#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define FILE_PATH "../data/students.txt"

void calculateResult(Student *student) {
    float total = 0.0f;
    for (int i = 0; i < MAX_SUBJECTS; ++i) {
        total += student->marks[i];
    }
    student->total = total;
    student->percentage = total / MAX_SUBJECTS;

    if (student->percentage >= 90.0f) student->grade = 'A';
    else if (student->percentage >= 75.0f) student->grade = 'B';
    else if (student->percentage >= 60.0f) student->grade = 'C';
    else if (student->percentage >= 40.0f) student->grade = 'D';
    else student->grade = 'F';
}

void addStudent() {
    FILE *pFile = fopen(FILE_PATH, "a");
    if (pFile == NULL) {
        printf("Error opening file for appending");
        return;
    }

    Student s;
    /* Read roll number */
    printf("Enter Roll Number: ");
    if (scanf("%d", &s.roll) != 1) {
        printf("Invalid roll number input.\n");
        /* consume leftover input */
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        fclose(pFile);
        return;
    }

    /* consume leftover newline before fgets */
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    /* Read name (allows spaces) */
    printf("Enter Name: ");
    if (fgets(s.name, NAME_LEN, stdin) == NULL) {
        printf("Error reading name.\n");
        fclose(pFile);
        return;
    }
    /* strip trailing newline */
    size_t len = strlen(s.name);
    if (len > 0 && s.name[len - 1] == '\n') s.name[len - 1] = '\0';

    /* Read marks for each subject with validation */
    for (int i = 0; i < MAX_SUBJECTS; ++i) {
        float m;
        int ok = 0;
        do {
            printf("Enter marks for subject %d (0-100): ", i + 1);
            if (scanf("%f", &m) != 1) {
                printf("Invalid input. Try again.\n");
                /* clear invalid token */
                int cc;
                while ((cc = getchar()) != '\n' && cc != EOF);
                continue;
            }
            if (m < 0.0f || m > 100.0f) {
                printf("Marks must be between 0 and 100. Try again.\n");
                continue;
            }
            ok = 1;
            s.marks[i] = m;
        } while (!ok);
    }

    calculateResult(&s);

    /* Write a tab-separated line:
       roll\tname\tm1\tm2\t... \ttotal\tpercentage\tgrade\n
    */
    fprintf(pFile, "%d\t%s", s.roll, s.name);
    for (int i = 0; i < MAX_SUBJECTS; ++i) {
        fprintf(pFile, "\t%.2f", s.marks[i]);
    }
    fprintf(pFile, "\t%.2f\t%.2f\t%c\n", s.total, s.percentage, s.grade);

    fclose(pFile);
    printf("Student added successfully.\n");
}

void displayStudents() {
    FILE *pFile = fopen(FILE_PATH, "r");
    if (pFile == NULL) {
        perror("Error opening file for reading");
        return;
    }

    char line[512];
    printf("\n--- Students ---\n");
    while (fgets(line, sizeof(line), pFile) != NULL) {
        /* trim newline */
        size_t ln = strlen(line);
        if (ln > 0 && line[ln - 1] == '\n') line[ln - 1] = '\0';

        /* Tokenize tab-separated fields */
        char *token = strtok(line, "\t");
        if (!token) continue;

        /* roll */
        int roll = atoi(token);
        token = strtok(NULL, "\t"); if (!token) continue;
        char name[NAME_LEN]; strncpy(name, token, NAME_LEN); name[NAME_LEN-1] = '\0';

        float marks[MAX_SUBJECTS];
        for (int i = 0; i < MAX_SUBJECTS; ++i) {
            token = strtok(NULL, "\t");
            if (token) marks[i] = strtof(token, NULL);
            else marks[i] = 0.0f;
        }

        token = strtok(NULL, "\t"); /* total */
        float total = token ? strtof(token, NULL) : 0.0f;
        token = strtok(NULL, "\t"); /* percentage */
        float percentage = token ? strtof(token, NULL) : 0.0f;
        token = strtok(NULL, "\t"); /* grade */
        char grade = (token && token[0]) ? token[0] : 'F';

        /* print nicely */
        printf("Roll: %d | Name: %s | Marks:", roll, name);
        for (int i = 0; i < MAX_SUBJECTS; ++i) {
            printf(" %.0f", marks[i]);
            if (i < MAX_SUBJECTS-1) printf(",");
        }
        printf(" | Total: %.2f | %%: %.2f | Grade: %c\n", total, percentage, grade);
    }

    fclose(pFile);
}


