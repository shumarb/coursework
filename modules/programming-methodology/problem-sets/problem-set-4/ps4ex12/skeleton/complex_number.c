// CS1010 Programming Methodology
// Problem Set 4 Exercise #12: complex_number.c
//
// This program performs arithmetic calculation
// on complex numbers.
//
// <Replace this with your name>

#include <stdio.h>

typedef struct {
	int a, b;   // a + bi
} complex_t;

int main(void) {

	char operator;
	complex_t op1, op2;

	printf("Complex number (%d + %di) created\n"); // incomplete

	scanf(" %c", &operator); // ignore space b4 reading operator


	printf("After addition: ( + i)\n");

	printf("After subtraction: ( + i)\n");

	printf("After multiplication: ( + i)\n");

	printf("After division: ( + i)\n");

	return 0;
}
