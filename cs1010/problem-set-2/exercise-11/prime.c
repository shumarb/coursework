// CS1010 Programming Methodology
// Problem Set 2 Exercise #11: prime.c
//
// Program reads in a number,
// checks if it is divisible by any number between 2 and a number-1.
// If yes, number is not prime.
// If no, or number is 1, number is not prime.
// Print out outcome on whether number is a prime.

#include <stdio.h>

int is_prime(int num);

int main(void)
{
	int num;

	printf("Enter a positive integer: ");
	scanf("%d", &num);

	// Number is not prime if it is 1.
	if(num == 1)
	{
		printf("%d is not a prime\n",num);
	}
	else
	{
		answer = is_prime(num);
		
		if(is_prime(num) == 0)
		{
			printf("%d is a prime\n", num);
		}
		else
		{
			printf("%d is not a prime\n", num);
		}
	}

	return 0;
}

// Function checks if a number is a prime number,
// and returns a non-negative value.
int is_prime(int num)
{
	int i;
	int counter = 0;

	for(i = 2; i <= (num - 1); i++)
	{
		// Number is a prime if it leaves a remainder (modulo division = 0)
		if((num % i) == 0)
		{
			counter++;
		}
	}
	return counter;
}

