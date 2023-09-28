/* Title: Assignment #1 - Student Registration System
* Course: CST8234 C Language
* @Author: <<< Yijia Xu (041061204) >>>
* Lab Section: 301
* Professor: Surbhi Bahri
* Due date: 07/10/23
* Submission date: 07/10/23
*
* Demo malloc(), memset(), calloc() and free() in C, Ansi-style
*
* Status:
* Requirement #1: {complete}
* Requirement #2: {complete} 
* Requirement #3: {complete}
* Requirement #4: {complete}
* Requirement #5: {complete}
* Requirement #6: {complete}
* Requirement #7: {complete}
* Requirement #8: {complete}
*
*/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/*
Function Name: main
Purpose: Display main menu, and prompt user to enter an option.
Function in parameters: void
Function out parameter: EXIT_SUCCESS
Version: 1
Author: Yijia Xu
*/
int main(){
    int stuNumber;
    int courseNumber;
    printf("Welcome to Student Registration System. \n\n");
    stuNumber = get_int("Enter the number of students to register: ");

    /* allocate dynamic memory to save student id in an array */
    char** studentId = (char*) malloc(stuNumber * sizeof(char*));
    studentIdInput(stuNumber, studentId);

    printf("\n");

    courseNumber = get_int("Enter the number of courses to register: ");
    /* allocate dynamic memory to save student id in an array */
    char** courseId = (char*) malloc(courseNumber * sizeof(char*));
    courseIdInput(courseNumber, courseId);

    /* initilize dynamically memory location for registration table (2darray) */
    int i, j;
    int** table = (int**)malloc(stuNumber * sizeof(int*));
    for (i = 0; i < stuNumber; i++) {
        table[i] = (int*)malloc(courseNumber * sizeof(int));
        for (j=0; j<courseNumber; j++)
            table[i][j] = 0;
    }

    /* initilize dynamically memory location for registration table (for printing out) */
    RegistrationTable* regi = malloc(stuNumber * courseNumber * sizeof(RegistrationTable));
    int count = 0;
    int option;
    int skip = 1;

    while (1){
        printf("\nMain Menu:\n");
        printf("  [1] Register a student into a course.\n");
        printf("  [2] Drop a student from a course.\n");
        printf("  [3] Display Registration table\n");
        printf("  [4] Exit.\n");
        option = get_int("  Enter an option from the menu: ");
        
        int i, j;
        int stu_index, cour_index;
        switch (option)
        {
        case 1:
            /* prompt and verify entered student and course id(s) */
            student_list(stuNumber, studentId);
            char* inputStuId = (char*)malloc(20 * sizeof(char));
            stu_index = checkStuID(inputStuId, studentId, stuNumber);

            course_list(courseNumber, courseId);
            char* inputCourId = (char*)malloc(20 * sizeof(char));
            cour_index = checkCourID(inputCourId, courseId, courseNumber);
            
            /* check if id is already on record */
            if (table[stu_index][cour_index] == 1){
                printf("Already on record.\n");
                printf("Student id %5s cannot register to course %7s\n", inputStuId, inputCourId);
                printf("Registration Unsuccessful.\n");
                continue;
            }
            else {
            RegistrationTable new;
                new.index = count;
                new.studentId = studentId[stu_index]; 
                new.courseId = courseId[cour_index]; 
                new.status = 'R';
            /* check if id is dropped out */
            for (i=0; i<count; i++){
                if ((strcmp(new.studentId, regi[i].studentId) == 0) && (strcmp(new.courseId, regi[i].courseId) == 0)){
                    if (regi[i].status == 'D'){
                        printf("Student id %5s have dropped out from course %7s\n", new.studentId, new.courseId);
                        printf("Registration Unsuccessful.\n");
                        /* skip and return to main menu */
                        skip = 0;
                        break;
                    }
                }
            }
            if (!skip)
                continue;
            /* save registered student and course to struct */
            regi[count] = new;
            printf("Registration Successful.\n");
            count++;

            table[stu_index][cour_index] =1;
            }

            free(inputStuId);
            free(inputCourId);

            break;
        case 2:
            registration_table(stuNumber, courseNumber, regi, count);
            printf("Please select Index number to drop student registration:");
            int dropIndex;
            scanf("%d", &dropIndex);

            /* find the student and course indices for the dropped registration */
            if (dropIndex >=0 && dropIndex < count) {
                regi[dropIndex].status = 'D';
                printf("Drop course successful.\n");

                int dropStuIndex = -1;
                int dropCourIndex = -1;
                for (i = 0; i < stuNumber; i++) {
                    for (j = 0; j < courseNumber; j++) {
                        if (strcmp(regi[dropIndex].studentId, studentId[i]) == 0 &&
                        strcmp(regi[dropIndex].courseId, courseId[j]) == 0) {
                            dropStuIndex = i;
                            dropCourIndex = j;
                            break;
                        }
                   }
                }
                
                /* change the corresponding position in table to 0 for dropped*/
                if (dropStuIndex != -1 && dropCourIndex != -1) {
                    table[dropStuIndex][dropCourIndex] = 0;
                }
                registration_table(stuNumber, courseNumber, regi, count);
            }
            else {
                printf("Error! Invalid registration index.\n");
            }
            break;

        case 3:
            registration_table(stuNumber, courseNumber, regi, count);
            break;
        case 4:
            /* free registration table (2d array) */
            for (i = 0; i < stuNumber; i++) {
                free(table[i]);  
            }
            free(table);
            
            freeRegistrationTable(regi, count);
            printf("Existing......\n");
            return EXIT_SUCCESS;
        default:
            printf("Please enter an integer between 1 and 4.\n");
            break;
        }
    }
}

/*
Function Name: freeRegistrationTable
Purpose: Free memory of registration table.
Function in parameters: RegistrationTable* regi, int count
Function out parameter: void
Version: 1
Author: Yijia Xu
*/
void freeRegistrationTable(RegistrationTable* regi, int count) {
    int i;
    free(regi->studentId);
    free(regi->courseId);
    free(regi);
}

