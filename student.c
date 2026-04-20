#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student* addStudent(Student* head) {
    Student* newNode = (Student*)malloc(sizeof(Student));

    printf("Enter ID: ");
    scanf("%d", &newNode->id);

    printf("Enter name: ");
    scanf_s(" %[^\n]", newNode->name, (unsigned)_countof(newNode->name));

    newNode->gradeCount = 0;
    newNode->average = 0;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    Student* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

Student* removeStudent(Student* head) {
    int id;
    printf("Enter ID to remove: ");
    scanf_s("%d", &id);

    Student* temp = head, * prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found.\n");
        return head;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Student removed.\n");
    return head;
}

void addGrade(Student* head) {
    int id;
    printf("Enter student ID: ");
    scanf_s("%d", &id);

    Student* s = searchByID(head, id);

    if (!s) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter grade: ");
    scanf_s("%f", &s->grades[s->gradeCount]);

    s->gradeCount++;

    float sum = 0;
    for (int i = 0; i < s->gradeCount; i++)
        sum += s->grades[i];

    s->average = sum / s->gradeCount;
}

void freeList(Student* head) {
    Student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}