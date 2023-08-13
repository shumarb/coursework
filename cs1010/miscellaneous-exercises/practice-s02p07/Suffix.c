// Suffix.c
// This program reads a positive integer and 
// prints the value with the correct ordinal suffix.
//
// SHEIKH UMAR
#include <stdio.h>

void printSuffix(int);

int main(void) {    
	int value;

	printf("Enter value: ");
	scanf("%d", &value);

	printf("%d", value);
	printSuffix(value);

	return 0;
}

// This function prints the corresponding 
// ordinal suffix for value.
void printSuffix(int value) {

	// For numbers with last 2 digits of 11, 12, 13, display suffix 'th'
	if ((value % 100) == 11 || (value % 100) == 12 || (value % 100) == 13)
	{
		printf("th\n");
	}

	// For numbers whose last 2 digits are neither 11, 12, or 13
	else
	{
		// For numbers with last digit of 1 and number is not 11, print suffix 'st'
		if ((value % 10) == 1)
		{
			printf("st\n");
		}

		// For numbers with last digit of 2 and number is not 12, print suffix 'nd'
		else if ((value % 10) == 2)
		{
			printf("nd\n");
		}

		// For numbers with last digit of 3 and number is not 13, print suffix 'rd'
		else if ((value % 10) == 3)
		{
			printf("rd\n");
		}
		
		// For remaining numbers where top condition is not satisfied, print th
		else
		{
			printf("th\n");
		}
	}
}

