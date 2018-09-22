#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define SIZE 5

int main() {

	struct Student {
		char name[20];
		int grade;
	};

	FILE *fp = NULL;
	struct Student st[SIZE];

	fp = fopen("testData.txt", "r");

	if (fp != NULL) {

		int i;
		for (i = 0; i < SIZE; i++) {
			while (fscanf(fp, "%d,%s\n", &st[i].name, &st[i].grade) != EOF) {
				printf("%d%s\n", &st[i].name, &st[i].grade);
			}

		}

		fclose(fp);
	}
	else {
		printf("Error: Could not open file.\n");
	}
	return 0;
}