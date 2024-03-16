// Suffix.c
// This program reads a positive integer and 
// prints the value with the correct ordinal suffix.
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

}

