// CS1010 Programming Methodology
// Problem Set 4 Exercise #15: birthday.c
//
// This program reads in a list of birthdays
// and checks if there exists two birthdays
// of the same day and month.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 25

typedef struct {
	int day, month;
} date_t;

int read_birthdays(date_t bday[]);
int share_birthday(date_t bday[], int num);

int main(void) {


	printf("Group of  having same birthday: ");
	printf("Yes\n");
	printf("No\n");

	return 0;
}

// Read in all birthdays
// Return the number of birthdays read
int read_birthdays(date_t bday[]) {

	printf("How many birthdays to input? ");

	printf("Enter birthdays, day followed by month each:\n");

	return 0; // stub
}

// Check if any two birthdays in the array are the same
// Return 1 if so, or 0 otherwise
int share_birthday(date_t bday[], int num) {

	return 0;  // stub
}
