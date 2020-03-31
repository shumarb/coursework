// CS1010 Programming Methodology
// Problem Set 2 Exercise #25: prime_product.c
//
// Program reads in a number,
// and prints it out as a product of its prime multiples in increasing order.
//
// SHEIKH UMAR

#include <stdio.h>

void calculate(int num);

int main(void) 
{
	int num;
	printf("Enter integer: ");
	scanf("%d", &num);
	calculate(num);
	
	return 0;
}

// Calculate and print out num as a multiple of its primes.
void calculate(int num){
	int i = 2;
	
	if(num < 0)
	{
		printf("%d = -1", num);
	}
	if(num > 0)
	{
		printf("%d = 1", num);
	}

	if(num < 0)
	{
		num*=-1;
	}
	
	int k = num;
	
	while(k > 1)
	{
		while((k % i) != 0)
		{
			i++;
		}
		k /= i;
		printf(" * %d", i);
	}
	printf("\n");
}
