// CS1010 Programming Methodology
// Problem Set 2 Exercise #13: square_number.c
//
// Program reads in a number, computes and prints out if it is a square number.

#include <stdio.h>
#include <math.h>

int main(void)
{
	int num;
	int sqrt_num;

	printf("Enter an integer: ");
	scanf("%d", &num);

	sqrt_num = sqrt(num);
	
	if((sqrt_num * sqrt_num) == num)
	{
		printf("%d is a square number\n", num);
	}
	else
	{
		printf("%d is not a square number\n", num);
	}
	return 0;
}

