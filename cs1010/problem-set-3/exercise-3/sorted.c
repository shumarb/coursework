// CS1010 Programming Methodology
// Problem Set 3 Exercise #03: sorted.c
//
// This program checks whether all the values
// in an array are sorted in non-decreasing order.
// SHEIKH UMAR A0149874L

#include <stdio.h>
#define MAX 10

int is_sorted(int arr[], int size);

int main(void)
{
	int i, size;

	printf("Enter the number of elements: ");
	scanf("%d", &size);

	int arr[size];
	
	printf("Enter %d elements: ", size);
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	if (is_sorted(arr, size))
	{
		printf("Given array is sorted.\n");
	}
	else
	{
		printf("Given array is not sorted.\n");
	}

	return 0;
}

// Check if array is sorted in non-decreasing order.
// Return 1 if true, 0 otherwise.
int is_sorted(int arr[], int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		if(arr[i] > arr[i+1])
		{
			return 0;
		}
	}

	return 1;
}

