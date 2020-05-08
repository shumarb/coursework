// CS1010 Programming Methodology
// Problem Set 2 Exercise #05: count_positive.c
//
// Program reads in 5 integers, counts number of positive numbers.
// Program prints out number of positive numbers.

#include <stdio.h>

int main(void) {

	int n1, n2, n3, n4, n5;
	int counter = 0;

	printf("Enter 5 integers: ");
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
	
	if(n1 > 0)
	{
		counter++;
	}
	if(n2 > 0)
	{
		counter++;
	}
	if(n3 > 0)
	{
		counter++;
	}
	if(n4 > 0)
	{
		counter++;
	}
	if(n5 > 0)
	{
		counter++;
	}
	
	printf("Count = %d\n",counter);

	return 0;
} 

