// CS1010 Programming Methodology
// Problem Set 1 Exercise #05: investment.c
//
// Program takes in positive integers principal, rate and num_years
// and computes the amount of money earned after num_years years
// in 2 decimal places
//
// SHEIKH UMAR

#include <math.h>
#include <stdio.h>

int main(void) 
{
	double amount; // Amount of money earned after num_years
	int principal, rate, num_years;

	printf("Enter principal amount: ");
	scanf("%d", &principal);

	printf("Enter interest rate   : ");
	scanf("%d", &rate);

	printf("Enter number of years : ");
	scanf("%d", &num_years);

	double new_rate = (double) (rate / 100.00);
	amount = (principal * (1 - pow(new_rate, (num_years + 1)))) / (1 - (new_rate));
	
	printf("Amount = $%.2lf\n", amount);

	return 0;
}
