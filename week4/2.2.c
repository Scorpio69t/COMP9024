#include <stdio.h>
typedef struct {
   int   studentID;
   int   age;
   char  gender;
   float WAM;
} PersonT;

int main(void) {
    PersonT per1;
    PersonT per2;
    PersonT *ptr;

    ptr = &per1;
    per1.studentID = 3141592;
    ptr->gender = 'F';
    ptr = &per2;
    ptr->studentID = 2718281;
    ptr->gender = 'M';
    per1.age = 25;
    ptr->age = 24;
    ptr = &per1;
    per2.WAM = 86.0;
    ptr->WAM = 72.625;
    ptr->studentID = 1234567;
        // Print per1
    printf("per1:\n");
    printf("Student ID: %d\n", per1.studentID);
    printf("Age: %d\n", per1.age);
    printf("Gender: %c\n", per1.gender);
    printf("WAM: %.2f\n", per1.WAM);

    // Print per2
    printf("\nper2:\n");
    printf("Student ID: %d\n", per2.studentID);
    printf("Age: %d\n", per2.age);
    printf("Gender: %c\n", per2.gender);
    printf("WAM: %.2f\n", per2.WAM);

    return 0;
}