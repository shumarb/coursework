// CS1010 Programming Methodology
// Problem Set 3 Exercise #02: exist.c
//
// This program reads an array of integers
// and another integer k, checks if k exists
// in the array.
// SHEIKH UMAR A0149874L

#include <stdio.h>
#define MAX_SIZE 10

int contains(int arr[], int size, int k);

int main(void)
{
	// define array according to the max size
	int i, k, size;
	int arr[MAX_SIZE];
	
	printf("Enter the number of elements: ");
	scanf("%d", &size); // read size of array
	
	printf("Enter %d elements: ", size);
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter k: ");
	scanf("%d", &k);

	if(contains(arr, size, k) == 1)
	{
		printf("%d is in the given array\n", k);
	}
	else
	{
		printf("%d is not in the given array\n", k);
	}

	return 0;
}

// Take an array 'arr' of 'size' elements,
// check if k exists in the array.
// Return 1 if so, 0 otherwise
int contains(int arr[], int size, int k)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(arr[i] == k)
		{
			return 1;
		}
	}

	return 0;
}

