// CS1010 Programming Methodology
// Problem Set 2 Exercise #04: perfect_number.c
//
// Program reads in a number, checks its number of divisors,
// and checks if the sum of these divisors = num.
// If it is a perfect number.
//
// SHEIKH UMAR

#include <stdio.h>

int main(void) {
	int i, n;
	int sum = 0;
	
	printf("Enter a positive integer: ");
	scanf("%d", &n);

	// Sum: Add up the multiples of n
	for(i = 1; i <= (n / 2); i++)
	{
		if((n % i) == 0)
		{
			sum += i;
		}
	}

	// if sum = n. If yes, it is a perfect number
	if(n == sum)
	{
		printf("%d is a perfect number.\n", n);
	}
	else
	{
		printf("%d is not a perfect number, its sum of proper divisors is %d.\n", n, sum);
	}
	return 0;
}

