// CS1010 Programming Methodology
// Problem Set 2 Exercise #15: pattern.c
//
// Program reads in a number, and prints out a pattern
// that corresponds to the number.

#include <stdio.h>

int main(void)
{
	int count, i, j, k = 0; 

	printf("Enter count: ");
	scanf("%d", &count);

	for(i = 1; i <= count; i++)
	{
		printf("#");
		k++;
		for(j = 1; j <=k; j++)
		{
			printf("-");
		}
	}
	printf("\n");
	return 0;
}

