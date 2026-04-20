#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

// Search by ID

Student* searchByID(Student* head, int id)
{
	while (head != NULL)
	{
		if (head->id == id)
		{
			return head;
			head = head->next;
		}

		return NULL;
	}
}

	//  Search by name

	Student* searchByName(Student * head, char name[])
	{
		while (head != NULL)
		{
			if (strcmp(head->name, name) == 0)
			{
				return head;
				head = head->next;
			}

			return NULL;
		}
	}


	// Display one student

	void displayStudent(Student* s)
	{
		if (!s) return;

		printf("\nID: %d\nName: %s\nAverage: %.2f\n", s->id, s->name, s->average);
		printf("Grades: ");
		
		for (int i = 0; i < s->gradeCount; i++)
			printf("%.1f", s->grades[i]);

		printf("\n");
	}

	// Display all students

	void displayAll(Student* head)
	{
		while (head != NULL)
		{
			displayStudent(head);
			head = head->next;
		}
	}

	// Update student name

	Student* updateStudent(Student* head)
	{
		int id;
		printf("Enter Student ID: ");
		scanf_s("%d", &id);

		Student* s = searchByID(head, id);
		
		if (!s)
		{
			printf("Student not found.\n");
			return head;
		}

		printf("Enter new name: ");
		scanf_s(" %[^\n]", s->name, (unsigned)_countof(s->name));

		return head;
	}