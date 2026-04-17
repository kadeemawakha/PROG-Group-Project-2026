#include <stdio.h>
#include <string.h>
#include "student.h"
#include "operations.h"

void menu()
{
	printf("\n===== Student Grade Manager =====\n");
	printf("1. Add Student\n");
	printf("2. Remove Student\n");
	printf("3. Search Student by ID\n");
	printf("4. Add Grade to Student\n");
	printf("5. Display All Students\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");
}

int main()
{
	struct Student* head = NULL;
	int choice;

	while (1)
	{
		menu();

		if (scanf_s("%d", &choice) != 1)
		{
			printf("Invalid input. Try again.\n");
			while (getchar() != '\n'); // clears buffer
			continue;
		}

		if (choice == 1)
		{
			int id;
			char name[50];

			printf("Enter Student ID: ");
			scanf_s("%d", &id);

			printf("Enter Student Name: ");
			scanf_s("%d", &name);

			head = addStudent(head, id, name);
			printf("Student added successfully.\n");
		}

		else if (choice == 2)
		{
			int id;
			printf("Enter student ID to remove: ");
			scanf_s("%d", &id);

			head = removeStudent(head, id);
		}
	}
}