// CS1010 Programming Methodology
// Problem Set 3 Exercise #02: exist.c
//
// This program reads an array of integers
// and another integer k, checks if k exists
// in the array.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX_SIZE 10

int contains(int arr[], int size, int k);

int main(void) {

	// define array according to the max size
	int size, arr[MAX_SIZE];

	printf("Enter the number of elements: ");
	scanf("%d", &size); // read size of array

	printf("Enter %d elements: ", size);


	printf("Enter k: ");

	printf(" is in the given array\n");
	printf(" is not in the given array\n");

	return 0;
}

// Take an array 'arr' of 'size' elements,
// check if k exists in the array.
// Return 1 if so, 0 otherwise
int contains(int arr[], int size, int k) {

	return 0;  // stub
}
