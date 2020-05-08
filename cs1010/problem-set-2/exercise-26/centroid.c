// CS1010 Programming Methodology
// Problem Set 2 Exercise #26: centroid.c
//
// Program reads in three coordinates,
// computes and prints out the median.

#include <stdio.h>

void centroid(double x1, double y1, double x2, double y2, double x3, double y3, double *xG_p, double *yG_p);

int main(void) {

	double	x1, y1,    // coordinates of 1st vertex
	       	x2, y2,    // coordinates of 2nd vertex
			x3, y3,    // coordinates of 3rd vertex
			xG, yG;    // coordinates of centroid

	printf("Coordinates of 1st vertex: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Coordinates of 2nd vertex: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Coordinates of 3rd vertex: ");
	scanf("%lf %lf", &x3, &y3);
	
	// make function call to centroid function
	centroid(x1, y1, x2, y2, x3, y3, &xG, &yG);

	printf("Coordinates of centroid = (%.2f, %.2f)\n", xG, yG);

	return  0;
}

// Calculate x- and y- coordinate of median,
// assign it to memory address of xG and yG
void centroid(double x1, double y1, double x2, double y2,double x3, double y3, double *xG_p, double *yG_p) {
	*xG_p = ((1.0 / 3.0) * (x1 + x2 + x3));
	*yG_p = ((1.0 / 3.0) * (y1 + y2 + y3));
}

