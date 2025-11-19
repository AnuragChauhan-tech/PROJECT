#include<stdio.h>
#include<string.h>


#define max_student 200
#define max_name 40
#define subject_count 5
#define max_roll 16
#define gpascale 4
typedef struct {//a list that stores all students records as dictionaries
    char name[max_name];
    int marks[subject_count];
    int roll_no[max_roll];
    int total;
    float average;
} Student;
int student_count =0;
void compute(Student *s){
     s->total = 0;
    for(int i = 0; i < subject_count; i++) {
        s->total = s->total + s->marks[i];


    }
    s->average = s->total / (float)subject_count;

}
//1. Data Storage
//students = [] - A list that stores all student records as dictionaries

// add_student() Function input for student name, roll number, and 5 subject marks
//Calculates total using sum(marks)
//Calculates percentage as (total/500) × 100
//Calls calculate_gpa() to convert percentage to GPA
//Stores everything in a dictionary and adds to the students list