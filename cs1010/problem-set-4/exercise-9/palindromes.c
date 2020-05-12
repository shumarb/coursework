// CS1010 Programming Methodology
// Problem Set 4 Exercise #09: palindromes.c
//
// This program reads a list of input strings,
// reports how many of them are palindrome.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 90

int count_palindrome(char str[]);
void read_string(char str[]);
int is_palindrome(char str[]);

int main(void)
{
	int count;   // number of palindrome strings
	char str[MAX_LEN];

	count = count_palindrome(str);
	printf("Number of palindromes = %d\n", count);

	return 0;
}


// Count the number of palindromes
// in the input strings
int count_palindrome(char str[])
{
	int k, num, count = 0;
	char space;

	printf("How many strings? ");
	scanf("%d%c", &num, &space);
	printf("Enter %d strings, each on a line:\n", num);
	for(k = 0; k < num; k++)
	{
		read_string(str);
		if(is_palindrome(str))
		{
			count++;
		}
	}

	return count;
}


// Read one string using fgets and store into str
void read_string(char str[])
{
	fgets(str, MAX_LEN, stdin);
	if(str[strlen(str)] == '\n')
	{
		str[strlen(str)] = '\0';
	}

	int j, k = 0;
	char new[MAX_LEN];

	for(j = 0; j < strlen(str); j++)
	{
		if(isalpha(str[j]))
		{
			new[k++] = tolower(str[j]);// Input lowercase of alphabet in str to new
		}
	}
	new[k] = '\0';

	// Since j<(k+1), assign characters from 0 to k in new
	// to str, so NULLSPACE will be assigned to str
	for(j = 0; j < (k + 1); j++)
	{
		str[j] = new[j];
	}
}


// Check if str is a palindrome or not
// Return 1 if so, 0 otherwise
int is_palindrome(char str[])
{
	int lower = 0, upper = (strlen(str)) - 1;

	while(lower < upper)
	{
		if(str[lower] != str[upper])
		{
			return 0;
		}
		lower++;
		upper--;
	}

	return 1;
}

