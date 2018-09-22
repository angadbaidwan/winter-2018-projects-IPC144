/* -------------------------------------------
Name: Angadpreet Baidwan
Student number: 135421170
Email: abaidwan1@myseneca.ca
Section: P
Date: March 12, 2018
----------------------------------------------
Assignment: 1
Milestone:  3
---------------------------------------------- */

// Structure type Name declaration

struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code from Milestone #2 here...

struct Address {
	int strtNum;
	char strt[41];
	int aprtNum;
	char postal[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code from Milestone #2 here...

struct Numbers {
	char cell[21];
	char home[21];
	char business[21];
};

// Structure type Contact declaration
// Place your code here...

struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};