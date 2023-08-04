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
	int answer =0;
	if((n == 1)||(n == 2))
	{
		answer = 1;
	}
	else
	{
		int i;

		// Run a for loop that determines the fibonacci number of n
		// by (n-2) & (n-1) fibonacci numbers.
		for(i = (n-2); i < n; i++)
		{
			answer += fib(i);
		}
	}

	return answer;
}

