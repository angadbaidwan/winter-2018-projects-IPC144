// Name: Angadpreet Baidwan
// Student Number: 135421170
// Email: abaidwan1@myseneca.ca
// Section: P
// Workshop: 5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 2

int main() {

	struct Employee
	{
		int id;
		int age;
		double salary;
	};

	int option; int validEmps = 0;
	struct Employee emp[SIZE] = {{ 0 }};

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
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
				printf("Enter Employee ID: ");
				scanf("%d", &emp[validEmps].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[validEmps].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[validEmps].salary);
				printf("\n");
				if (emp[validEmps].id > 0) {
					++validEmps;
				}
			} else {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			break;
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		default:
			printf("ERROR!!! Invalid Menu Option Selected\n\n");
			break;
		}
	} while (option != 0);
	return 0;
}