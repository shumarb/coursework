// CS1010 Programming Methodology
// Problem Set 3 Exercise #17: sort_three_digits.c
//
// This program sorts a list of integers
// in ascending order of their first 3 digits.
//
// <Replace this with your name>

#include <stdio.h>
#define SIZE 100 

void sort_array(int arr[], int size);
int is_less_than(int num1, int num2);

// main is complete and given
int main(void) {

	int i, num, val[SIZE];

	printf("Enter the number of elements: ");
	scanf("%d", &num);

	printf("Enter %d elements: ", num);
	for (i = 0; i < num; i++) {
		scanf("%d", &val[i]);
	}

	sort_array(val, num);

	printf("Sorted array: [");
	for (i = 0; i < num-1; i++) {
		printf("%d, ", val[i]);
	}
	printf("%d]\n", val[num-1]);

	return 0;
}

// Original selection sort, need to be modified
// to sort integers according to the first 3 digits
void sort_array(int arr[], int size) {

	int i, start_idx, min_idx, temp;

	for (start_idx = 0; start_idx < size-1; start_idx++) {
		min_idx = start_idx;
		for (i = start_idx+1; i < size; i++) {
			if (arr[i] < arr[min_idx]) {
				min_idx = i;
			}
		}
		temp = arr[start_idx];
		arr[start_idx] = arr[min_idx];
		arr[min_idx] = temp;
	}
}

// Compare integers according to first 3 digits,
// return 1 if first argument is smaller, 0 otherwise
int is_less_than(int num1, int num2) {

	return 0;  // stub
}
