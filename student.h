#ifndef STUDENT_H
#define STUDENT_H

#define MAX_SUBJECTS 5
#define NAME_LEN 40

typedef struct {
    int roll;
    char name[NAME_LEN];
    float marks[MAX_SUBJECTS];
    float total;
    float percentage;
    char grade;
} Student;

void addStudent();
void displayStudents();
void calculateResult(Student *student);

#endif /* STUDENT_H */
