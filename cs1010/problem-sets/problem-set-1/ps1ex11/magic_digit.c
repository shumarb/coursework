// CS1010 Programming Methodology
// Problem Set 1 Exercise #11: magic_digit.c
//
// Program reads in a 5-digit number,
// then obtains the first-,third-,and fifth-positioned digits.
// Next, program adds these digits to form a number.
// Finally, program obtains the last digit of this number
// and prints it out.
//
// SHEIKH UMAR

#include <stdio.h>

// function prototype
int get_magic(int num);

int main(void) {

	/** main function is complete **/

	int num, digit;

	// process first number
	printf("Enter 1st number: ");
	scanf("%d", &num);
	digit = get_magic(num);
	printf("Magic digit = %d\n",digit);

	// process second number
	printf("Enter 2nd number: ");
	scanf("%d", &num);
	digit = get_magic(num);
	printf("Magic digit = %d\n", digit);

	return 0;
}

// Take a number and return the magic digit 
int get_magic(int num) {
	
	// Obtain fifth-placed digit by modulo division
	int fifth_digit = num % 10;
	
	// Obtain third-placed digit by dividing num by 100, and modulo-divide by 10
	int third_digit = (num / 100) % 10;
	
	// Obtain first-placed digit by integer division
	int first_digit = num / 10000;

	//Add the digits above to form a new number
	int new_num = first_digit + third_digit + fifth_digit;

	//Obtain last digit of new number by modulo division
	int magic_digit = new_num % 10;

	//Return magic_digit to main function
	return magic_digit;
}

