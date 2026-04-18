#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    int id;
    char name[50];
    float grades[10];
    int gradeCount;
    float average;
    struct Student* next;
} Student;

// Function declarations
Student* addStudent(Student* head);
Student* removeStudent(Student* head);
Student* searchByID(Student* head, int id);
Student* searchByName(Student* head, char name[]);
void addGrade(Student* head);
void displayStudent(Student* s);
void displayAll(Student* head);
Student* updateStudent(Student* head);
void freeList(Student* head);

#endif