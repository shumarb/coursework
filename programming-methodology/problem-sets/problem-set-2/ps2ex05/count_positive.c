// CS1010 Programming Methodology
// Problem Set 2 Exercise #05: count_positive.c
//
// Program reads in 5 integers, counts number of positive numbers.
// Program prints out number of positive numbers.
//
// SHEIKH UMAR

#include <stdio.h>

int main(void) 
{
	int count = 0, i, number;

	printf("Enter 5 integers: ");

	for (i = 0; i < 5; i++) {
		scanf("%d", &number);
		if (number > 0) {
			count++;
		}
	}

	printf("Count = %d\n", count);

	return 0;
} 
