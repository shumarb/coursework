// CS1010 Programming Methodology
// Problem Set 3 Exercise #09: most_appeared.c
//
// This program reports the digit that
// appears most of the time in a given number.
// SHEIKH UMAR A0149874L

#include <stdio.h>

int most_appeared(int num);

int main(void)
{
	int num;

	printf("Enter a positive integer: ");
	scanf("%d", &num);

	printf("Most appeared digit in %d: %d\n", num, most_appeared(num));

	return 0;
}

// Return the digit that has max frequency.
// In case more than 1 digit gives the same
// max frequency, return the biggest digit.
int most_appeared(int num)
{
	int j , k, max, integer = num;
	int freq[10] = {0}; // frequency of digits 0-9

	for(k = 0; k < 10; k++)
	{
		freq[k] = 0;
	}

	// Increase number of times each digit in number is found.
	while(integer > 0)
	{
		int digit = integer % 10;
		freq[digit]++;
		max = digit;
		integer /= 10;
	}

	/*
	printf("Max = %d\n", max);
	for(j = 0; j < 10; j++)
	{
		printf("%d ", freq[j]);
	}
	printf("\n");
	*/

	// Compare values of elements in freq array.
	// For each comparison, if first element>second element, max = first element.
	// else, max = second element.
	for(j = 0; j < 10; j++)
	{
		if(freq[j] >= freq[max])
		{
			max = j;
		}
	}
	
	return max;
}

