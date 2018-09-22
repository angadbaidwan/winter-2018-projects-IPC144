// Name: Angadpreet Baidwan
// Student Number: 135421170
// Email: abaidwan1@myseneca.ca
// Section: P
// Workshop: 5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 4

int main() {

	struct Employee
	{
		int id;
		int age;
		double salary;
	};

	int option; int validEmps = 0; int inputId; int changeId;
	struct Employee emp[SIZE] = {{ 0 }};

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 1:
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			int j;
			for (j = 0; j < SIZE; j++) {
				if (emp[j].id > 0) {
					printf("%6d%9d%11.2lf\n", emp[j].id, emp[j].age, emp[j].salary);
				}
			}
			printf("\n");
			break;
		case 2:
			printf("Adding Employee\n");
			printf("===============\n");
			if (validEmps < SIZE) {
				int m;
				for (m = 0; m < SIZE; m++) {
					if (emp[m].id == 0) {
						changeId = m;
						m += SIZE;
					}
				}
				printf("Enter Employee ID: ");
				scanf("%d", &emp[changeId].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[changeId].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[changeId].salary);
				printf("\n");
				if (emp[validEmps].id > 0) {
					++validEmps;
				}
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			break;
		case 3:
			printf("Update Employee Salary\n");
			printf("======================\n");
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &inputId);
				int k;
				for (k = 0; k < SIZE; k++) {
					if (emp[k].id == inputId) {
						changeId = k;
					}
				}
				if (inputId != emp[changeId].id) {
					printf("ERROR!!! Invalid ID\n");
				}
				else {
					printf("The current salary is %.2lf\n", emp[changeId].salary);
					printf("Enter Employee New Salary: ");
					scanf("%lf", &emp[changeId].salary);
					printf("\n");
				}
			} while (inputId != emp[changeId].id);
			break;
		case 4:
			printf("Remove Employee\n");
			printf("===============\n");
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &inputId);
				int l;
				for (l = 0; l < SIZE; l++) {
					if (emp[l].id == inputId) {
						changeId = l;
					}
				}
				if (inputId != emp[changeId].id) {
					printf("ERROR!!! Invalid ID\n");
				}
				else {
					printf("Employee %d will be removed\n\n", emp[changeId].id);
					emp[changeId].id = 0; emp[changeId].salary = 0; emp[changeId].age = 0;
					inputId = 0;
					--validEmps;
				}
			} while (inputId != emp[changeId].id);
			break;
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
			break;
		}
	} while (option != 0);
	return 0;
}