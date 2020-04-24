// CS1010 Programming Methodology
// Problem Set 1 Exercise #05: investment.c
//
// Program takes in positive integers principal, rate and num_years
// and computes the amount of money earned after num_years years
// in 2 decimal places

#include <stdio.h>
#include <math.h>

int main(void) {

	int principal, rate, num_years;
	double amount; //Amount of money earned after num_years

	printf("Enter principal amount: ");
	scanf("%d", &principal);

	printf("Enter interest rate   : ");
	scanf("%d", &rate);

	printf("Enter number of years : ");
	scanf("%d", &num_years);

	// rate is in integer. Hence, rate/100 = 0 (nearest integer is rate<100)
	// Hence, create new variable that stores rate as a double
	double new_rate = (double) (rate / 100.00);

	// Create new variable to store value of num_years increased by 1
	int new_num_years = (num_years + 1);

	// Calculation to find amount
	amount = (principal * (1 - pow(new_rate, new_num_years))) / (1 - (new_rate));

	// Print out result
	printf("Amount = $%.2lf\n", amount);

	return 0;
}

