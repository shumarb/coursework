// countNumbers.c
// To count the number of integers in the range [limit1, limit2]
// which are not divisible by divisor1 and divisor2
//
// SHEIKH UMAR
#include <stdio.h>

int count_numbers(int, int, int, int);

int main(void) {    
	int divisor1, divisor2, limit1, limit2;

	printf("Enter 2 divisors: ");
	scanf("%d %d", &divisor1, &divisor2);
	while((divisor1 == divisor2) || divisor1 <= 0 || divisor2 <= 0)
	{	
		printf("Enter 2 divisors: ");
		scanf("%d %d", &divisor1, &divisor2);
	}

	printf("Enter lower and upper limits: ");
	scanf("%d %d", &limit1, &limit2);
	while((limit1 == limit2) || limit1 <= 0 || limit2 <= 0 || limit1 > limit2)
	{
		printf("Enter lower and upper limits: ");
		scanf("%d %d", &limit1, &limit2);
	}

	printf("Answer = %d\n", count_numbers(divisor1, divisor2, limit1, limit2));

	return 0;
}

int count_numbers(int divisor1, int divisor2, int limit1, int limit2)
{
	int total = 0, i;
	for (i = limit1; i<= limit2; i++)
	{
		if ( ((i % divisor1) != 0) && ((i % divisor2) != 0) )
		{
			total++;
		}
	}

	return total;
}


