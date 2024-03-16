// CS1010 AY2011/2 Semester 1 
// PE1 Ex1: century.c
// Name: Sheikh Umar
#include <math.h>
#include <stdio.h>

void printCentury(int);
void printOrdinal(int);

int main(void)
{
	int year; // user's input

	printf("Enter year: ");
	scanf("%d", &year);

	printf("The year %d falls in the ", year);
	printCentury(year);
	printf(" century.\n");
	
	return 0;
}

void printCentury(int year)
{	
	// year has n digits, so obtain first (n - 2) digits
	// this number represents a 0-based number
	// then add 1 to this number because century is 1-based counting
	year /= 100;
	year += 1;
	printf("%d", year);
	printOrdinal(year);
}

void printOrdinal(int century)
{
	// for numbers with last 2 digits of 11, 12, and 13, display suffix 'th'
	if ( (century % 100) == 11 || (century % 100) == 12 || (century % 100) == 13 )
	{
		printf("th");
	}

	// for numbers whose last 2 digits are neither 11, 12, or 13
	else
	{
		// for numbers with last digit of 1 and number is not 11, print suffix 'st'
		if ((century % 10) == 1)
		{
			printf("st");
		}

		// for numbers with last digit of 2 and number is not 12, print suffix 'nd'
		else if ((century % 10) == 2)
		{
			printf("nd");
		}

		// for numbers with last digit of 3 and number is not 13, print suffix 'rd'
		else if ((century % 10) == 3)
		{
			printf("rd");
		}
		
		// for remaining numbers where top condition is not satisfied, print th
		else
		{
			printf("th");
		}
	}
}

