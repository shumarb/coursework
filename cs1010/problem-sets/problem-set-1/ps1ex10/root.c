// CS1010 Programming Methodology
// Problem Set 1 Exercise #10: root.c
//
// Program takes in the values of a, b, c.
// These values correspond to a(x^2) + bx + c of a quadratic equation.
// Program calculates the roots of this equation, and prints out the bigger root
//
// SHEIKH UMAR

#include <stdio.h>
#include <math.h>

// function prototype
double get_root(double a, double b, double c);

int main(void) {

	double a, b, c, root;

	printf("Enter coefficients (a b c): ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	root = get_root(a, b, c);

	printf("Bigger root is %.2f\n", root);

	return 0;
}

// Take three coefficients and return the bigger root
double get_root(double a, double b, double c) {
	
	// Declare 2 double variables as the 2 roots
	double x1, x2;

	// Use golden formula for each root
	x1 = ((-b) + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
	x2 = ((-b) - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
	
	// Compare x1 and x2, return the bigger value
	if(x1 < x2)
	{
		return x2;
	}
	else
	{
		return x1;
	}
}

