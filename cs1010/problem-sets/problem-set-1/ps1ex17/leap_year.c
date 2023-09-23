// CS1010 Programming Methodology
// Problem Set 1 Exercise #17: leap_year.c
//
// Program reads in a year.
// Program checks if year is divisible either: by 4 but not 100, or by 400
// Program prints out on whether the year is a leap year or not
//
// SHEIKH UMAR

#include <stdio.h>

// function prototype
int is_leap_year(int);

int main(void)
{
	int year;

	printf("Enter year: ");
	scanf("%d", &year);
	
	// If value returned from is_leap_year is 1, print out that year is a leap year
	if (is_leap_year(year) == 1)
	{
		printf("%d is a leap year.\n", year);
	}
	else
    {
		// Else print this out if year is not a leap year
		printf("%d is not a leap year.\n", year);
	}
	
	return 0;
}

// Return 1 if year is leap year, or 0 otherwise
int is_leap_year(int year)
{
	// Leap year if either:
	// 1. year is divisible by 400
	// 2. year is divisible by 4 and not divisible by 100
	if ((year % 400) == 0 || ((year % 4) == 0 && (year % 100) != 0))
    {
		return 1;
	}

	return 0;
}
