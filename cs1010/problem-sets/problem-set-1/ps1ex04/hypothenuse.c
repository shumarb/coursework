// CS1010 Programming Methodology
// Problem Set 1 Exercise #04: hypothenuse.c
//
// Program takes in the values of a triangle's opposite and adjacent lengths
// then calculates the hypothenus of the triangle
// and prints it out
//
// SHEIKH UMAR

#include <stdio.h>
#include <math.h> // to use sqrt() function

int main(void)
{
	double opposite, adjacent, hypothenuse;

	printf("Enter a and b: ");
	scanf("%lf %lf", &opposite, &adjacent);

	//Calculation for hypothenuse
	hypothenuse = sqrt(pow(opposite, 2) + pow(adjacent, 2));
	printf("c = %.2lf\n", hypothenuse);

	return 0;
}

