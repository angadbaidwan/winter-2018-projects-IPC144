/*
Name:      Angadpreet Baidwan
Student#:  135421170
Section:   P
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	double amountDue, GST;
	int loonies, quarters, dimes, nickels, pennies, intBalance;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amountDue);

	GST = amountDue * .13 + .005;
	amountDue += GST;
	printf("GST: %0.2lf\n", GST);
	printf("Balance owing: $%.2lf\n", amountDue);

	loonies = amountDue;
	amountDue = amountDue - loonies;
	intBalance = 100 * amountDue;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, (float)intBalance / 100);

	quarters = intBalance / 25;
	intBalance = intBalance % 25;
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, (float)intBalance/100);

	dimes = intBalance / 10;
	intBalance = intBalance % 10;
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, (float)intBalance / 100);

	nickels = intBalance / 5;
	intBalance = intBalance % 5;
	printf("Nickels required: %d, balance owing $%.2lf\n", nickels, (float)intBalance / 100);

	pennies = intBalance;
	intBalance = 0;
	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, (float)intBalance / 100);


	return 0;
}