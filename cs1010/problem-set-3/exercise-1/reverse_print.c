// CS1010 Programming Methodology
// Problem Set 3 Exercise #01: reverse_print.c
//
// This program reads a list of numbers
// and print them out reversely.
// SHEIKH UMAR A0149874L

#include <stdio.h>
#define MAX_SIZE 10

int main(void)
{
	/*
		 You may
		 (1) read and store an integer into array directly, or
		 (2) use a variable to hold the input temporarily,
		 and assign it to an array slot thereafter.
		 The first way is more commonly used
	 */

	// define array according to the max size
	int i,size, arr[MAX_SIZE];
	printf("Enter the number of integers: ");
	scanf("%d", &size);
	
	printf("Enter %d integers: ", size);
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("Reverse printing: ");
	for(i = (size - 1); i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

