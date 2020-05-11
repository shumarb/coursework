// CS1010 Programming Methodology
// Problem Set 3 Exercise #07: find_twice.c
//
// This program checks if any integer
// is repeated in an array and if so,
// reports the first duplicated integer.

#include <stdio.h>
#include <math.h>
#define MAX_LEN 10 

int find_twice(int arr[], int size);
void reads_integers(int arr[], int size);

int main(void)
{
	int size, arr[MAX_LEN];

	printf("Enter the number of elements: ");
	scanf("%d", &size);

	reads_integers(arr, size);

	if(find_twice(arr, size) == -1)
	{
		printf("Array doesn't contain repeated data\n");
	}
	else
	{
		printf("%d is the first repeated integer\n", find_twice(arr, size));
	}
	
	return 0;
}

// Reads elements from user
// and stores it in array
void reads_integers(int arr[], int size)
{
	int i;
	printf("Enter %d elements: ", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
}

// Find the first repeated element. 
// Return index of its first appearance
// if found, or -1 otherwise
int find_twice(int arr[], int size)
{
	int i, j;

	for(i = 0; i < (size - 1); i++)
	{
		for(j = (i + 1); j < size; j++)
		{
			if(arr[i] == arr[j])
			{
				return arr[i];
			}
		}
	}
	
	return (-1);
}

