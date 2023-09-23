// CS1010 Programming Methodology
// Problem Set 1 Exercise #20: younger.c
//
// Program reads in each person's day, month, and year of birth
// Program compares the year first. Person with smaller birth year is younger person
// For same birth day, month and year, both persons have the same age
// For same birth day and year, person with greater numerical value of month is the younger person
//
// SHEIKH UMAR

#include <stdio.h>

int main(void)
{
	int d1, m1, y1; // birth day, month, year of Tamil
	int d2, m2, y2; // birth day, month, year of Alice

	printf("Enter birthday for Tamil (day month year): ");
	scanf("%d %d %d", &d1, &m1, &y1);

	printf("Enter birthday for Alice (day month year): ");
	scanf("%d %d %d", &d2, &m2, &y2);
	
	// If Alice's birth year > Tamil's birth year, Alice is younger
	if (y2 > y1)
	{
		printf("Alice is younger\n");
	}
	
	// If Tamil's birth year > Alice's birth year, Tamil is younger
	else if (y1 > y2)
	{
		printf("Tamil is younger\n");
	}
	
	// If both persons have same birth day and birth year
	// and Alice has greater month value than Tamil, Alice is younger
	else if ((d1 == d2) && (y1 == y2) && (m2 > m1))
	{	
		printf("Alice is younger\n");
	}

	// If both persons have same birth day and birth year
	// and Tamil has greater month value than Alice, Tamil is younger
	else if ((d1 == d2) && (y1 == y2) && (m1 > m2))
	{	
		printf("Tamil is younger\n");
	}
	
	// If both have same birth month and year,
	// and Tamil has greater birth day than Alice, 
	// Tamil is younger
	else if ((m1 == m2) && (y1 == y2) && (d1 > d2))
	{
		printf("Tamil is younger\n");
	}

	// If both have same birth month and year,
	// and Alice has greater birth day than Alice, 
	// Alice is younger
	else if ((m1 == m2) && (y1 == y2) && (d2 > d1))
	{
		printf("Alice is younger\n");
	}

	// If both persons have same birth day, month, and year, they have the same age
	else
	{
		printf("Tamil and Alice are of the same age\n");
	}

	return 0;
}
