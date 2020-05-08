// CS1010 Programming Methodology
// Problem Set 2 Exercise #23: square_free.c
//
// Program reads in 4 numbers, computes number of square-free numbers in first two and last two numbers,
// prints out range with more square-free numbers,
// or prints both if both rangees have same number of square-free numbers

#include <stdio.h>

int num_square_free(int lower, int upper);
int is_square_free(int num);

int main(void)
{
	int n1, n2, n3, n4;
	int counter_1, counter_2;

	printf("Enter four positive integers: ");
	scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

	counter_1 = num_square_free(n1,n2);
	counter_2 = num_square_free(n3, n4);

	if(counter_1 > counter_2)
	{
		printf("Range [%d, %d] has more square-free numbers: %d\n", n1, n2, counter_1);
	}
	else if(counter_2 > counter_1)
	{
		printf("Range [%d, %d] has more square-free numbers: %d\n", n3, n4, counter_2);
	}
	else
	{
		printf("Both ranges have the same number of square-free numbers: %d\n", counter_1);
	}

	return 0;
}

// Function sends each number from lower to upper to is_square_free function
// to check if it is square-free. Return square-free integer back to main function.
int num_square_free(int lower, int upper)
{
	int num, ans = 0;

	// Send each num to is_square_free function
	for(num = lower; num <= upper; num++)
	{
		if (is_square_free(num) ==1)
		{
			ans++;
		}
	}

	return ans; // Non square free num. Return 0.
}

// Check if numm is square free
// Precon: If num is <i*i, where i = 2,3,4,...
// num is square_free
int is_square_free(int num) {
	int i = 2;

	while(num >= (i * i))
	{
		if((num % (i * i)) == 0)
		{
			return 0; // num is not square free
		}
		i++; // Increase i by 1, check if num can be divided by i*i
	}

	// If num<i*i, it is a square_free integer, so return 1 to num_square_free
	return 1;
}

