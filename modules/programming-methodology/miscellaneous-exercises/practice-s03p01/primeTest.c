// primeTest.c
// To check if a number is prime.
//
// SHEIKH UMAR
#include <stdio.h>

int is_prime(int);

int main(void) {    
	int value;

	printf("Enter a positive integer: ");
	scanf("%d", &value);

	if (is_prime(value)) 
		printf("%d is a prime.\n", value);
	else
		printf("%d is not a prime.\n", value);

	return 0;
}

// Function determines if a number is a prime number.
// Precond: User entered a positive integer
int is_prime(int n) {
	// 1 is not a prime number
	if (n == 1)
	{
		return 0;
	}

	int i;
	for (i = 2; i <= (n / 2); i++)
	{
		// if number is divisible by a number other than itself
		// (every positive integer is divisible by 1)
		// then n is not a prime number
		if ((n % i) == 0)
		{
			return 0;
		}
	}

	return 1;
}

