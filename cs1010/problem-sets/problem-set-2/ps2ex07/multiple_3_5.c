// CS1010 Programming Methodology
// Problem Set 2 Exercise #07: multiple_3_5.c
//
// Program reads in a number, calculates number of multiples of 3 between 1 to number,
// then calculates number of multiples of 5 between 1 to number, 
// adds these numbers and prints out its sum.
//
// SHEIKH UMAR

#include <stdio.h>

int multiple(int);

int main(void)
{
	int num;

	printf("Enter n: ");
	scanf("%d",&num);

	printf("%d\n", multiple(num));

	return 0;
}

int multiple(int num)
{
	int i, mul_3 = 0, mul_5 = 0;
	
	for (i = 3; i < num; i++)
	{
		if ((i % 3) == 0)
		{
			mul_3++;
		}
	}

	for (i = 3; i < num; i++)
	{
		// Ensure number is a multiple of 5 and not a multiple of 3.
		// This is to prevent counting a number twice.
		// Example: if num is 16, 15 will be counted in both for loops without the condition above.
		if (((i % 5) == 0) && ((i % 3) != 0))
		{
			mul_5++;
		}
	}
	//printf("%d %d\n",mul_3,mul_5);
	
	return (mul_3 + mul_5);
}
