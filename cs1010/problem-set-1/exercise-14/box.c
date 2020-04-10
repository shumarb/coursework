// CS1010 Programming Methodology
// Problem Set 1 Exercise #14: box.c
//
// Program takes in the length, width, height of a box
// and computes its surface area and diagonal using
// 2 separate functions
// SHEIKH UMAR

#include <stdio.h>
#include <math.h>

// function prototypes
int compute_surface_area(int length, int width, int height);
double compute_diagonal(int length, int width, int height);

int main(void) {
	int length, width, height;

	printf("Enter length: ");
	scanf("%d", &length);
	
	printf("Enter width : ");
	scanf("%d", &width);

	printf("Enter height: ");
	scanf("%d", &height);
	
	compute_surface_area(length, width, height);
	compute_diagonal(length, width, height);

	printf("Surface area = %d\n", compute_surface_area(length, width, height));
	printf("Diagonal = %.2lf\n", compute_diagonal(length,width, height));

	return 0;
}

// Compute surface area
int compute_surface_area(int length, int width, int height) {
	
	int value = (2 * (length * width) + 2 * (length * height) + 2 * (width * height));
		     
	// Return value of surface area to main function
	return value;
}

// Compute length of diagonal
double compute_diagonal(int length, int width, int height) {
	
	// A right-angled triangle is formed, with the diagonal of the box as
	// the hypothenuse, diagonal of a square box with dimensions of the width and length as the opposite,
	// and the height of the box as the adjacent.
	// Find the measurement of the diagonal of a square box with dimensions of the width and length first.
	// Then use Pythagoras Theorem with the available values to find the measurement of the diagonal.
	
	double c = pow(length, 2) + pow(width, 2);
	double diagonal = sqrt(pow(height, 2) + c);
	
	return diagonal;
}

		     
