/* -------------------------------------------
Name: Angadpreet Baidwan
Student number: 135421170
Email: abaidwan1@myseneca.ca
Section: P
Date: March 31, 2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name * name) {
	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]", name->firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]", name->middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]", name->lastName);
};

// getAddress:
void getAddress(struct Address * address) {
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]", address->street);
	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]", address->postalCode);
	printf("Please enter the contact's city: ");
	scanf(" %[^\n]", address->city);
};

// getNumbers:
void getNumbers(struct Numbers * numbers) {
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);
	printf("Do you want to enter a home phone number? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
};

// getContact:
void getContact(struct Contact * contact) {
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}