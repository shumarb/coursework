// CS1010 Programming Methodology
// Problem Set 3 Exercise #04: deviation.c
//
// This program calculates the
// standard deviations for n real numbers.
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
#define MAX_LEN 9 

double deviation(double val[], int size);
double average(double val[], int size);
double sum_of_difference(double val[], int size);

int main(void) {

	double val[MAX_LEN];
	int i, num;

	printf("How many real numbers? ");
	scanf("%d", &num);

	printf("Enter %d numbers: ", num);
	for (i = 0; i < num; i++)
	{
		scanf("%lf", &val[i]);
	}

	printf("Standard deviation: %.2lf\n", deviation(val, num));

	return 0;
}

// Return standard deviation
double deviation(double val[], int size)
{
	double numerator;

	numerator = sum_of_difference(val, size);

	return sqrt(numerator / (double) size);
}

// Return average of numbers in the array
double average(double val[], int size)
{
	double sum = 0;
	int i;

	for (i = 0; i < size; i++)
	{
		sum += val[i];
	}

	return (sum / (double) size);
}

// Calculate the sum of square differences
// i.e. upper inner part of the formula
double sum_of_difference(double val[], int size)
{
	double mean, sum_of_difference = 0.0;
	int i;

	mean = average(val, size);
	
	for (i = 0; i < size; i++)
	{
		sum_of_difference += pow((val[i] - mean), 2.0);
	}

	return sum_of_difference;
}

