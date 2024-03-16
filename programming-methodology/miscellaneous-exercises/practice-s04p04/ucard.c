// CS1010 AY2012/3 Semester 1
// PE1 Ex2: ucard.c
// Name: Sheikh Umar
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:

#include <stdio.h>

int luhnah(int);
void issued(int);

int main(void) {
	int uCardNo, check_number; 

	printf("Enter uCard Number: ");
	scanf("%d", &uCardNo);

	check_number = luhnah(uCardNo);
	printf("The check number is %d\n", check_number);

	if ((check_number % 7) == 0)
	{
		printf("Valid\n");
		issued(uCardNo);
	}
	else
	{
		printf("Invalid\n");
	}
	
	return 0;
}

int luhnah(int uCardNo)
{
	int digit, is_even = 1, sum = 0, is_test = 0;

	while (uCardNo != 0)
	{
		digit = uCardNo % 10;

		// check if digit extracted
		// is in even-positioned of check_number
		// from the right
		// if it is, multiply it by 2
		if ((is_even % 2) == 0)
		{
			digit *= 2;
		}

		while (digit != 0)
		{	
			sum += (digit % 10);
			digit /= 10;
		}

		is_even++;
		uCardNo /= 10;
	}

	if (is_test)
	{
		printf("sum = %d\n", sum);
	}

	return sum;
}

void issued(int uCardNo)
{	
	// obtain first 2 digits of check number
	while (uCardNo >= 100)
	{
		uCardNo /= 10;
	}
	
	int is_test = 0;
	if (is_test)
	{
		printf("first 2 digits are %d\n", uCardNo);
	}

	printf("Issued by ");
	if (uCardNo >= 31 && uCardNo <= 35)
	{
		printf("East branch\n");
	}
	else if (uCardNo >= 51 && uCardNo <= 55)
	{
		printf("West branch\n");
	}
	else
	{
		printf("Central branch\n");
	}
}
