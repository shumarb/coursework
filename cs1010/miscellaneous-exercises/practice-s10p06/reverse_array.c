// reverse_array.c
// Reverse all values in an integer array.
//
// SHEIKH UMAR

#include <stdio.h>
#define MAX_SIZE 15

int readArray(int []);
void printArray(int [], int);
void reverseArray(int [], int, int, int);

int main(void) {
	int list[MAX_SIZE], size;

	size = readArray(list);
	reverseArray(list, size, 0, size - 1);
	
	printArray(list, size);
	
	return 0;
}

// Read values into array.
// Return number of elements read.
int readArray(int arr[]) {
	int size, i;

	printf("Enter number of integers: ");
	scanf("%d", &size);
	printf("Enter integers: ");
	for (i=0; i<size; i++)
		scanf("%d", &arr[i]);

	return size;
}

// Print values in array
void printArray(int arr[], int size) {
	int i;

	printf("Reversed array: ");
	for (i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Reverse all the values in the array arr
// Pre-cond: size >= 1
void reverseArray(int arr[], int size, int first_index, int last_index) {
	if (first_index > last_index)
	{
		return;
	}

	int temp;
	temp = arr[first_index];
	arr[first_index] = arr[last_index];
	arr[last_index] = temp;

	reverseArray(arr, size, first_index + 1, last_index - 1);
}

