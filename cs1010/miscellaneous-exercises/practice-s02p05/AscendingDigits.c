// AscendingDigits.c
// This program reads 3 positive integers and outputs "Yes" if
// the hundreds digits are in ascending order, or "No" otherwise.
//
// SHEIKH UMAR
#include <stdio.h>

int isAscending(int, int, int);
int finds_hundredth_digit(int);

int main(void) {    
	int num1, num2, num3;
	printf("Enter 3 positive integers: ");
	scanf("%d %d %d", &num1, &num2, &num3);
	printf("The integers are %d, %d and %d\n", num1, num2, num3);

	if (isAscending(num1, num2, num3))
	{
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}

	return 0;
}

// This function returns 1 if the digits at the hundredth position
// of the 3 parameters are in ascending order, or 0 otherwise.
int isAscending(int num1, int num2, int num3)
{	
	// Obtain 3rd-last digit of number.
	// this digit represents number in hundredth position.
	num1 /= 100;
	num1 %= 10;

	num2 /= 100;
	num2 %= 10;

	num3 /= 100;
	num3 %= 10;

	return ((num1 < num2) && (num1 < num3) && (num2 < num3));
}

