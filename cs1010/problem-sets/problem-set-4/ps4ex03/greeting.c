// CS1010 Programming Methodology
// Problem Set 4 Exercise #03: greeting.c
//
// This program reads age and gender of a person,
// print out corresponding information.
//
// SHEIKH UMAR

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int age;
	char gender;

	printf("Your age? ");
	scanf("%d", &age);
	
	printf("Your gender? ");
	scanf(" %c", &gender);

	gender = toupper(gender);

	if(age < 18)
	{
		if(gender == 'M')
		{
			printf("Hello boy\n");
		}
		else
		{	
			printf("Hey girl\n");
		}
	}
	else
	{
		if(gender == 'M')
		{
			printf("Hello Mr.\n");
		}
		else
		{
			printf("Hey Ms.\n");
		}
	}
	
	return 0;
}

