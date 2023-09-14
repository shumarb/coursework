// north_east.c
// Compute the number of north-east paths.
//
// SHEIKH UMAR
#include <stdio.h>

int ne(int, int);

int main(void) {
	int rows, cols;

	printf("Enter rows and columns apart: ");
	scanf("%d %d", &rows, &cols);
	printf("Rows and columns apart: %d %d\n", rows, cols);

	printf("Number of NE-paths = %d\n", ne(rows, cols));
	return 0;
}

// Compute number of north-east paths between two points 
// that are x rows and y columns apart.
// Precod: x>=0, y>=0
int ne(int x, int y) {

	// Base case:
	// If x == 0 or y == 0, then number of ways to move from Point A to Point B or anywhere between these points
	// in only 1 direction but not the other has not been exhausted
	// If both x == 0 or y == 0, number of ways to move from Point A to Point B have been fully exhausted.
	if (x == 0 || y == 0)
	{
		return 1;
	}

	// Recursive case:
	// Number of ways to move from Point A or Point B in either direction have not been fully exhausted
	// at current position, find number of ways to travel from Point A to Point B by 1 step in north direction
	// and find number of ways to travel from Point A to Point B by 1 step in east direction
	return ne(x - 1, y) + ne(x, y - 1);
}

