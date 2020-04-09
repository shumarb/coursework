// CS1010 Programming Methodology
// Problem Set 1 Exercise #13: mean.c
//
// Program reads in three values.
// Then, program computes the arithmetic and geometric means.
// Finally, program prints out the values of the aforementioned means.

#include <stdio.h>
#include <math.h>

// function prototypes
double compute_AM(int a, int b, int c);
double compute_GM(int a, int b, int c);

int main(void) {
	int a, b, c;

	printf("Enter 3 positive integers: ");
	scanf("%d %d %d", &a, &b, &c);

	printf("Arithmetic mean = %.2lf\n", compute_AM(a, b, c));
	printf("Geometric mean = %.2lf\n", compute_GM(a, b, c));

	return 0;
}

// Compute arithmetic mean
double compute_AM(int a, int b, int c) {
	double arithmetic;
	
	// Calculate arithmetic mean
	arithmetic = (double) ((a + b + c) / 3);
	
	// Return value of arithmetic mean to main function
	return arithmetic;
}

// Compute geometric mean
double compute_GM(int a, int b, int c) {
	
	double geometric;
	
	// Calculate value of geometric mean
	geometric = cbrt(a * b * c);
	
	// Return value of geometric mean to main function
	return geometric;
}

