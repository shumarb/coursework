// CS1010 Programming Methodology
// Problem Set 4 Exercise #10: compatible.c
//
// This program removes common characters
// in two names, ignoring cases. Then check
// whether the remains two strings both have
// odd or even characters.
//
// SHEIKH UMAR

#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Name has at most 35 characters
#define MAXLEN 36

void match(char [], char [], int *, int *);
void read_name(char []);

int main(void)
{
	char name_1[MAXLEN], name_2[MAXLEN];
	int remain_1, remain_2;// number of remaining letters in name1 and name2 after matching

	printf("Enter 2 names below:\n");
	read_name(name_1); // do not remove/change this line
	read_name(name_2); // do not remove/change this line

	// Call the match() function here
	match(name_1, name_2, &remain_1, &remain_2);

	printf("Number of letters remaining in 1st name = %d\n", remain_1);
	printf("Number of letters remaining in 2nd name = %d\n", remain_2);

	if (((remain_1 % 2) == 0 && (remain_2 % 2) == 0) || ((remain_1 % 2) != 0 && (remain_2 % 2) != 0))
	{
		printf("The names are compatible.\n");
	}
	else
	{
		printf("The names are not compatible.\n");
	}

	return 0;
}

// Read a name (may contain spaces) using fgets
void read_name(char name[])
{
	fgets(name,MAXLEN,stdin);
	int j;

	if (name[strlen(name)] == '\n')
	{
		name[strlen(name)] = '\0';
	}

	for (j = 0; j < strlen(name); j++)
	{
		name[j] = tolower(name[j]);
	} 
}

// We cross out common characters from both names,
// and return the number of remaining letters in both names.
void match(char name_1[], char name_2[], int *count1_p, int *count2_p)
{
	*count1_p = 0;
	*count2_p = 0;
	int j, k;

	for (j = 0; j < strlen(name_1); j++)
	{
		for (k = 0; k < strlen(name_2); k++)
		{
			if (name_1[j] == name_2[k])
			{
				name_1[j] = name_2[k] = '!';
				break;
			}
		}
	}

	for (j = 0; j < strlen(name_1); j++)
	{
		if (isalpha(name_1[j]))
		{
			(*count1_p)++;
		}
	}

	for (j = 0; j < strlen(name_2); j++)
	{
		if (isalpha(name_2[j]))
		{
			(*count2_p)++;
		}
	}
}
