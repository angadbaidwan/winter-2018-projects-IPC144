#include <stdio.h>

int main() {
	const float PI = 3.143f;
	double radius, area;

	printf("Enter the circle radius: ");
	scanf_s("%lf", &radius);

	area = PI * (radius * radius);

	printf("The circle area is %.2lf.\n", area);

	return 0;
}