// CS1010 Programming Methodology
// Problem Set 2 Exercise #17: winners.c
//
// Program reads in two digits and number of participants,
// and computes and prints out number of winners based on certain conditions being met.

#include <stdio.h>

int counter(int, int, int);

int main(void)
{
	int factor, must_have, total_participants;

	printf("Enter factor-digit: ");
	scanf("%d", &factor);
	printf("Enter must-have-digit: ");
	scanf("%d", &must_have);
	printf("Enter the number of participants: ");
	scanf("%d", &total_participants);

	printf("Number of winners: %d\n", counter(factor, must_have, total_participants));

	return 0;
}

int counter(factor, digit, total)
{
	int i, counter = 0;
	
	for(i = factor; i <= total; i += factor)
	{
		if((i < 10) && (i == digit))
		{
			counter++;
		}
		
		if(i >= 10 && i <= 99)
		{
			int first_digit = (i % 10);
			int second_digit = (i / 10);
			if(first_digit == digit || second_digit == digit)
			{
				counter++;
			}
		}
		
		if(i >= 100 && i <= 999)
		{
			int first_digit = (i % 10);
			int second_digit = ((i / 10) % 10);
			int third_digit = (i / 100);
			if(first_digit == digit || second_digit == digit || third_digit == digit)
			{
				counter++;
			}
		}
		
		if(i >= 1000 && i <= 9999)
		{
			int first_digit = (i % 10);
			int second_digit = ((i / 10) % 10);
			int third_digit = ((i / 100) % 10);
			int fourth_digit = (i / 1000);
			if(first_digit == digit || fourth_digit == digit || second_digit == digit || third_digit == digit)
			{
				counter++;
			}
		}
		
		if(i >= 10000 && i <= 99999)
		{
			int first_digit = (i % 10);
			int second_digit = ((i / 10) % 10);
			int third_digit = ((i / 100) % 10);
			int fourth_digit = ((i / 1000) % 10);
			int fifth_digit = (i / 10000);
			if(first_digit == digit || fifth_digit == digit || fourth_digit == digit || second_digit == digit || third_digit == digit)
			{
				counter++;
			}
		}
	}
	
	return counter;
}
