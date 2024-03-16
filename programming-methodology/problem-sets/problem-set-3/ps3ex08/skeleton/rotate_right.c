// CS1010 Programming Methodology
// Problem Set 3 Exercise #08: rotate_right.c
//
// This program rotates the given array
// k positions to the right, where k is
// a positive integer.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX_LEN 100 

void rotate_right_k(int arr[], int size, int k);
void rotate_right_1(int arr[], int size);
void print_array(int arr[], int size);

int main(void) {

	printf("Enter the number of elements: ");

	printf("Enter  elements: ");

	printf("Enter k: ");

	//rotate_right_k();

	//print_array();

	return 0;
}

// Rotate the array elements
// to the right by k positions
void rotate_right_k(int arr[], int size, int k) {
	// stub
}

// Rotate the array elements
// to the right by 1 position
void rotate_right_1(int arr[], int size) {
	// stub
}

// Print an array in sequence
// complete and given
void print_array(int arr[], int length) {

	int i;

	printf("[");
	for (i = 0; i < length-1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d]\n", arr[length-1]);
}
