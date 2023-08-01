// CS1010 Programming Methodology
// Problem Set 3 Exercise #01: reverse_print.c
//
// This program reads a list of numbers
// and print them out reversely.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX_SIZE 10

int main(void) {

	// define array according to the max size
	int size, arr[MAX_SIZE];

	printf("Enter the number of integers: ");
	scanf("%d", &size);

	printf("Enter %d integers: ", size);

	/*
		 You may
		 (1) read and store an integer into array directly, or
		 (2) use a variable to hold the input temporarily,
	    	 and assign it to an array slot thereafter.
		 The first way is more commonly used
	 */

	printf("Reverse printing: ");


	return 0;
}
