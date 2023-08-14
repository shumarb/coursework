// validate.c
// To read age from user, until the 
// age entered is valid (1 - 100).
//
// SHEIKH UMAR
#include <stdio.h>

int main(void) {    
	int num_attempts = 0, age;

	do
	{
		printf("Enter age: ");
		scanf("%d", &age);
		num_attempts++;
	} while (age < 1 || age > 100);

	printf("Your age is %d.\n", age);
	printf("Number of attempts = %d\n", num_attempts);

	return 0;
}

