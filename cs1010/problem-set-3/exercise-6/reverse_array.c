// CS1010 Programming Methodology
// Problem Set 3 Exercise #06: reverse_array.c
//
// This program accepts an array of integers
// and reverse all data in the array
// SHEIKH UMAR A0149874L

#include <stdio.h>
#define MAX_LEN 20

int read_array(int arr[]);
void reverse_array(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{
	int num, arr[MAX_LEN];
	num = read_array(arr);
	reverse_array(arr, num);
	print_array(arr, num);
	return 0;
}

// Read in an array, return its size
int read_array(int arr[])
{
	int i, size;
	printf("How many values in array? ");
	scanf("%d", &size);

	printf("Enter %d values: ", size);
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	return size;
}

// Reverse all elements in an array
void reverse_array(int arr[], int size)
{
	int temp, low = 0, high = (size - 1);

	while (low < high)
	{
		temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;
		low += 1;
		high -= 1;
	}
}

// Print an array in sequence
// complete and given
void print_array(int arr[], int size)
{
	int i;
	printf("Reversed: ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

