// CS1010 Programming Methodology
// Problem Set 1 Exercise #19: bmi.c
//
// Program reads in user's gender, height and weight.
// Next, program passes these values to body_type function to compute bmi.
// This function assigns the bmi to either underweight, acceptable or overweight.
// This is represented as a value
// Main program displays advise based on bmi
// 
// SHEIKH UMAR

#include <stdio.h>

// function prototype
int body_type(int, double, double);

int main(void)
{
	double weight, height;
	int gender, type;

	printf("Enter your gender (0 for female, 1 for male): ");
	scanf("%d", &gender);

	printf("Enter your weight (kg) and height (m): ");
	scanf("%lf %lf", &weight, &height);
	
	type = body_type(gender, weight, height);
	
	if (type == -1)
	{
		printf("Stuff yourself with more food!\n");
	}
	
	else if (type == 0)
	{
		printf("Great! Maintain it!\n");
	}
	
	// Print out advise for overweight
	else
	{
		printf("Time to join the gym!\n");
	}

	return 0;
}

// Takes gender, weight, height and returns body type
int body_type(int gender, double weight, double height)
{
	double bmi = (weight / (height * height));
	int weight_class;

	if (gender == 0)
	{
		// If bmi is less than or equal to 19, weight class is underweight
		if (bmi <= 19.00)
		{
			weight_class = -1;
		}

		// If bmi is between 19 and up to and including 24, body type is acceptable
		else if ((bmi > 19) && (bmi <= 24))
		{
			weight_class = 0;
		}

		// If above two conditions are not satisfied, body type is overweight
		else
		{
			weight_class = 1;
		}
	}

	// Assign weight class for male
	else
	{
		// If bmi is less than or equal to 19, weight class is underweight
		if (bmi <= 20.00)
		{
			weight_class = -1;
		}

		// If bmi is between 19 and up to and including 24, body type is acceptable
		else if ((bmi > 20.00) && (bmi <= 25.00))
		{
			weight_class = 0;
		}

		// If above two conditions are not satisfied, body type is overweight
		else
		{
			weight_class = 1;
		}
	}
	
	return weight_class;
}
