// CS1010 Programming Methodology
// Problem Set 4 Exercise #07: my_str_functions.c
//
// This program writes our own string functions:
// my_strlen(), my_strcpy(), my_strcat() and my_strcmp().
//
// SHEIKH UMAR

#include <math.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int my_strcmp(char s1[], char s2[]);
int my_strlen(char s[]);
void my_strcat(char s1[], char s2[]);
void my_strcpy(char s1[], char s2[]);
void read_string(char str[]);

int main(void)
{
	/** main function is complete **/

	char s1[MAX], s2[MAX];

	printf("Enter s1: ");
	read_string(s1);

	printf("Enter s2: ");
	read_string(s2);

	printf("my_strlen(s1) returns %d\n", my_strlen(s1));

	printf("my_strlen(s2) returns %d\n", my_strlen(s2));

	printf("my_strcmp(s1, s2) returns %d\n", my_strcmp(s1, s2));

	my_strcat(s1, s2);
	printf("my_strcat(s1, s2) returns %s\n", s1);

	my_strcpy(s1, s2);
	printf("my_strcpy(s1, s2) returns %s\n", s1);

	return 0;
}

// Read a string from user input
void read_string(char str[])
{
	/** read_string function is complete **/

	int len;

	fgets(str, MAX, stdin);
	len = strlen(str);
	if (str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}

// Return the number of characters in string
// before termination null character
int my_strlen(char s[])
{
	int j, count = 0;
	int len = strlen(s);
	for (j = 0; j < len; j++)
	{
		count++;
	}

	return count; // stub
}


void my_strcpy(char s1[], char s2[])
{
	int i;
	
	// Update values of s1 based on its corresponding values in s2
	// Then update the next value after the last recorded character
	// to be NULLSPACE
	int len = my_strlen(s2);
	for (i = 0; i < len; i++)
	{
		s1[i] = s2[i];
	}
	
	s1[strlen(s2)] = '\0';
}


// Append a copy of string s2, including
// '\0', to the end of string s1
void my_strcat(char s1[], char s2[])
{

	int j, k = 0;
	int len_1 = my_strlen(s1), len_2 = my_strlen(s2);
	int total = len_1 + len_2;
	char new_str[MAX];
	for (j = 0; j < len_1; j++)
	{
		new_str[j] = s1[j];
	}
	
	for (j = len_1; j < total; j++)
	{
		new_str[j] = s2[k];
		k++;
	}

	//Update s1 to be new_str
	//Always update NULLSPACE after last character in new_str
	for (j = 0; j < total; j++)
	{
		s1[j] = new_str[j];
	}
	s1[total] = '\0';
}


// Compare s1 and s2 character by character
// Return 15 if s1 > s2, -15 if s1 < s2, or 0 if s1 = s2.
// Return value 15 is just an example.
int my_strcmp(char s1[], char s2[])
{
	int len_1 = my_strlen(s1), len_2 = my_strlen(s2);
	int j, range, done = 0, answer; 

	if (len_1 == len_2)
	{
		range = len_1;
	}
	else
	{
		range = fmin(len_1, len_2);
	}

	for (j = 0; j < (range + 1) && done == 0; j++)
	{
		// printf("s1: %c, s2: %c\n", s1[j], s2[j]);
		if (s1[j] > s2[j])
		{
			answer = 15;
			done = 1;
		}
		else if (s1[j] == s2[j])
		{
			answer = 0;
		}
		else
		{
			answer = -15;
			done = 1;
		}
	}

	return answer;
}
