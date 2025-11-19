#include<stdio.h>
#include<string.h>


#define max_student 200
#define max_name 40
#define subject_count 5
#define max_roll 16

typedef struct {
    char name[max_name];
    int marks[subject_count];
    int roll_no[max_roll];
    int total;
    float average;
} Student;
int student_count =0;
void compute(Student *s){
    int sum = 0;
    int i;
    for (i = 0 ; i < subject_count; i++)sum += s-> marks[i];
    s-

    

}






