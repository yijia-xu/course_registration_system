#include<stdio.h>
#include <stdlib.h>
#include "main.h"

/*
Function Name: student_list
Purpose: Print a list of student id saved in the array.
Function in parameters: int stu_number, char** stu_id
Function out parameter: void
Version: 1
Author: Yijia Xu
*/
void student_list(int stu_number, char** stu_id){
    int i;
    printf("List of Student IDs\n");
    for (i=0; i<stu_number; i++)
        printf("Index %i%10s\n", i, stu_id[i]);
}

/*
Function Name: course_list
Purpose: Print a list of course id saved in the array.
Function in parameters: int course_number, char** course_id
Function out parameter: void
Version: 1
Author: Yijia Xu
*/
void course_list(int course_number, char** course_id){
    int i;
    printf("List of Available Course IDs\n");
    for (i=0; i<course_number; i++)
        printf("Index %i%10s\n", i, course_id[i]);
}

/*
Function Name: registration_table
Purpose: Print the registration table.
Function in parameters: int stuNumber, int courseNumber, RegistrationTable* regi, int count
Function out parameter: void
Version: 1
Author: Yijia Xu
*/
void registration_table(int stuNumber, int courseNumber, RegistrationTable* regi, int count){
    printf("\n%40s", "Resigtration Table\n");
    printf("%-20s%-20s%-20s%-20s\n", "Registration Index", "Student ID", "Course ID", "Registration Status");

    int i;
    for (i = 0; i < count; i++) {
        printf("%-20d%-20s%-20s%-20c\n", regi[i].index, regi[i].studentId,
               regi[i].courseId, regi[i].status);
    }
}
