// CS1010 Programming Methodology
// Problem Set 2 Exercise #09: collatz.c
//
// Program reads in an integer,
// computes number of divisions and multiplications needed to convert
// integer to 1.
//
// SHEIKH UMAR

#include <stdio.h>

int count_iterations(int num);

int main(void)
{
	int num;
	printf("Enter a natural number: ");
	scanf("%d", &num);

	if(num == 1)
	{
		printf("Number of iterations = %d\n", 0);
	}
	else
	{
		printf("Number of iterations = %d\n" ,count_iterations(num));
	}
	return 0;

}

// Function computes number of times needed to convert 
// input to 1 via collatz method.
int count_iterations(int num)
{
	int count_mul = 0, count_div = 0;

	while(num != 1)
	{
		// Division if number is even
		if((num % 2) == 0)
		{
			num = (num / 2);
			count_div++;
		}
		// Multiplication if number is odd
		else
		{
			num = ((num * 3) + 1);
			count_mul++;
		}
	}

	return (count_mul + count_div);
}

