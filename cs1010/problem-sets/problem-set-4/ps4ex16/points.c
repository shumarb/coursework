// CS1010 Programming Methodology
// Problem Set 4 Exercise #16: points.c
//
// This program reads a series of points
// and calculates the area of the minimum
// surrounding circle.
//
// SHEIKH UMAR

#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define MAX_NUM 10  // max number of points

typedef struct {
	int x, y;
} point_t;

int read_points(point_t pts[]);
double compute_circle_area(point_t pts[], int numPts);

int main(void)
{
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
int read_points(point_t pts[])
{
	int j, num;

	printf("Enter the number of points: ");
	scanf("%d", &num);

	printf("Enter x- and y-coordinates for points:\n");
	for(j = 0; j < num; j++)
	{
		scanf("%d %d", &pts[j].x, &pts[j].y);
	}

	return num;
}

// Calculate the area of surrounding circle
double compute_circle_area(point_t pts[], int numPts)
{
	int j;
	double rad = sqrt(pow(pts[0].x, 2.0) + pow(pts[0].y,2.0));

	for(j = 1; j < numPts; j++)
	{
		rad = fmax(rad, sqrt(pow(pts[j].x, 2.0) + pow(pts[j].y, 2.0)));
	}

	return (rad * rad * PI);
}

