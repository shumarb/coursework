// CS1010 Programming Methodology
// Problem Set 4 Exercise #29: odd_digit_sum.c
//
// This program checks whether the sum of
// all digits is odd.
//

#include <stdio.h>

int is_sum_odd(int num);

int main(void) {

	int number;

	printf("Enter a positive integer: ");
	scanf("%d", &number);

	printf("Sum of digits for %d", number);
	if ( is_sum_odd(number) ) {
		printf(" is odd\n");
	} else {
		printf(" is not odd\n");
	}

	return 0;
}

// Check the sum of all digits,
// return 1 if odd, 0 otherwise.
// Given num is positive initially
int is_sum_odd(int num) {


	return 0; // stub
}
