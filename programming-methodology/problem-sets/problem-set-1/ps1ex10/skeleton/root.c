// CS1010 Programming Methodology
// Problem Set 1 Exercise #10: root.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>

// function prototype
double get_root(double a, double b, double c);

int main(void) {

	double a, b, c, root;

	printf("Enter coefficients (a b c): ");


	root = get_root(a, b, c);

	printf("Bigger root is %.2f\n", root);

	return 0;
}

// Take three coefficients and return the bigger root
double get_root(double a, double b, double c) {

	return 0; // stub, to be replaced by your code 
}
