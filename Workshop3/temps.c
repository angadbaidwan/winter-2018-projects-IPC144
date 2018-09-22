// Name: Angadpreet Baidwan
// Student Number: 135421170
// Email: abaidwan1@myseneca.ca
// Section: P
// Workshop: 3

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 4;
#include <stdio.h>

int main() {

	int highDay, lowDay, n, maxDay, minDay;
	int totalHigh = 0; int totalLow = 0; int maxTemp = -40; int minTemp = 40;
	double avgHigh, avgLow, avgTotal;
	int x = 1;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (n = 1; n <= 4; n++) {
		x = 1;
		while (x > 0) {
			printf("Enter the high value for day %d: ", n);
			scanf("%d", &highDay);
			printf("\n");
			printf("Enter the low value for day %d: ", n);
			scanf("%d", &lowDay);
			printf("\n");

			if ((highDay > 40 || lowDay < -40) || highDay < lowDay) {
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
				x = 1;
			}
			else {
				x = 0;
			}
			if (highDay > maxTemp) {
				maxTemp = highDay;
				maxDay = n;
			} if (lowDay < minTemp) {
				minTemp = lowDay;
				minDay = n;
			}
		}
		totalHigh += highDay;
		totalHigh += lowDay;
	}
	avgHigh = totalHigh / NUMS;
	avgLow = totalLow / NUMS;
	avgTotal = (avgHigh + avgLow) / 2;
	printf("The average (mean) temperature was: %.2lf\n", avgTotal);
	printf("The highest temperature was %d, on day %d\n", maxTemp, maxDay);
	printf("The lowest temperature was %d, on day %d\n", minTemp, minDay);
	return 0;
}