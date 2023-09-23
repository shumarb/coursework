// CS1010 Programming Methodology
// Problem Set 2 Exercise #02: print_digits.c
//
// Program reads in an integer, and prints out its digits
//
// SHEIKH UMAR

#include <stdio.h>

void print_digits(int num); // function prototype

int main(void)
{
	int num;

	printf("Enter a positive integer: ");
	scanf("%d",&num);

	print_digits(num);
	return 0;
}

// Print digits right to left
void print_digits(int num)
{
	// Keep extracting each digit as long as num>0
	while(num > 0)
	{
		int n1 = (num % 10);
		printf("%d ",n1);

		// Obtain digits of num without earlier last digit
		// While loop will rely on this value of num
		num /= 10;
	}
	
	printf("\n");  // change line
}
