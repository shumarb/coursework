// CS1010 Programming Methodology
// Problem Set 1 Exercise #18: triangle.c
//
// Program reads in 3 lengths, then determines type of triangle formed
// based on these lengths, and finally prints out the type of triangle
// formed by the 3 lengths
//
// SHEIKH UMAR

#include <stdio.h>

int main(void)
{
	int length1, length2, length3;
	scanf("%d %d %d", &length1, &length2, &length3);

	// Condition for equilateral triangle
	// The 3 lengths are the same
	if ((length1 == length2) && (length2 == length3))
	{
		printf("Equilateral\n");
	}
	
	// Condition for isoceles triangle
	// 2 of the 3 lengths are the same
	else if (
		((length1 == length2) && (length1 != length3)) 
		|| ((length1 == length3) && (length1 != length2)) 
		|| ((length2 == length3) && (length2 != length1)))
	{
		printf("Isosceles\n");
	}
	
	// Condition for not a triangle: any 1 length is greater than or equal to the sum of the other 2
	else if((length1 >= (length2 + length3)) || (length2 >= (length1 + length3)) || (length3 >= (length2 + length1)))
	{
		printf("Not a triangle\n");
	}

	else
	{
		printf("Scalene\n");
	}

	return 0;
}
