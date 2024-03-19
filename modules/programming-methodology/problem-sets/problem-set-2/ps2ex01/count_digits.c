// CS1010 Programming Methodology
// Problem Set 2 Exercise #01: count_digits.c
//
// Program reads in an integer, and display its number of digits
//
// SHEIKH UMAR

#include <stdio.h>

int range(int);

int main(void)
{
	int num;
	printf("Enter a positive integer: ");
	scanf("%d", &num);

	printf("Number of digits = %d\n", range(num));
	
	return 0;
}


// Function determines number of digits that num has
int range(int num)
{
	int digit;

	if (num < 10)
	{
		digit = 1;
	}

	if ((num >= 10) && (num < 100))
	{
		digit = 2;
	}

	if ((num >= 100) && (num < 1000))
	{
		digit = 3;
	}
	
	if ((num >= 1000) && (num < 10000))
	{
		digit = 4;
	}

	else if ((num >= 10000) && (num < 100000))
	{
		digit = 5;
	}

	if ((num >= 100000) && (num < 1000000))
	{
		digit = 6;
	}
	
	if ((num >= 1000000) && (num < 10000000))
	{
		digit = 7;
	}

	return digit;
}
