// sum_digits_recursion.c
// This program reads a non-negative integer and calls
// a recursive function to sum up all digits in that integer.
// 
// SHEIKH UMAR
#include <stdio.h>

int sumDigits(int);

int main(void) {
	int num;

	printf("Enter a non-negative integer: ");
	scanf("%d", &num);

	printf("Sum of its digits = %d\n", sumDigits(num));

	return 0;
}

// Return sum of digits in n
// Precond: n >= 0
int sumDigits(int n) {

	// Base case: n == 0. This means n has no digits left, so return 0.
	if (n == 0)
	{
		return 0;
	}

	// Recursive case: n >= 0, so return (last digit) + recursive call of sum(n without last digit)
	return ((n % 10) + sumDigits(n / 10));
}

