// NRIC.c
// This program computes NRIC check code.
//
// SHEIKH UMAR
#include <stdio.h>

char generateCode(int);

int main(void) {    
	int number;
	char code;

	printf("Enter 7-digit NRIC number: ");
	scanf("%d", &number);

	code = generateCode(number);

	printf("Check code is %c\n", code);

	return 0;
}

// This function generates the check code for NRIC num
char generateCode(int num) {
	char code;
	int val = 0, last_digit, to_subtract, is_test = 0;

	// Step 1: Extract digit, multiply it by corresponding digit, then add it to val.

	// Extraction 1
	if (is_test)
	{	
		printf("before extraction, num = %d\n", num);
	}
	last_digit = num % 10;
	val += last_digit * 2;
	num /= 10;
	if (is_test)
	{	
		printf("after extraction, num = %d, last_digit = %d, val = %d\n", num, last_digit, val);
	}
	
	// Extraction 2
	if (is_test)
	{	
		printf("before extraction, num = %d\n", num);
	}
	last_digit = num % 10;
	val += last_digit * 3;
	num /= 10;
	if (is_test)
	{	
		printf("after extraction, num = %d, last_digit = %d, val = %d\n", num, last_digit, val);
	}
	
	// Extraction 3
	if (is_test)
	{	
		printf("before extraction, num = %d\n", num);
	}
	last_digit = num % 10;
	val += last_digit * 4;
	num /= 10;
	if (is_test)
	{	
		printf("after extraction, num = %d, last_digit = %d, val = %d\n", num, last_digit, val);
	}
	
	// Extraction 4
	if (is_test)
	{	
		printf("before extraction, num = %d\n", num);
	}
	last_digit = num % 10;
	val += last_digit * 5;
	num /= 10;
	if (is_test)
	{	
		printf("after extraction, num = %d, last_digit = %d, val = %d\n", num, last_digit, val);
	}
	
	// Extraction 5
	if (is_test)
	{	
		printf("before extraction, num = %d\n", num);
	}
	last_digit = num % 10;
	val += last_digit * 6;
	num /= 10;
	if (is_test)
	{	
		printf("after extraction, num = %d, last_digit = %d, val = %d\n", num, last_digit, val);
	}
	
	// Extraction 6
	if (is_test)
	{	
		printf("before extraction, num = %d\n", num);
	}
	last_digit = num % 10;
	val += last_digit * 7;
	num /= 10;
	if (is_test)
	{	
		printf("after extraction, num = %d, last_digit = %d, val = %d\n", num, last_digit, val);
	}
	
	// Extraction 7
	if (is_test)
	{	
		printf("before extraction, num = %d\n", num);
	}
	last_digit = num % 10;
	val += last_digit * 2;
	if (is_test)
	{	
		printf("after extraction, num = %d, last_digit = %d, val = %d\n", num, last_digit, val);
	}
	

	// Step 2: Obtain remainder of val in step 1 divided by 11 
	to_subtract = (val % 11);
	if (is_test)
	{	
		printf("after step 2, to_subtract = %d\n", to_subtract);
	}

	// Step 3: Subtract 2 from value obtained in Step 2
	val = 11 - to_subtract;
	if (is_test)
	{	
		printf("after step 3, val = %d\n", val);
	}

	// Step 4: Match val to corresponding character in table, and return this character
	switch (val) 
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

