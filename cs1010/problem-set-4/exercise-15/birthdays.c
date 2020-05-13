// CS1010 Programming Methodology
// Problem Set 4 Exercise #15: birthday.c
//
// This program reads in a list of birthdays
// and checks if there exists two birthdays
// of the same day and month.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>
#define MAX 25

typedef struct {
	int day, month;
} date_t;

int read_birthdays(date_t bday[]);
int share_birthday(date_t bday[], int num);

int main(void)
{
	date_t birthdays[MAX];
	int input = read_birthdays(birthdays);

	printf("Group of %d having same birthday: ", input);

	if(share_birthday(birthdays, input))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}

// Read in all birthdays
// Return the number of birthdays read
int read_birthdays(date_t bday[])
{
	int input, j;

	printf("How many birthdays to input? ");
	scanf("%d", &input);

	printf("Enter %d birthdays, day followed by month each:\n", input);
	for(j = 0; j < input; j++)
	{
		scanf("%d %d", &bday[j].day, &bday[j].month);
	}

	return input;
}

// Check if any two birthdays in the array are the same
// Return 1 if so, or 0 otherwise
int share_birthday(date_t bday[], int num)
{
	int j, k;

	for(j = 0; j < num; j++)
	{
		for(k = j + 1; k < num; k++)
		{
			if((bday[j].day == bday[k].day) && (bday[j].month == bday[k].month))
			{
				return 1;
			}
		}
	}

	return 0;
}

