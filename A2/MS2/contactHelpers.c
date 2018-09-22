/* -------------------------------------------
Name: Angadpreet Baidwan
Student number: 135421170
Email: abaidwan1@myseneca.ca
Section: P
Date: March 24, 2018
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt: Empty function definition goes here:
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

// getIntInRange: Empty function definition goes here:
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

// yes: Empty function definition goes here:
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

// menu: Empty function definition goes here:
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

// ContactManagerSystem: Empty function definition goes here:
void ContactManagerSystem(void) {
	int option, exit = 0;
	do {
		option = menu();
		if (option >= 1 && option <= 6) {
			printf("\n<<< Feature %d is unavailable >>>\n\n", option);
			pause();
			printf("\n");
		}
		else if (option == 0) {
			printf("\nExit the program? (Y)es/(N)o: ");
			exit = yes();
			printf("\n");
		}
	} while (exit != 1);
	printf("Contact Management System: terminated\n");
}