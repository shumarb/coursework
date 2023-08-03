// CS1010 Programming Methodology
// Problem Set 4 Exercise #24: square_sum.c
//
// This program reads a positive integer,
// returns the sum of all its digits in square.
//
// SHEIKH UMAR
#include <stdio.h>

int square_sum(int num);

int main(void)
{
	/** main function is complete **/

	int number;

	printf("Enter a positive integer: ");
	scanf("%d", &number);

	printf("Square sum of all digits is %d\n", square_sum(number));

	return 0;
}

// Recursively calculate the square sum
// of all digits in a given number
int square_sum(int num)
{
	int sum = 0;
		if(num < 10)
		{
			return num*num;
		}
		else
		{
			sum += ((num % 10) * (num % 10));
			num /= 10;
			// printf("sum = %d, num = %d\n", sum, num);
			// printf("new sum = %d\n", sum + square_sum(num));
			return (sum + square_sum(num));
	}
}

