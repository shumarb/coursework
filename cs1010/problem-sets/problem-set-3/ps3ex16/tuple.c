// CS1010 AY2013/4 Semester 2
// Problem Set 3 Exercise #16: tuple.c
//
// This program checks if there is at least a pair
// of integers in a sorted array whose sum equals key.
//
// SHEIKH UMAR

#include <stdio.h>
#define MAX 10

int check_tuple(int arr[], int size, int key);

// main is complete and given
int main(void) {

	int i, size, arr[MAX], key;

	printf("Enter the number of distinct elements in sorted array: ");
	scanf("%d", &size);

	printf("Enter %d elements: ", size);
	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Enter key: ");
	scanf("%d", &key);

	if ( check_tuple(arr, size, key) ) {
		printf("Exist\n");
	} else {
		printf("Not exist\n");
	}

	return 0;
}



// Check if there exist at least a pair
// of integers whose sum equals key.
// Return 1 if so, 0 otherwise
// 'arr' is sorted
int check_tuple(int arr[], int size, int key) {

	int lower_bound = 0, higher_bound = size - 1; // these elements represents indices of arr

	while (lower_bound <= higher_bound) 
	{
		int sum = arr[lower_bound] + arr[higher_bound];
		// Scenario 1: sum of elements == key, this means a pair of elements x + y = key exists
		if (sum == key) 
		{
			return 1;
		} else if (sum < key)

		{	// Scenario 2: sum < key, then increase lower bound
			lower_bound += 1;
		} else
		{
			// Scenario 3: sum > key, then decrease higher bound
			higher_bound -= 1;
		}
		
	}

	return 0;  // stub
}
