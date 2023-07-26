// CS1010 Programming Methodology
// Problem Set 4 Exercise #02: ic_check_code.c
//
// This program reads an NRIC number
// and produces its check code.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>

char generate_code(int num);

int main(void)
{
	/** main function is complete **/
	int num;
	
	printf("Enter 7-digit NRIC number: ");
	scanf("%d", &num);
	printf("Check code is %c\n", generate_code(num));

	return 0;
}

// Generate check code according
// to the given algorithm
char generate_code(int num)
{
	int counter = 6, digit, sum = 0, weights[7] = {2, 7, 6, 5, 4, 3, 2};
	int remainder, code_num;
	char code;

	while(num > 0)
	{
		digit = num % 10;
		sum += digit * weights[counter];
		counter--;
		num /= 10;
		// printf("%d %d\n", num, sum);
	}

	remainder = sum % 11;
	code_num = 11 - remainder;

	switch(code_num)
	{
		case 1:
			code = 'A';
			break;
		case 2:
			code = 'B';
			break;
		case 3:
			code = 'C';
			break;
		case 4:
			code = 'D';
			break;
		case 5:
			code = 'E';
			break;
		case 6:
			code = 'F';
			break;
		case 7:
			code = 'G';
			break;
		case 8:
			code = 'H';
			break;
		case 9:
			code = 'I';
			break;
		case 10:
			code = 'Z'; 
			break;
		case 11:
			code = 'J';
			break;
	}
	
	return code;
}

