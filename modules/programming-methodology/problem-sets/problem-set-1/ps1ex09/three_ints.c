// CS1010 Programming Methodology
// Problem Set 1 Exercise #09: three_ints.c
//
// Program reads in 3 integers, and calculates the hundredth-placed digit of that integer
// Program displays that hundredth-placed digit corresponding to the integer entered
// Program prints out integer if it is less than 100

#include <stdio.h>

// function prototype
int get_hundredth(int);

// main function is complete
int main(void)
{
	int num1, num2, num3;  
	int digit; // digit in hundredth position

	printf("Enter 3 positive integers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	digit = get_hundredth(num1);
	printf("%d ", digit);

	digit = get_hundredth(num2);
	printf("%d ", digit);

	digit = get_hundredth(num3);
	printf("%d\n", digit);

	return 0;
}

// Take a number and return the digit in hundredth position
int get_hundredth(int num)
{
	if (num < 100)
	{
		return 0;
	} 

	else if (num >= 100 && num < 1000)
	{	
		return (num / 100);
	} 

	else if (num > 1000 && num <= 10000)
	{
		return ((num / 100) % 10);
	} 

	else if (num > 1000 && num <= 10000)
	{
		return ((num / 1000) % 10);
	} 

	else
	{
		return ((num / 10000) % 10);
	}
}	
