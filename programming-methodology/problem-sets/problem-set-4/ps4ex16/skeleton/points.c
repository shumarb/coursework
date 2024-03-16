// CS1010 Programming Methodology
// Problem Set 4 Exercise #16: points.c
//
// This program reads a series of points
// and calculates the area of the minimum
// surrounding circle.
//
// <Replace this with your name>

#include <stdio.h>

#define PI 3.14159
#define MAX_NUM 10  // max number of points

typedef struct {
	int x, y;
} point_t;

int read_points(point_t pts[]);
double compute_circle_area(point_t pts[], int numPts);

int main(void) {

	int numPts;  // actual number of points read in
	double area;

	point_t pts[MAX_NUM];

	numPts = read_points(pts);

	area = compute_circle_area(pts, numPts);

	printf("Area of smallest circle = %.2f\n", area);

	return 0;
}

// Read points one by one and store into array.
// Return the number of points read
int read_points(point_t pts[]) {

	printf("Enter the number of points: ");

	printf("Enter x- and y-coordinates for points:\n");


	return 0; // stub
}

// Calculate the area of surrounding circle
double compute_circle_area(point_t pts[], int numPts) {

	return 0; // stub
}
