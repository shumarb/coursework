// CS1010 Programming Methodology
// Problem Set 3 Exercise #12: containment.c
//
// This program checks if set A is
// contained in set B.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 9

void scan_array(int arr[], int size);
int is_subset(int arrA[], int sizeA, int arrB[], int sizeB);

int main(void) {

	int arrA[MAX], sizeA, arrB[MAX], sizeB;

	printf("Size of 1st array? ");
	scanf("%d", &sizeA);
	scan_array(arrA, sizeA);

	printf("Size of 2nd array? ");
	scanf("%d", &sizeB);
	scan_array(arrB, sizeB);

	if ( is_subset(arrA, sizeA, arrB, sizeB) ) {
		printf("1st array is a subset of 2nd array\n");
	} else {
		printf("1st array is not a subset of 2nd array\n");
	}

	return 0;
}

// Read values into array
void scan_array(int arr[], int size) {

	printf("\tEnter  values: ");
}

// Check whether arrA is a subset of arrB.
int is_subset(int arrA[], int sizeA, int arrB[], int sizeB) {

	return 0;  // stub
}
