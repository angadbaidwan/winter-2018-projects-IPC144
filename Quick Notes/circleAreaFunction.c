#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double cArea(double, float);

int main() {
	const float PI = 3.143f;
	double radius, area;

	printf("Enter radius: ");
	scanf("%lf", &radius);
	area = cArea(radius, PI);
	printf("The are of the circle is %.2lf\n\n", area);
	return 0;
}

double cArea(double rad, float PI) {
	double result;
	result = rad*rad*PI;
	
	return result;
}