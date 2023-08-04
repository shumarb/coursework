// CS1010 Programming Methodology
// Problem Set 2 Exercise #16: print_square.c
//
// Program reads in a number, and prints out a square
// that is of the size of the number.
//
// SHEIKH UMAR
#include <stdio.h>

int main(void)
{
	int i, j, k;

	printf("Enter k: ");
	scanf("%d", &k);

	// Case 1: k = 2
	// Must hardcode as square where k = 2 has no space
	if(k == 2)
	{
		printf("**\n");
		printf("**\n");
	}
	else
	{
		// First line
		for(i = 1; i <= k; i++)
		{
			printf("*");
		}
		printf("\n");

		// Second line to second-last line
		for(i = 2; i <= (k-1); i++)
		{
			printf("*");
			for(j = 2; j <= (k-1); j++)
			{
				printf(" ");
			}
			printf("*");
			printf("\n");
		}

		// print last line
		for(i = 1; i <= k; i++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}

