// CS1010 Programming Methodology
// Problem Set 4 Exercise #22: conway.c
//
// This program prints conway sequence a(n).
//
// SHEIKH UMAR

#include <stdio.h>

int a(int);

int main(void)
{
	/** main function is complete **/

	int n;

	printf("Enter n (n>0): ");
	scanf("%d", &n);

	printf("a(n) = %d\n", a(n));

	return 0;
}

// Compute a(n) according to
// the recursive formula
int a(int n)
{
	if (n >= 1 && n <= 2)
	{
		return 1;
	}
	
	return a(a(n - 1)) + a(n - a(n - 1));
}
