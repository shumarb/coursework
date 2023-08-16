// countPrimes.c
// To count the number of primes in the range [1, limit]
// where limit is entered by user.
// 
// SHEIKH UMAR
#include <stdio.h>

int is_prime(int);

int main(void) {    
	int limit;

	printf("Enter limit: ");
	scanf("%d", &limit);

	printf("Number of primes (1-%d): %d\n", limit, is_prime(limit));

	return 0;
}

// Function determines if a number is a prime number.
// Precond: User entered a positive integer.
int is_prime(int n) {
	int i, j, num_primes = 0;
	for (i = 2; i < n; i++)
	{	
		// assume i is a prime number.
		int is_prime = 1;
		for (j = 2; j <= (i / 2) && is_prime; j++)
		{
			// if i is divisible by a number between 1 to it's midpoint (i / 2)
			// then i is not a prime number.
			if ((i % j) == 0)
			{
				is_prime = 0;
			}
		}

		// i is not divisible by any number other than 1 and itself
		// hence it is a prime number.
		if (is_prime)
		{
			num_primes++;
		}
	}

	return num_primes;
}

