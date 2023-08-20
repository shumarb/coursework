// multiples5or7.c 
// Reads a positive integer num and count the number
// of multiples of 5 or 7 in the range [1, num].
//
// SHEIKH UMAR
#include <stdio.h>

int count_multiples(int);

int main(void) {
	int num, num_multiples;

	printf("Enter positive integer: ");
	scanf("%d", &num);
	
	num_multiples = count_multiples(num);
	if (num_multiples == 0)
	{
		printf("There are no multiples of 5 or 7 in [1,%d].\n", num);
	}
	else if (num_multiples == 1)
	{
		printf("There is 1 multiple of 5 or 7 in [1,%d].\n", num);
	}
	else
	{
		printf("There are %d multiples of 5 or 7 in [1,%d].\n", num_multiples, num);
	}

	return 0;
}

// Precond: value > 0
int count_multiples(int value) {
	int num_multiples = 0, i;

	for (i = 1; i <= value; i++)
	{
		// number is a multiple of 5 or 7 if either
		// 1. it is only a multiple of 5 and not 7
		// 2. it is only a multiple of 7 and not 5
		// 3. it is a multiple of both 5 and 7 only
		if ( ((i % 5) == 0 && (i % 7) != 0) || ((i % 5) != 0 && (i % 7) == 0) || ((i % 5) == 0 && (i % 7) == 0) )
		{
			num_multiples++;
		}
	}

	return num_multiples;
}

