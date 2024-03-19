// CS1010 Programming Methodology
// Problem Set 4 Exercise #04: print_copies.c
//
// This program prints duplicated copies of an
// input string, up to a total of 10 characters.
//
// SHEIKH UMAR

#include <stdio.h>
#include <string.h>
#define LEN 6 

int main(void)
{
	char input[LEN];
	int i, input_len, rounds;

	printf("Enter a string: ");
	scanf("%s", input);

	input_len = strlen(input);
	rounds = 10 / input_len;

	for (i = 0 ; i < rounds; i++)
	{
		printf("%s",input);
	}
	printf("\n");

	return 0;
}
