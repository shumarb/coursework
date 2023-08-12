// DaysSince1Jan2017.c
// This program reads the day and month of 2017 and computes
// the number of days since 1st January 2017.
//
// SHEIKH UMAR
#include <stdio.h>

int computeDays(int, int);

int main(void) {    
	int day, month;

	printf("Enter day and month: ");
	scanf("%d %d", &day, &month);

	printf("Day %d of month %d is the %dth day of 2017.\n", 
	       day, month, computeDays(day, month));

	return 0;
}

// This function computes the number of days that have elapsed 
// for the given day and month since 1st January 2017.
int computeDays(int day, int mth) {
	int num_days_elapsed = 0;

	// If month entered is January, number of days elapsed == number of days user has entered
	if (mth == 1)
	{
		return day;
	}

	// For days between February and December,
	// obtain number of days elapsed up to month before month that user entered,
	// return sum days that user entered and number of days elapsed up to month before month that user entered
	switch(mth - 1)
	{
		case 1: num_days_elapsed += 31; break;
		case 2: num_days_elapsed += 59; break;
		case 3: num_days_elapsed += 90; break;
		case 4: num_days_elapsed += 120; break;
		case 5: num_days_elapsed += 151; break;
		case 6: num_days_elapsed += 181; break;
		case 7: num_days_elapsed += 212; break;
		case 8: num_days_elapsed += 243; break;
		case 9: num_days_elapsed += 273; break;
		case 10: num_days_elapsed += 304; break;
		case 11: num_days_elapsed += 334; break;
	}

	return day + num_days_elapsed;
}

