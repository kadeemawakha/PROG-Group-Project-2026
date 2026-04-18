#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "student.h"

// Search functions
Student* searchByID(Student* head, int id);
Student* searchByName(Student* head, char name[]);

// Grade functions
void addGrade(Student* head);

// Display functions
void displayStudent(Student* s);
void displayAll(Student* head);

// Update function
Student* updateStudent(Student* head);

#endif
