// CS1010 Programming Methodology
// Problem Set 3 Exercise #08: rotate_right.c
//
// This program rotates the given array
// k positions to the right, where k is
// a positive integer.
// SHEIKH UMAR A0149874L

#include <stdio.h>
#define MAX_LEN 100

void rotate_right_k(int arr[], int size, int k);
void rotate_right_1(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{
	int arr[MAX_LEN], i, k, size;
	
	printf("Enter the number of elements: ");
	scanf("%d", &size);
	
	printf("Enter %d elements: ", size);
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Enter k: ");
	scanf("%d", &k);
	
	if(size == 1)
	{
		print_array(arr, size);
	}

	else
	{
		rotate_right_k(arr, size, k);
		print_array(arr, size);
	}
	
	return 0;
}

// Rotate the array elements
// to the right by k positions
void rotate_right_k(int arr[], int size, int k)
{
	int i;
	for(i = 1; i <= k; i++)
	{
		rotate_right_1(arr, size);
	}
}

// Rotate the array elements
// to the right by 1 position
void rotate_right_1(int arr[], int size)
{
	int new_arr[MAX_LEN], i;

	for(i = 1; i < size - 1; i++)
	{
		new_arr[i] = arr[i - 1];
	}
	new_arr[0] = arr[size - 1];
	new_arr[size - 1] = arr[size - 2];

	for(i = 0; i < size; i++)
	{
		arr[i] = new_arr[i];
	}
}

// Print an array in sequence
// complete and given
void print_array(int arr[], int length)
{
	int i;
	printf("[");
	for (i = 0; i < length - 1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d]\n", arr[length - 1]);
}

