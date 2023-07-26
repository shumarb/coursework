// CS1010 Programming Methodology
// Problem Set 2 Exercise #03: age.c
//
// Program reads in age, keeps asking user for it if it falls out of range.
// Program takes note of number of attempts for correct age.
// Program prints out age that meets criteria and number of attempts needed

#include <stdio.h>

int main(void)
{
	int age, counter = 0;

	printf("Enter age: ");
	scanf("%d", &age);
	counter++;
	
	// Keep asking for age if it falls out of range.
	// Increase counter for every input entered.
	while((age < 1) || (age > 100))
	{
		printf("Enter age: ");
		scanf("%d", &age);
		counter++;
	}

	printf("Your age is %d\n", age);
	printf("Number of attempts = %d\n", counter);

	return 0;
}

