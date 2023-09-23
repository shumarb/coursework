// CS1010 Programming Methodology
// Problem Set 1 Exercise #07: sphere.c
// 
// This program reads diameter and 
// calculates surface area of a sphere.
//
// SHEIKH UMAR

#include <math.h>
#include <stdio.h>
#define PI 3.1415

int main(void) {

	double diameter, radius;

	printf("Enter diameter: ");
	scanf("%lf", &diameter);

	radius = diameter / 2.0;

	printf("Surface area = %.3lf\n", (4.0 * PI * pow(radius, 2.0)));

	printf("Volume = %.3lf\n", (4.0 * PI * pow(radius, 3.0) / 3.0));

	return 0;
}
