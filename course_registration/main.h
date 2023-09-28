#ifndef REGISTRATION
#define REGISTRATION
typedef struct {
    int index;
    char* studentId;
    char* courseId;
    char status;
} RegistrationTable;

void freeRegistrationTable(RegistrationTable* regi, int stuNumber);
int get_int(char* prompt);
void studentIdInput(int number, char** id);
void courseIdInput(int number, char** id);
int checkStuID(char* inputId, char** id, int number);
int checkCourID(char* inputId, char** id, int number);
void student_list(int stu_number, char** stu_id);
void course_list(int course_number, char** course_id);
void registration_table(int stuNumber, int courseNumber, RegistrationTable* regi, int count);

#endif