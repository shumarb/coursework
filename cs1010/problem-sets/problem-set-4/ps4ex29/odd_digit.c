// CS1010 Programming Methodology
// Problem Set 4 Exercise #29: odd_digit_sum.c
//
// This program checks whether the sum of
// all digits is odd.
//
// SHEIKH UMAR

#include <stdio.h>

int is_sum_odd(int);

int main(void)
{
	int number;

	printf("Enter a positive integer: ");
	scanf("%d", &number);

	printf("Sum of digits for %d", number);

	// Let sum represent the sum of odd and even digits in a number
	// Increase sum by 1 only for every odd digit in a number
	// If sum is an odd number, then the number is odd
	// else, it is not an odd number
	if (is_sum_odd(number) % 2 != 0)
	{
		printf(" is odd\n");
	}
	else
	{
		printf(" is not odd\n");
	}

	return 0;
}

// Check the sum of all digits,
// return 1 if odd, 0 otherwise.
// Given num is positive initially
int is_sum_odd(int num)
{
	if (num == 0) {
		return 0;
	}
	
	if ((num % 10) % 2 != 0) {
		return 1 + is_sum_odd(num / 10);
	}

	return (num / 10);
}
