// CS1010 Programming Methodology
// Problem Set 3 Exercise #05: positive_first.c
//
// This program tests if all the positive
// number (if any) appear before all the
// non-positive numbers (if any) in an array.
// SHEIKH UMAR A0149874L

#include <stdio.h>
#include <math.h>
#define MAX_LEN 9 

int is_positive_first(int numbers[], int size);

int main(void)
{
	int size, numbers[MAX_LEN];

	printf("Enter the number of elements: ");
	scanf("%d", &size);

	if(is_positive_first(numbers, size) == 1)
	{
		printf("All positive numbers appear before non-positive numbers\n");
	}
	else
	{
		printf("Some positive numbers appear after non-positive numbers\n");
	}
	return 0;
}

// Return 1 if all positive numbers appear before
// any non-positive numbers, or 0 otherwise
int is_positive_first(int numbers[], int size)
{
	int i, j; 

	printf("Enter %d elements: ", size);
	for(i = 0; i < size; i++)
	{
		scanf("%d", &numbers[i]);
	}

	for(i = 0; i < (size - 1); i++)
	{
		if(numbers[i] <= 0)
		{
			for(j = (i + 1); j < size; j++)
			{
				if(numbers[j] > 0)
				{
					return 0; // A positive number found after non-negative number
				}
			}
		}
	}
	
	return 1;
}

