// CS1010 Programming Methodology
// Problem Set 3 Exercise #20: union.c
//
// This program reads two sets of distinct integers
// and prints out the union of two sets.
//
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 10

int read_array(int set[], char *index);
int get_union(int setA[], int sizeA, int setB[], int sizeB);
int exist(int arr[], int size, int val);
void sort_array(int set[], int size);
void print_array(int set[], int size);  // given

int main(void) {

	int setA[2*MAX], setB[MAX];  // two sets
	int sizeA, sizeB;

	sizeA = read_array(setA, "1st");
	sizeB = read_array(setB, "2nd");

	// update setA to be union of setA and setB
	// return updated size of setA
	sizeA = get_union(setA, sizeA, setB, sizeB);

	// sort setA in ascending order
	sort_array(setA, sizeA);

	print_array(setA, sizeA);

	return 0;
}

// Read elements of a set one by one
int read_array(int set[], char *index) {

	printf("Size of %s set? ", index);

	printf("\tEnter  values: ");

	return 0; // stub
}

// Update setA to be the union of setA and setB
int get_union(int setA[], int sizeA, int setB[], int sizeB) {

	return 0; // stub
}

// Return 1 if val exists in arr, or 0 otherwise
int exist(int arr[], int size, int val) {

	// this function is also suggested
	// which makes coding easier

	return 0; // stub
}

// Sort array in ascending order of elements
void sort_array(int set[], int size) {

	// stub
}

// Print elements of array
void print_array(int set[], int size) {

	int i;

	printf("Union of two sets is (in ascending order):");
	for (i = 0; i < size; i++) {
		printf(" %d", set[i]);
	}
	printf("\n");
}
