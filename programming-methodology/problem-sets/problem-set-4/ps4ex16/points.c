// CS1010 Programming Methodology
// Problem Set 4 Exercise #16: points.c
//
// This program reads a series of points
// and calculates the area of the minimum
// surrounding circle.
//
// SHEIKH UMAR

#include <math.h>
#include <stdio.h>
#define PI 3.14159
#define MAX_NUM 10  // max number of points

typedef struct {
	int x, y;
} point_t;

double compute_circle_area(point_t pts[], int numPts);
int read_points(point_t pts[]);

int main(void)
{
	double area;
	int numPts; 
	point_t pts[MAX_NUM];

	numPts = read_points(pts);
	area = compute_circle_area(pts, numPts);

	printf("Area of smallest circle = %.2f\n", area);

	return 0;
}

// Read points one by one and store into array.
// Return the number of points read
int read_points(point_t pts[])
{
	int j, number_of_points;

	printf("Enter the number of points: ");
	scanf("%d", &number_of_points);

	printf("Enter x- and y-coordinates for %d points:\n", number_of_points);
	for (j = 0; j < number_of_points; j++)
	{
		scanf("%d %d", &pts[j].x, &pts[j].y);
	}

	return number_of_points;
}

// Calculate the area of surrounding circle
double compute_circle_area(point_t pts[], int numPts)
{
	double radius = sqrt(pow(pts[0].x, 2.0) + pow(pts[0].y,2.0));
	int j;

	for (j = 1; j < numPts; j++)
	{
		radius = fmax(radius, sqrt(pow(pts[j].x, 2.0) + pow(pts[j].y, 2.0)));
	}

	return (radius * radius * PI);
}
