// CS1010 Programming Methodology
// Problem Set 1 Exercise #12: travel.c
//
// Program reads in the coordinates of Home, Office, and NTUC
// Program calculates distance from Home to Office
// Program calculates distance from Office to NTUC
// Program calculates distance from NTUC to Home
// Program adds the 3 distances above to form total distance
// Program prints out total distance travelled

#include <stdio.h>
#include <math.h>

// function prototype
double distance(double x1, double y1, double x2, double y2);

int main(void) {
	double x1, y1;	//Coordinates for Home
	double x2, y2;	//Coordinates for Office
	double x3, y3;	//Coordinates for NTUC
	double total;	//Total distance travelled
	double first_distance, second_distance, third_distance;

	printf("Enter X Y coordinates for Home: ");
	scanf("%lf  %lf", &x1, &y1);

	printf("Enter X Y coordinates for Office: ");
	scanf("%lf %lf", &x2, &y2);

	printf("Enter X Y coordinates for NTUC: ");
	scanf("%lf %lf", &x3, &y3);
	
	// Calculate distance from Home to Office
	first_distance = distance(x1, y1, x2, y2);
	
	// Calculate distance from Office to NTUC
	second_distance = distance(x2, y2, x3, y3);

	// Calculate distance from NTUC to Home
	third_distance = distance(x3, y3, x1, y1);

	// Calculate total distance
	total = first_distance + second_distance + third_distance;
	printf("Distance of travel is %.2lf\n", total);

	return 0;
}

// Calculate distance between two points (x1, y1), (x2, y2)
double distance(double x1, double y1, double x2, double y2) {
	double travel = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	return travel;
}

