// CS1010 Programming Methodology
// Problem Set 1 Exercise #15: max_int.c
//
// Program reads in 3 integers, passes it to the get_max function
// The 3 numbers are compared in the get_max function, which then returns the largest integer back to main function
// Finally, main program prints out the largest integer
//
// SHEIKH UMAR

#include <stdio.h>

// function prototype
int get_max(int, int, int);

int main(void)
{
	int num1, num2, num3;

	printf("Enter three integers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	printf("Maximum input integer is %d\n", get_max(num1, num2, num3));

	return 0;
}

// Return the max value among the three inputs
int get_max(int num1, int num2, int num3)
{
	if ((num1 > num2) && (num1 > num3))
	{
		return num1;
	}
	else if ((num2 > num1) && (num2 > num3))
	{
		return num2; 
	}
	else
	{
		return num3;
	}
}
