// CS1010 Programming Methodology
// Problem Set 4 Exercise #17: roster.c
//
// This program reads student number and major,
// and prints out the student roster in
// ascending order of student number.
//
// <Replace this with your name>

#include <stdio.h>
#include <string.h>
#define NUM_STUD 1000  // max 1000 students in class 

typedef struct {
	char number[10];    // student number
	char major[15]; 
} student_t;

int read_roster(student_t roster[]);
void sort_roster(student_t roster[], int size);
void print_roster(student_t roster[], int size);

int main(void) {

	int size;  // actual number of students
	student_t roster[NUM_STUD]; // class roster

	// read student info.
	size = read_roster(roster);

	// sort roster accoding to ascending order of student
	sort_roster(roster, size);

	// print roster
	print_roster(roster, size);

	return 0;
}

// Read student and major of students into array 'roster',
// return the number of students read.
int read_roster(student_t roster[]) {


	printf("Enter the number of students in class: ");

	printf("Enter student number and major of each student:\n");

	return 0;  // stub
}

// Sort roster according to ascending order of student number
void sort_roster(student_t roster[], int size) {

	// note: how do you compare two student numbers
	// which are strings?

}

// Print the roster
// Complete and given
void print_roster(student_t roster[], int size) {

	int i;

	printf("Sorted list:\n");
	for (i = 0; i < size; i++) {
		printf("%-10s%-12s\n", roster[i].number, roster[i].major);
	}
}
