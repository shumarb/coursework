// CS1010 Programming Methodology
// Problem Set 2 Exercise #14: power_of_3.c
//
// Program reads in a start and end number, computes and 
// prints out total number of numbers that are power of 3.

#include <stdio.h>
#include <math.h>

int count_numbers(int start, int end);

int main(void)
{
	int start, end;

	printf("Enter start and end: ");
	scanf("%d %d", &start, &end);

	printf("Answer = %d\n", count_numbers(start, end));
	return 0;
}

// Count the number of integers from start to
// end (both inclusive) which are power of 3
int count_numbers(int start, int end)
{
	int counter = 0;
	int num = 1;
	
	// Use while loop to keep running up to end
	// Start number must be >=1, as smallest number of power of 3 = 3^0 = 1.
	// End number must be <=1. If end=1, smallest number of power of 3 = 3^0 = 1.
	while((num <= end) && (start >= 1))
	{
		// Check that num is greater>=3 is true.
		// 3 is starting point as it is the first number of power of 3
		if (num >= start)
		{
			counter++;
		}
		num *= 3;
	}
	
	return counter;
}

