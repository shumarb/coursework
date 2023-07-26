// CS1010 Programming Methodology
// Problem Set 3 Exercise #15: pair.c
//
// This program checks if there exist
// two different array elements whose
// sum equals to the given key.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>
#define MAX 10

int check_pair(int arr[], int size, int key);

// main is complete and given
int main(void)
{
	int arr[MAX], i, key, size;
	printf("Enter the number of distinct elements: ");
	scanf("%d", &size);
	printf("Enter %d elements: ", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter key: ");
	scanf("%d", &key);

	if (check_pair(arr, size, key))
	{
		printf("Exist\n");
	}
	else
	{
		printf("Not exist\n");
	}
	
	return 0;
}

// Check if there exist at least a pair
// of integers whose sum equals key.
// Return 1 if so, or 0 otherwise
// 'arr' is unsorted
int check_pair(int arr[], int size, int key)
{
	int found = 0, i, j;

	for(i = 0; i < (size - 1) && found == 0; i++)
	{
		for(j = i + 1; j < size && found == 0; j++)
		{
			if((arr[i] + arr[j]) == key)
			{
				found = 1;
			}
		}
	}
	return found;
}

