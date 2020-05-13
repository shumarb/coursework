// CS1010 Programming Methodology
// Problem Set 4 Exercise #11: perimeter.c
//
// This program reads the lengths of two sides
// of a rectangle, and computes the minimum
// perimeter after folding the rectangle
// once along the x-axis or y-axis.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>
#include <math.h>

typedef struct {
	double side1, side2;
} 	rectangle_t;

int main(void)
{
	// declare a rectangle of type rectangle_t below
	rectangle_t rect;
	double fold1, fold2;

	printf("Enter lengths of two sides: ");
	scanf("%lf %lf", &rect.side1, &rect.side2);
	
	fold1 = 2 * ((0.5 * rect.side1) + rect.side2);
	fold2 = 2 * ((0.5 * rect.side2) + rect.side1);
	printf("Min perimeter after fold = %.1lf\n", fmin(fold1, fold2));

	return 0;
}

