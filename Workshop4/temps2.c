// Name: Angadpreet Baidwan
// Student Number: 135421170
// Email: abaidwan1@myseneca.ca
// Section: P
// Workshop: 4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int NUM; int max = -100; int min = 100; int maxDay; int minDay; int avgDays; int total = 0;
	int Day[10]; int Hi[10]; int Low[10];
	float avg;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &NUM);
	printf("\n");

	while (NUM < 3 || NUM > 10) {
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &NUM);
		printf("\n");
	}

	int i = 0;
	for (i = 0; i < NUM; i++) {
		Day[i] = i + 1;
		printf("Day %d - High: ", Day[i]);
		scanf("%d", &Hi[i]);
		if (Hi[i] > max) {
			max = Hi[i];
			maxDay = Day[i];
		}
		printf("Day %d - Low: ", Day[i]);
		scanf("%d", &Low[i]);
		if (Low[i] < min) {
			min = Low[i];
			minDay = Day[i];
		}
	}

	printf("\nDay  Hi  Low\n");

	int j = 0;
	for (j = 0; j < NUM; j++) {
		printf("%d    %d    %d\n", Day[j], Hi[j], Low[j]);
	}
	
	printf("\nThe highest temperature was %d, on day %d\n", max, maxDay);
	printf("The lowest temperature was %d, on day %d\n", min, minDay);
	printf("\n");

	do {
		total = 0;
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", NUM);
		scanf("%d", &avgDays);
		printf("\n");
		if (avgDays >= 0) {
			while (avgDays == 0 || avgDays > NUM) {
				printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", NUM);
				scanf("%d", &avgDays);
				printf("\n");
			}
			int g = 0;
			for (g = 0; g < avgDays; g++) {
				total += Hi[g];
				total += Low[g];
			}
			if (avgDays > 0) {
				avg = (float)total / ((float)avgDays * 2);
				printf("The average temperature up to day %d is: %.2lf\n\n", avgDays, avg);
			}
		}
	} while (avgDays > 0);

	printf("Goodbye!\n");
	return 0;
}