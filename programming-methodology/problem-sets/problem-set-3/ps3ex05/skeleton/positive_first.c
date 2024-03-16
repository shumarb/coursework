// CS1010 Programming Methodology
// Problem Set 3 Exercise #05: positive_first.c
//
// This program tests if all the positive
// number (if any) appear before all the
// non-positive numbers (if any) in an array.
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
#define MAX_LEN 9 

int is_positive_first(int numbers[], int size);

int main(void) {


	printf("Enter the number of elements: ");

	printf("Enter  elements: ");

	printf("All positive numbers appear before non-positive numbers\n");
	printf("Some positive numbers appear after non-positive numbers\n");

	return 0;
}

// Return 1 if all positive numbers appear before
// any non-positive numbers, or 0 otherwise
int is_positive_first(int numbers[], int size) {

	return 1;  // stub
}
