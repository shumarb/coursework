// CS1010 Programming Methodology
// Problem Set 1 Exercise #02: heights.c
//
// This program calculates the heights of 
// children according to heights of parents
//
// SHEIKH UMAR

#include <stdio.h>

int main(void) 
{
	double john, kate, mary, tom;

	printf("Enter the heights for John and Mary: ");
	scanf("%lf %lf", &john, &mary);

	tom = (0.54 * (john + mary));
	printf("Height for Tom: %.2f\n", tom);

	kate = 0.5 * (mary + (john * 0.923));
	printf("Height for Kate: %.2f\n", kate);

	return 0;
}
