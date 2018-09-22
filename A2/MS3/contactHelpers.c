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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>


// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void) {

}

// pause: Empty function definition goes here:
void pause(void) {

}

// getInt: Empty function definition goes here:
void getInt(void) {

}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int x, int y) {

}

// yes: Empty function definition goes here:
int yes(void) {

}

// menu: Empty function definition goes here:
int menu(void) {

}

// ContactManagerSystem: Empty function definition goes here:
void ContactManagerSystem(void) {

}


// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
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
    return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {

}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int x) {

}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact * contact) {

}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contact[], int x) {

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contact[], int x) {

}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contact[], int x) {

}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contact[], int x) {

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contact[], int x) {

}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contact[], int x) {

}