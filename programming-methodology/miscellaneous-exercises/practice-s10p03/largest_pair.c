// largest_pair.c
// Read a positive integer and determine the largest digit pair
// in the integer.
//
// SHEIKH UMAR
#include <stdio.h>

int largest_digit_pair(int);

int main(void) {
	int num;

	printf("Enter positive integer: ");
	scanf("%d", &num);

	printf("Largest pair of digits in %d is %d\n", num, largest_digit_pair(num));
	return 0;
}

// Find the largest digit pair in n
// Precond: n > 0
int largest_digit_pair(int n) {

	// Base case: n == 0, so pair of number formed is 0, hence return 0
	if (n == 0)
	{
		return 0;
	}

	// Recursive case: compare pair of last 2 digits
	// and compare this pair to the next pair of digits of n after removing the last 2 digits
	// and return the larger pair
	if (( n % 100) > largest_digit_pair(n / 100))
	{
		return (n % 100);
	}

	return largest_digit_pair(n / 100);
}

