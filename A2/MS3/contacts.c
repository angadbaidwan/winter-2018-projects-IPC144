/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"



// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


// getName:

void getName(struct Name * name) {
	char choice;
	printf("Please enter the contact's first name: ");
	scanf(" %s", name->firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &choice);
	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %s", name->middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf(" %s", name->lastName);
};

// getAddress:

void getAddress(struct Address * address) {
	char choice;
	printf("Please enter the contact's street number: ");
	scanf(" %d", &address->strtNum);
	printf("Please enter the contact's street name: ");
	scanf(" %s", address->strt);
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &choice);
	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf(" %d", &address->aprtNum);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]", address->postal);
	printf("Please enter the contact's city: ");
	scanf(" %s", address->city);
};

// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable

void getNumbers(struct Numbers * numbers) {
	char choice;
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &choice);
	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		getTenDigitPhone(numbers->cell);
	}
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &choice);
	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &choice);
	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
};

// getContact

void getContact(struct Contact * contact) {

}