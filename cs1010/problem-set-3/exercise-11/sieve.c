// CS1010 Programming Methodology
// Problem Set 3 Exercise #11: sieve.c
//
// This program implements Sieve of Eratosthenes,
// which is used to check if a given number is
// prime or not.
// It use preprocessing to figure out all prime
// numbers and answer queries by looking up
// the array constructed.
// SHEIKH UMAR A0149874L

#include <stdio.h>
#include <math.h>
#define SIZE 10000

void initialize(int arr[]);
void preprocess(int arr[]);
int check_prime(int);

int main(void)
{
	int num, arr[SIZE+1];

	initialize(arr);
	preprocess(arr);

	printf("Pre-processing ready, "
			"enter values (0 to stop):\n");

	scanf("%d", &num);
	while (num > 0) 
	{
		if (arr[num] == 1)
		{
			printf("prime\n");
		}
		else
		{
			printf("not prime\n");
		}
		scanf("%d", &num);
	}

	return 0;
}

// Initialize all slots to 1
void initialize(int arr[])
{
	int j;
	for(j = 0; j < SIZE + 1; j++)
	{
		arr[j] = 1;
	}
}

// Pre-process and determine all prime numbers
void preprocess(int arr[]) 
{
	int m, p;
	for(m = 2; m <= 100; m++)
	{

		if(check_prime(m) == 1)
		{
			p = 2;
			while((p * m) <= 10000)
			{
				arr[p * m] = 0;
				p++;
			}
		}
	}
}


int check_prime(int num)
{
	int j;

	while(num == 2|| num == 3)
	{
		return 1;
	}

	for(j = 2; j < sqrt(num); j++)
	{
		if((num % j) == 0)
		{
			return 0;
		}
	}
	return 1;
}

