// CS1010 Programming Methodology
// Problem Set 2 Exercise #18: uCard.c
//
// Program reads in a number, multiplies every even alternative digit from right,
// computes check number, determines if it is valid or not. Program prints it out.
// If valid, program determines its appropriate branch and prints it out.
//
// SHEIKH UMAR

#include <stdio.h>

int luhnah(int uCard);
void print_branch(int uCard);

int main(void) {
	int num, answer, digits;

	printf("Enter uCard Number: ");
	scanf("%d",&num);

	answer = luhnah(num); 
	printf("The check number is %d\n", answer);

	// Print out valid if check number is divisible by 7
	if ((answer % 7) == 0)
	{
		printf("Valid\n");

		// Extract first 2 digits if >100
		if ((num >= 10) && (num < 99))
		{
			digits = num;
		}
		else if ((num >= 100) && (num < 999))
		{
			digits = (num / 10);
		}
		else if ((num > 1000) && (num < 9999))
		{
			digits = (num / 100);
		}
		else if ((num >= 10000) && (num < 99999))
		{
			digits = (num / 1000);
		}
		else if ((num >= 100000) && (num < 99999))
		{
			digits = (num / 10000);
		}
		else if ((num >= 1000000) && (num < 9999999))
		{
			digits = (num /100000);
		}
		else if ((num >= 10000000) && (num < 99999999))
		{
			digits = (num / 1000000);
		}
		else
		{
			digits = (num /10000000);
		}
		print_branch(digits);
	}
	else
	{
		printf("Invalid\n");
	}

	return 0;
}

// Function extracts each digit,
// Doubles even-placed digits from right,
// Extracts each individual digit if it is >10
// Adds these numbers together.
int luhnah(int u_card) {
	int n1, n2, n3, n4, n5, n6, n7, n8, n9;
	int n10 = 0, n11 = 0,n12 = 0,n13 = 0;

	n1 = (u_card % 10);
	n2 = (((u_card / 10) % 10) * 2);
	n3 = ((u_card / 100) % 10);
	n4 = (((u_card / 1000) % 10) * 2);
	n5 = ((u_card / 10000) % 10);
	n6 = (((u_card / 100000) % 10) * 2);
	n7 = ((u_card / 1000000) % 10);
	n8 = (((u_card / 10000000) % 10) * 2);
	n9 = (u_card / 100000000);
	// printf("* %d %d %d %d %d %d %d %d %d\n",n1,n2,n3,n4,n5,n6,n7,n8,n9);

	if (n2 >= 10)
	{
		n10 = (n2 / 10);
		n2 = (n2 % 10);
		// printf("* %d %d\n",n2,n10);
	}

	if (n4 >= 10)
	{
		n11 = (n4 / 10);
		n4 = (n4 % 10);
		// printf("* %d %d\n",n4,n11);
	}

	if (n6 >= 10)
	{
		n12 = (n6 / 10);
		n6 = (n6 % 10);
		// printf("* %d %d\n",n6,n12);
	}

	if (n8 >= 10)
	{
		n13 = (n8 / 10);
		n8 = (n8 % 10);
		// printf("* %d %d\n",n8,n13);
	}

	return (n13 + n12 + n11 + n10 + n9 + n8 + n7 + n6 + n5 + n4 + n3 + n2 + n1);
}


// Function determines type of issuing branch based on front 2 numbers of number entered,
// and check number is divisible by 7.
void print_branch(int num)
{
	if ((num >= 31) && (num <= 35))
	{
		printf("Issued by East branch\n");
	}
	else if ((num >= 51) && (num <= 55))
	{
		printf("Issued by West branch\n");
	}
	else
	{
		printf("Issued by Central branch\n");
	}
}
