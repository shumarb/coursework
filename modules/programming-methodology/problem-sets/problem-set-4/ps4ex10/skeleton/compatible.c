// CS1010 Programming Methodology
// Problem Set 4 Exercise #10: compatible.c
//
// This program removes common characters
// in two names, ignoring cases. Then check
// whether the remains two strings both have
// odd or even characters.
//
// <Replace this with your name>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Name has at most 35 characters
#define MAXLEN 36

void read_name(char name[]);
void match(char name1[], char name2[], int *count1_p, int *count2_p);

int main(void) {

	char name1[MAXLEN], name2[MAXLEN];
	int remain1, // number of remaining letters in name1 
			remain2; // and name2 after matching

	printf("Enter 2 names below:\n");
	read_name(name1); // do not remove/change this line
	read_name(name2); // do not remove/change this line

	// Call the match() function here


	printf("Number of letters remaining in 1st name = %d\n", 
			remain1);
	printf("Number of letters remaining in 2nd name = %d\n",
			remain2);

	printf("The names are compatible.\n");

	printf("The names are not compatible.\n");

	return 0;
}

// Read a name (may contain spaces) using fgets
void read_name(char name[]) {

	// stub 

}

// We cross out common characters from both names,
// and return the number of remaining letters in both names.
void match(char name1[], char name2[], int *count1_p,
		int *count2_p) {

	// stub 

}
