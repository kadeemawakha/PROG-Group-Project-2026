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
	printf("4. Search by Name\n");
	printf("5. Add Grade to Student\n");
	printf("6. Display All Students\n");
	printf("7. Update Student\n");

	printf("8. Exit\n");
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
			
			head = addStudent(head);
			
		}

		else if (choice == 2)
		{
			head = removeStudent(head);
		}

		else if (choice == 3) 
		{
			int id;
			printf("Enter ID: ");
			scanf_s("%d", &id);

			Student* s = searchByID(head, id);
			if (s)
				displayStudent(s);
			else
				printf("Student not found.\n");
		}

		else if (choice == 4)
		{
			char name[50];
			printf("Enter name: ");
			scanf_s("%[^\n]", name);

			Student* s = searchByName(head, name);

			if (s)
				displayStudent(s);
			else
				printf("Student not found.\n");
		}

		else if (choice == 5)
		{
			addGrade(head);
		}

		else if (choice == 6)
		{
			if (head == NULL)

				printf("No students available.\n");

			else
				displayAll(head);
		}

		else if (choice == 7)
		{
			head = updateStudent(head);
		}

		else if (choice == 8)
		{
			freeList(head);
			printf("Exiting. . . \n");
			break;
		}

		else
		{
			printf("Invalid choice.\n");
		}
	}

	return 0;
}