#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
/*
Function Name: get_int
Purpose: Prompt user to enter an int and check if it is valid.
Function in parameters: char* prompt
Function out parameter: int
Version: 1
Author: Yijia Xu
*/
int get_int(char* prompt) {
    int num;
    printf("%s", prompt);
    /* read an integer input from the user and error checking */
    while(!(scanf("%d", &num) && getchar() == '\n'))
    { 
        /* consume redundant characters*/
        while(getchar() != '\n'){ 
            continue;
        }
        printf("ERROR! Please enter an integer.\n");
        printf("%s", prompt);
        
    }
    return num;
}

/*
Function Name: studentIdInput
Purpose: Prompt user to enter student ID(s) and save verified id into an 1d array.
Function in parameters: int number, char** id
Function out parameter: void
Version: 1
Author: Yijia Xu
*/
void studentIdInput(int number, char** id){
    int count = 0;
    int i = 0;
    char inputId[20];
    while (count < number){
        printf("Enter the student index[%d] student id [5-digits]: ", count);
        scanf("%s", &inputId);
        
        if (strlen(inputId) != 5) {
            printf("Student ID must be 5 digits.\n");
            while (getchar() != '\n'); 
            continue;
        }

        int skip = 0;
        for (i = 0; i < 5; i++) {
            if (inputId[i] < '0' || inputId[i] > '9') {
                while (getchar() != '\n');
                printf("Student ID must be 5 digits.\n");
                skip = 1;
                break;
            }
        }
        if (skip)
            continue;

        id[count] = (char*) malloc(strlen(inputId) * sizeof(char));
        strcpy(id[count], inputId);  
        count ++;
    }
}

/*
Function Name: courseIdInput
Purpose: Prompt user to enter course ID(s) and save verified id into an 1d array.
Function in parameters: int number, char** id
Function out parameter: void
Version: 1
Author: Yijia Xu
*/
void courseIdInput(int number, char** id){
    int count = 0;
    char inputId[20];
    while (count < number){
        printf("Enter the course index[%d] course id [3-Alphas][4-digits]: ", count);
        scanf("%s", &inputId);
        
        if (strlen(inputId) != 7) {
            printf("Incorrect course ID length [7-character-Id]\n");
            while (getchar() != '\n'); 
            continue;
        }

        int skip = 0;
        int i;
        for (i = 0; i < 3; i++) {
            if (inputId[i] < 'A' || inputId[i] > 'z') {
                while (getchar() != '\n');
                printf("Incorrect course ID length [3-Alphas][4-digits]\n");
                skip = 1;
                break;
            }
        }
        if (skip)
            continue;

        for (i = 3; i < 7; i++) {
            if (inputId[i] < '0' || inputId[i] > '9') {
                while (getchar() != '\n');
                printf("Incorrect course ID length [3-Alphas][4-digits]\n");
                skip = 1;
                break;
            }
        }
        if (skip)
            continue;    

        id[count] = (char*) malloc(strlen(inputId) * sizeof(char));
        strcpy(id[count], inputId);  
        count ++;
    }
}

/*
Function Name: checkStuID
Purpose: Prompt and check if entered student id is valid and be in the studentID array.
Function in parameters: char* inputId, char** id, int number
Function out parameter: int index
Version: 1
Author: Yijia Xu
*/
int checkStuID(char* inputId, char** id, int number){
    int index = -1;
    do{
        printf("Enter the student's ID to register a course: ");
        scanf("%s", inputId);
        if (strlen(inputId) != 5) {
            printf("Student ID must be 5 digits.\n");
            while (getchar() != '\n'); 
            continue;
        }
        int i;
        for (i = 0; i < number; i++) {
            if (strcmp(inputId, id[i]) == 0) {
                index = i;
                return index;
            }
        }
        if (index == -1)
            printf("Error! Student ID not found.\n");
    }
    while (index == -1);
}

/*
Function Name: checkCourID
Purpose: Prompt and check if entered course id is valid and be in the courseID array.
Function in parameters: char* inputId, char** id, int number
Function out parameter: int index
Version: 1
Author: Yijia Xu
*/
int checkCourID(char* inputId, char** id, int number){
    int index = -1;
    do{
        printf("Enter the course id [3-Alphas][4-digits]: ");
        scanf("%s", inputId);
        if (strlen(inputId) != 7) {
            printf("Incorrect course ID length [7-character ID]\n");
            while (getchar() != '\n'); 
            continue;
        }
        int i;
        for (i = 0; i < number; i++) {
            if (strcmp(inputId, id[i]) == 0) {
                index = i;
                return index;
            }
        }
        if (index == -1)
            printf("Error! Student ID not found.\n");
    }
    while (index == -1);
}

