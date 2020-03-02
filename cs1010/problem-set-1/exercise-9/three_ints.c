// CS1010 Programming Methodology
// Problem Set 1 Exercise #09: three_ints.c
//
// Program reads in 3 integers, and calculates the hundredth-placed digit of that integer
// Program displays that hundredth-placed digit corresponding to the integer entered
// Program prints out integer if it is less than 100
//
// SHEIKH UMAR

#include <stdio.h>

// function prototype
int get_hundredth(int num);

// main function is complete
int main(void) {

	int num1, num2, num3;   // inputs
	int digit;  // digit in hundredth position

	printf("Enter 3 positive integers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	digit = get_hundredth(num1);
	printf("%d ", digit);

	digit = get_hundredth(num2);
	printf("%d ", digit);

	digit = get_hundredth(num3);
	printf("%d\n", digit);

	return 0;
}

// Take a number and return the digit in hundredth position
int get_hundredth(int num) {
	//Return integer if it is less than 100
	if (num<100){
		return 0;
	}
	//101<=num<1000
	else if(num>=100 && num<1000){
		int i;
		i=num/100;//Divide num by 100 to its hundredth-placed digit
		return i;
	}
	//1001<=num<=10000
	else if (num>1000 && num<=10000){
		int i;
		i=num/100;//Divide num by 100 to obtain first 2 digits
		int j;
		j=i%10;//Modulo-divide i by 10 to obtain hundredth-placed digit
		return j;
	}
	//10001<=num<100000
	else if (num>1000 && num<=10000){
		int i;
		i=num/1000;//Divide num by 1000 to obtain first 2 digits
		int j;
		j=i%10;//Modulo-divide i by 10 to obtain hundredth-placed digit
		return j;
	}
	//100001<num<=1000000
	else{
		int i;
		i=num/10000;//Divide num by 10000 to obtain first 2 digits
		int j;
		j=i%10;//Modulo-divide i by 10 to obtain hundredth-placed digit
		return j;
	}
}	


