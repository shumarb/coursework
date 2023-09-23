// CS1010 Programming Methodology
// Problem Set 4 Exercise #19: fraction.c
//
// This program reads in two fractions, 
// checks if they equal and computes their sum.
//
// <Replace this with your name>

#include <stdio.h>

typedef struct {
	int numer;  // numerator
	int denom;  // denominator 
} fraction_t;

int euclid_gcd(int a, int b);
fraction_t simplify(fraction_t frac);
int equals(fraction_t frac1, fraction_t frac2);
fraction_t add(fraction_t frac1, fraction_t frac2);

int main(void) {

	fraction_t frac1, frac2, frac3;

	printf("Enter 1st fraction: ");
	printf("Enter 2nd fraction: ");

	printf("1st fraction is /\n");
	printf("2nd fraction is /\n");

	printf("Two fractions are the same.\n");
	printf("Two fractions are not the same.\n");

	printf("/ + / = /\n");

	return 0;
}

// Return greatest common divisor of a and b
int euclid_gcd(int a, int b) {

	return 0; // stub
}

// Check whether two fractions equal
// Return 1 if so, 0 otherwise
int equals(fraction_t frac1, fraction_t frac2) {


	return 0; // stub
}

// Add frac1 to frac2, return the result
// in the simplified form
fraction_t add(fraction_t frac1, fraction_t frac2) {

}
