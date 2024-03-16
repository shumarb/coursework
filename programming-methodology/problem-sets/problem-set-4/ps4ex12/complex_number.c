// CS1010 Programming Methodology
// Problem Set 4 Exercise #12: complex_number.c
//
// This program performs arithmetic calculation
// on complex numbers.
//
// SHEIKH UMAR

#include <ctype.h>
#include <stdio.h>

typedef struct {
	int a, b;   // a + bi
} complex_t;

int main(void)
{
	char operator;
	int real, imag, is_done = 0, is_stop = 0;
	complex_t op1, op2;

	scanf("%d %d", &op1.a, &op1.b);
	printf("Complex number (%d + %di) created\n", op1.a, op1.b); // incomplete
	scanf(" %c", &operator); // ignore space b4 reading operator
	scanf(" %d %d", &op2.a, &op2.b);

	// Check if 'q' was entered. If yes, don't proceed with calculation
	while (!is_stop)
	{
		if (is_done == 1)
		{
			scanf("%d %d", &op2.a, &op2.b);
		}
		switch (operator)
		{
			case '+':
				real = op1.a + op2.a;
				imag = op1.b + op2.b;
				op1.a = real;
				op1.b = imag;
				printf("After addition: (%d + %di)\n", real, imag);
				// printf("op1.a = %d, op1.b = %d\n", op1.a, op1.b);
				is_done = 1;
				break;

			case '-':
				real = op1.a - op2.a;
				imag = op1.b - op2.b;
				op1.a = real;
				op1.b = imag;
				printf("After subtraction: (%d + %di)\n", real, imag);
				// printf("op1.a = %d, op1.b = %d\n", op1.a, op1.b);
				is_done = 1;
				break;

			case '*':
				real = ((op1.a) * (op2.a)) - ((op1.b) * (op2.b));
				imag = ((op1.b) * (op2.a)) + ((op1.a) * (op2.b));
				op1.a = real;
				op1.b = imag;
				printf("After multiplication: (%d + %di)\n", real, imag);
				// printf("op1.a = %d, op1.b = %d\n", op1.a, op1.b);
				is_done = 1;
				break;

			case '/':
				if (op2.a == 0 || op2.b == 0)
				{
					real = 0;
					imag = 0;
					op1.a = real;
					op1.b = imag;
					is_done = 1;
					printf("After division: (%d + %di)\n", real, imag);
					// printf("op1.a = %d, op1.b = %d\n", op1.a, op1.b);
				}
				else
				{
					real = (((op1.a) * (op2.a)) + ((op1.b) * (op2.b))) / (((op2.a) * (op2.a)) + ((op2.b) * (op2.b)));
					imag = (((op1.b) * (op2.a)) - ((op1.a) * (op2.b))) / (((op2.a) * (op2.a)) + ((op2.b) * (op2.b)));
					op1.a = real;
					op1.b = imag;
					is_done = 1;
					// printf("op1.a = %d, op1.b = %d\n", op1.a, op1.b);
					printf("After division: (%d + %di)\n", real, imag);
				}
				break;
		}
		
		scanf(" %c", &operator);// Operator and space
		if (operator == 'q')
		{
			is_stop = 1;
		}
	}

	return 0;
}
