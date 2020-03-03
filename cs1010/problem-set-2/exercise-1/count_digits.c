// CS1010 Programming Methodology
// Problem Set 2 Exercise #01: count_digits.c
//
// Program reads in a number,
// and prints out its digits.
//
// SHEIKH UMAR

#include <stdio.h>

int reads_number();
int range(int);
void displays_number_of_digits(int);

// Function reads in number
int reads_number()
{
	int test = 0, num;
	printf("Enter a positive integer: ");
	scanf("%d", &num);
	if (test)
	{
		printf("num = %d\n", num);
	}
	return num;

}

// Function determines number of digits that num has
int range(int num)
{
	int digit;
	if (num < 10){
		digit = 1;
	}
	if ((num >= 10) && (num < 100))
	{
		digit = 2;
	}
	if ((num >= 100) && (num < 1000))
	{
		digit = 3;
	}
	if ((num >= 1000) && (num < 10000))
	{
		digit = 4;
	}
	if ((num >= 10000) && (num < 100000))
	{
		digit = 5;
	}
	if ((num >= 100000) && (num < 1000000))
	{
		digit = 6;
	}
	if ((num >= 1000000) && (num < 10000000))
	{
		digit = 7;
	}
	return digit;
}

// Function displays number of digits in num
void displays_number_of_digits(int num)
{
	printf("Number of digits = %d\n", num);
}

int main(void)
{
	int num = reads_number();
	int num_digits = range(num);
	displays_number_of_digits(num_digits);
	return 0;
}
