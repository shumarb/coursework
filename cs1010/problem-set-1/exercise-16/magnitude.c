// CS1010 Programming Methodology
// Problem Set 1 Exercise #16: magnitude.c
//
// Program reads in the value of a magnitude of an earthquake 
// and displays the classification of this magnitude
// on the Ritcher Magnitude Scale

#include <stdio.h>

int main(void)
{
	double magnitude;

	printf("Magnitude: ");
	scanf("%lf", &magnitude);

	if(magnitude < 4.0)
	{
		printf("Classification: Minor\n");

	} 
	else if (magnitude >= 4.0 && magnitude < 6.0)
	{
		printf("Classification: Moderate\n");
	}
	else if (magnitude >= 6.0 && magnitude < 6.9)
	{
		printf("Classification: Strong\n");
	} 
	else 
	{
		printf("Classification: Major\n");
	}

	return 0;
}

