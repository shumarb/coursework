// CS1010 Programming Methodology
// Problem Set 3 Exercise #10: soft_toys.c
//
// This program checks on which day Kitty
// is able to collect all 5 types of soft
// toys or she is unable to do it.
//
// SHEIKH UMAR

#include <stdio.h>
#define SIZE 100

int which_day(int [], int);

int main(void)
{
	int days, j, types[SIZE];

	printf("How long will the campaign last: ");
	scanf("%d", &days);

	printf("Enter type of toys in each day: ");
	for (j = 0; j < days; j++)
	{
		scanf("%d", &types[j]);
	}
	
	if (which_day(types, days) > 0)
	{
		printf("Kitty is able to collect all types of toys on day %d\n", which_day(types, days));
	}
	else
	{	
		printf("Kitty is unable to collect all types of toys\n");
	}

	return 0;
}

// Return the day on which Kitty is able to
// collect all 5 types of soft toys, or -1 if
// she is unable to do so before the campaign ends
int which_day(int types[], int size)
{
	int collection[5] = {0};
	int j, day = 0;

	for (j = 0; j < size; j += 2)
	{
		if (j == 0 || types[j] != types[j-2])
		{
			if (j == 0)
			{
				day = 0;
				collection[types[j] - 1]++;
			}
			else
			{
				day += 2;
				collection[types[j] - 1]++;
			}
		}
	}

	for (j = 0; j < 5; j++)
	{
		if (collection[j] == 0)
		{
			day = -1;
			break;
		}
	}

	return day;
}
