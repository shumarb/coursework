// CS1010 Programming Methodology
// Problem Set 1 Exercise #13: mean.c
//
// Program reads in three values.
// Then, program computes the arithmetic and geometric means.
// Finally, program prints out the values of the aforementioned means.
//
// SHEIKH UMAR

#include <stdio.h>
#include <math.h>

// function prototypes
double compute_AM(int, int, int);
double compute_GM(int, int, int);

int main(void) {
	int num1, num2, num3;

	printf("Enter 3 positive integers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	printf("Arithmetic mean = %.2lf\n", compute_AM(num1, num2, num3));
	printf("Geometric mean = %.2lf\n", compute_GM(num1, num2, num3));

	return 0;
}

// Compute arithmetic mean
double compute_AM(int num1, int num2, int num3) {
	return ((double) (num1 + num2 + num3) / 3.0);
}

// Compute geometric mean
double compute_GM(int num1, int num2, int num3) {
	return cbrt(num1 * num2 * num3);
}

