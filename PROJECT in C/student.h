#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    int roll;
    char name[40];
    float marks[5];
    float total;
    float percentage;
    char grade;
} Student;

// core function
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

// helper
void calculateResult(Student* student);

#endif