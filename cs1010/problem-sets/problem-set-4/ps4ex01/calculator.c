// CS1010 Programming Methodology
// Problem Set 4 Exercise #01: calculator.c
//
// This program implements a simple calculator
// that can perform addition, subtraction,
// multiplication and division on integers.
//
// SHEIKH UMAR

#include <stdio.h>

void print_result(int, char, int);

int main(void)
{
	char operator;
	int i, num, num_1, num_2;

	printf("Enter the number of operations: ");
	scanf("%d", &num);

	for (i = 0 ; i < num; i++)
	{
		scanf("%d%c%d", &num_1, &operator, &num_2);
		print_result(num_1, operator, num_2);
	}

	return 0;
}

void print_result(int num_1, char operator, int num_2)
{
	double answer_div;
	int answer;

	// Compute
	if (operator == '/')
	{
		double num_1_double = num_1, num_2_double = num_2;
		answer_div = num_1_double / num_2_double;
		printf("%d%c%d = %.2lf\n", num_1, operator, num_2, answer_div);
	}
	
	else
	{
		if (operator == '+')
		{
			answer = num_1 + num_2;
		}
		else if (operator == '-')
		{
			answer = num_1 - num_2;
		}
		else
		{
			answer = num_1 * num_2;
		}
		printf("%d%c%d = %d\n", num_1, operator, num_2, answer);
	}
}
