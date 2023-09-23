// CS1010 Programming Methodology
// Problem Set 4 Exercise #25: contains.c
//
// This program checks if digit k appears
// in integer number.
//
// SHEIKH UMAR

#include <stdio.h>

int contains(int, int);

int main(void)
{
	/** main function is complete **/

	int number, k;

	printf("Enter a positive integer: ");
	scanf("%d", &number);

	printf("Enter a single digit integer k: ");
	scanf("%d", &k);

	if (contains (number, k)) 
	{
		printf("%d appears in %d\n", k, number);
	}
	else
	{
		printf("%d doesn't exist in %d\n", k, number);
	}

	return 0;
}

// Recursive function to check if num contains k
// Return 1 if so or 0 otherwise
// Given num is positive initially
int contains(int num, int k)
{
	if (num < 10)
	{
		if (num == k)
		{
			return 1;
		}

		return 0;
	}
	else
	{
		if ((num % 10) == k)
		{
			return 1;
		}

		return contains(num / 10, k);
	}
}
