// CS1010 Programming Methodology
// Problem Set 1 Exercise #07: sphere.c
// 
// This program reads diameter and 
// calculates surface area of a sphere.

#include <math.h>
#include <stdio.h>

double computes_surface_area(double diameter);
double computes_volume(double diameter);

int main(void)
{
	double diameter;

	printf("Enter diameter: ");
	scanf("%lf", &diameter);

	printf("Surface area = %.3lf\n", computes_surface_area(diameter));
	printf("Volume = %0.3lf\n", computes_volume(diameter));
	
	return 0;
}

// Function computes surface area based on diameter value
double computes_surface_area(double diameter)
{
	double radius = (diameter / 2.0);

	return (4.0 * 3.1415 * pow(radius, 2.0));
}

// Function computes volume based on diameter value
double computes_volume(double diameter)
{
	double radius = (diameter / 2.0);

	return ((4.0 / 3.0) * 3.1415 * pow(radius, 3.0));
}

