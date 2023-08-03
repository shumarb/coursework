// CS1010 Programming Methodology
// Problem Set 4 Exercise #23: my_power.c
//
// This program computes the nth power of x,
// where n is a non-negative integer.
//
// SHEIKH UMAR

#include <stdio.h>

double my_pow(double x, int n);

int main(void)
{
	/** main function is complete **/
	double x;
	int n;

	printf("Enter x and n: ");
	scanf("%lf %d", &x, &n);
	printf("my_pow(%.1f, %d) = %.2f\n", x, n, my_pow(x, n));

	return 0;
}

// Recursively compute x to the power of n
double my_pow(double x, int n)
{
	// Base cases: n=0,n=1;
	if(n == 0)
	{
		return 1;
	}
	else
	{
		return (x * (my_pow(x, n - 1)));
	}
}

