#include <stdio.h>

int main() {
	
	int grade;
	char gradeL;

	printf("Enter percent grade: ");
	scanf_s("%d", &grade);

	if (grade >= 85 && grade <= 100) {
		gradeL = 'A';
	} else if (grade >= 70 && grade < 85) {
		gradeL = 'B';
	} else if (grade >= 60 && grade < 70) {
		gradeL = 'C';
	} else if (grade >= 50 && grade < 60) {
		gradeL = 'D';
	} else if (grade >= 0 && grade < 50) {
		gradeL = 'F';
	} else {
		gradeL = 'I';
	}

	printf("The letter grade is: %c\n", gradeL);

	return 0;
}