// CS1010 Programming Methodology
// Problem Set 2 Exercise #06: factorial.c
//
// Program reads in a number, computes its factorial, and prints the answer.

#include <stdio.h>

int factorial(int);

int main(void) 
{
	int num;

	printf("Enter n: ");
	scanf("%d", &num);

	printf("%d\n",factorial(num));

	return 0;
} 

int factorial(int num)
{
	int i, answer = 1;

	for(i = 1; i <= num; i++)
	{
		answer *= i;
	}

	return answer;
}

