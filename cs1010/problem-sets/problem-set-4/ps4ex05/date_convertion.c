// CS1010 Programming Methodology
// Problem Set 4 Exercise #05: date_convertion.c
//
// This program reads a string in the UK date format
// and outputs the equivalent American format.
//
// SHEIKH UMAR

#include <stdio.h>
#include <string.h>

int main(void)
{
	int day, year;
	char month[10];

	printf("Enter date in UK format: ");
	scanf("%s", month);
	getchar();
	scanf("%d", &day);
	getchar();
	getchar();
	scanf("%d", &year);

	printf("Date in American format: %d %s %d\n", day, month, year);

	return 0;
}

