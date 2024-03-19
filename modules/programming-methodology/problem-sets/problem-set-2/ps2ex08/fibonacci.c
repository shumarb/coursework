// CS1010 Programming Methodology
// Problem Set 2 Exercise #08: fibonacci.c
//
// Program reads in a number(n),
// and prints out the nth number in th fibonacci sequence.
//
// SHEIKH UMAR

#include <stdio.h>

int fib(int);

int main(void)
{
	int n;
	
	printf("Enter n: ");
	scanf("%d", &n);

	printf("%d\n", fib(n));

	return 0;
}

// Calculate fibonacci number
int fib(int n)
{
	if ((n == 1) || (n == 2))
	{
		return 1;
	}

	// Run a for loop that determines the fibonacci number of n
	// by (n-2) & (n-1) fibonacci numbers.
	int fibonacci_number = 0, i;
	for (i = n - 2; i < n; i++)
	{
		fibonacci_number += fib(i);
	}
	
	return fibonacci_number;
}
