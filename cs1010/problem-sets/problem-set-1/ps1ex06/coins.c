// CS1010 Programming Methodology
// Problem Set 1 Exercise #06: coins.c
//
// Program reads in an amount, and finds the least number of S$1,
// 50-,20-,10-,5-, and 1-cent coints to use that reflects that amount
//
// SHEIKH UMAR

#include <stdio.h>

int main(void)
{
	int num, remaining, total;
	int num_1d, num_50c, num_20c, num_10c = 0, num_5c, num_1c; // initialise num_10c to prevent warnings from compiler

	printf("Enter amount in cents: ");
	scanf("%d", &num);

	// Find number of S$1 to use by dividing amount by 100
	num_1d = (num / 100);
	
	// Calculate, if any, remainder of num / 100.
	// To use for calculating number of 50c, 20c, 10c, 5c, 1c coins
	remaining = (num % 100);

	// Calculate number of 50c required
	num_50c = (remaining / 50);
	
	// Calculate, if any, remainder of num / 50.
	// To use for calculating number of 20c, 10c, 5c, 1c coins
	remaining = (remaining % 50);

	// Calculate number of 20c required
	num_20c = (remaining / 20);
	
	// Calculate, if any, remainder of num / 20.
	// To use for calculating number of 10c,5c,1c coins
	remaining = (remaining % 20);

	if (remaining < 10)
	{
		// Calculate number of 5c required
		num_5c = (remaining / 5);
		
		// Calculate, if any, remainder of num / 5.
		// To use for calculating number of 1c coins
		remaining = (remaining % 5);

		// Calculate number of 1c required
		num_1c = remaining;
	}
	else
	{
		// Calculate number of 10c required
		num_10c = (remaining / 10);
		
		// Calculate, if any, remainder of num / 10.
		// To use for calculating number of 5c,1c coins
		remaining = (remaining % 10);

		// Calculate number of 5c required
		num_5c = (remaining / 5);
		
		// Calculate, if any, remainder of num / 5.
		// To use for calculating number of 1c coins
		remaining = (remaining % 5);

		// Calculate number of 1c required
		num_1c = remaining;
	}

	total = (num_1d + num_50c + num_20c + num_10c + num_5c + num_1c);
	printf("Minimum number of coins needed: %d\n", total);

	return 0;
}

