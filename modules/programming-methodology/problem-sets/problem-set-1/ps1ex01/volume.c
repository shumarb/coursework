// CS1010 Programming Methodology
// Problem Set 1 Exercise #01: volume.c
// 
// This program reads in length, width and
// height of a box, computes its volume
//
// SHEIKH UMAR

#include <stdio.h>

int main(void) 
{
	int height, length, volume, width;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width: ");
	scanf("%i", &width);

	printf("Enter height: ");
	scanf("%d", &height);

	// correct the following two statements
	volume = length * width * height;
	printf("Volume = %d\n", volume);

	return 0;
}
