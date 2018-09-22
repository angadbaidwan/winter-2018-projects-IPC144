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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void) {
	char NL = 'x';
	int value;
	while (NL != '\n') {
		scanf(" %d%c", &value, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return value;
}

// getIntInRange:
int getIntInRange(int x, int y) {
	int val;
	do {
		val = getInt();
		if (val < x || val > y) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", x, y);
		}
	} while (val < x || val > y);
	return val;
}

// yes:
int yes(void) {
	char NL = 'x';
	char ans;
	int out = 2;
	while (NL != '\n' && (out != 0 || out != 1)) {
		scanf(" %c%c", &ans, &NL);
		if (NL == '\n' && (ans == 'y' || ans == 'Y')) {
			out = 1;
		}
		else if (NL == '\n' && (ans == 'n' || ans == 'N')) {
			out = 0;
		}
		else {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	}
	return out;
}

// menu:
int menu(void) {
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");
	return getIntInRange(0, 6);
}

// ContactManagerSystem:
void ContactManagerSystem(void) {
	struct Contact contact[MAXCONTACTS] = { { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
{
	{ "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
{
	{ "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
{
	{ "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
	};

	int option, exit = 0;
	do {
		option = menu();
		printf("\n");
		if (option == 1) {
			displayContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
		}
		else if (option == 2) {
			addContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
		}
		else if (option == 3) {
			updateContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
		}
		else if (option == 4) {
			deleteContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
		}
		else if (option == 5) {
			searchContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
		}
		else if (option == 6) {
			sortContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
		}
		else if (option == 0) {
			printf("Exit the program? (Y)es/(N)o: ");
			exit = yes();
			printf("\n");
		}
	} while (exit != 1);
	printf("Contact Management System: terminated\n");
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	for (i = 0; i < size; i++) {
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
			return i;
		}
	}
	return -1;
}

// displayContactHeader
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int x) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", x);
}

// displayContact:
void displayContact(const struct Contact * contact) {
	if (strlen(contact->name.middleInitial) == 0) {
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}
	else {
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0) {
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contact[], int x) {
	displayContactHeader();
	int i, j = 0;
	for (i = 0; i < x; i++) {
		if (strlen(contact[i].numbers.cell) > 0) {
			displayContact(&contact[i]);
			j++;
		}
	}
	displayContactFooter(j);
}

// searchContacts:
void searchContacts(const struct Contact contact[], int x) {
	printf("Enter the cell number for the contact: ");
	char cellNum[11];
	getTenDigitPhone(cellNum);
	printf("\n");
	int i =	findContactIndex(contact, MAXCONTACTS, cellNum);
	if (i != -1) {
		displayContact(&contact[i]);
		printf("\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
}

// addContact:
void addContact(struct Contact contact[], int x) {
	int i, k = 1;
	for (i = 0; i < x; i++) {
		if (strlen(contact[i].numbers.cell) == 0) {
			getContact(&contact[i]);
			printf("--- New contact added! ---\n");
			i += x;
			k = 0;
		}
	}
	if (k == 1) {
		printf("*** ERROR: The contact list is full! ***\n");
	}
}

// updateContact:
void updateContact(struct Contact contact[], int x) {
	printf("Enter the cell number for the contact: ");
	char cellNum[11];
	getTenDigitPhone(cellNum);
	int i = findContactIndex(contact, MAXCONTACTS, cellNum);
	if (i == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contact[i]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1) {
			contact[i].name.middleInitial[0] = '\0';
			getName(&contact[i].name);
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1) {
			contact[i].address.apartmentNumber = 0;
			getAddress(&contact[i].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) {
			contact[i].numbers.home[0] = '\0';
			contact[i].numbers.business[0] = '\0';
			getNumbers(&contact[i].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contact[], int x) {
	printf("Enter the cell number for the contact: ");
	char cellNum[11];
	getTenDigitPhone(cellNum);
	int i = findContactIndex(contact, MAXCONTACTS, cellNum);
	if (i == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contact[i]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes() == 1) {
			contact[i].numbers.cell[0] = '\0';
			contact[i].numbers.home[0] = '\0';
			contact[i].numbers.business[0] = '\0';
			contact[i].name.middleInitial[0] = '\0';
			contact[i].address.apartmentNumber = 0;
			printf("--- Contact deleted! ---\n");
		}
	}
}

// sortContacts:
void sortContacts(struct Contact contact[], int x) {
	int i, j, m;
	struct Contact temp;

	for (i = 0; i < x; i++) {
		m = i;
		for (j = i + 1; j < x; j++)
			if (strcmp(contact[j].numbers.cell, contact[m].numbers.cell) == -1) {
				m = j;
			}
		if (m != i) {
			temp = contact[i];
			contact[i] = contact[m];
			contact[m] = temp;
		}
	}
	printf("--- Contacts sorted! ---\n");
}