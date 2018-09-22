#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	/* Input Data
	9   2345.33  28
	10  1625.27  29
	11  1000.00  27
	12  3567.90  33
	*/

	int num;
	int employ[4] = {1,2,3,4} ; int id[4]; int age[4];
	float salary[4];

	printf("Enter number of employees between 1 & 4: ");
	scanf("%d", &num);
	printf("\n");

	for (int i = 0; i < num; i++) {
		printf("Employee #%d. Enter employ ID: ", employ[i]);
		scanf("%d", &id[i]);
		printf("Enter Salary: ");
		scanf("%f", &salary[i]);
		printf("Enter age: ");
		scanf("%d", &age[i]);
		printf("\n");
	}

	for (int j = 0; j < num; j++) {
		printf("Empl #%d  Id = %d  Salary = %.2f  Age = %d\n\n", employ[j], id[j], salary[j], age[j]);
	}

	return 0;
}