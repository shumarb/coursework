// CS1010 Programming Methodology
// Problem Set 3 Exercise #12: containment.c
//
// This program checks if set A is
// contained in set B.
//
// SHEIKH UMAR

#include <stdio.h>
#define MAX 9

void scan_array(int [], int);
int is_subset(int [], int, int [], int);

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
	int i;
	printf("\tEnter %d values: ",size);
	for (i = 0; i < size; i++) {
		scanf("%d",&arr[i]);
	}
}	

// Check whether arrA is a subset of arrB.
int is_subset(int arrA[], int sizeA, int arrB[], int sizeB) {
	int i, j, count = 0;
	for (i = 0; i < sizeA; i++) {
		for (j = 0; j < sizeB; j++) {
			if (arrA[i] == arrB[j]) {
				count++;
			}
		}
	}
	return count == sizeA; 
}
