// CS1010 AY2013/4 Semester 2
// Problem Set 4 Exercise #06: word_game.c
//
// This program reads in a word and computes 
// the total points of all the letters in the word.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>
#include <ctype.h> // Functions that have character input MUST have <ctype.h> at header.
#include <string.h> // For any C Programming pertaining to strings, MUST include <string.h> at function header
#define MAX 21

int compute_score(char word[]);

int main(void)
{
	char word[MAX];
	printf("Enter a word: ");
	scanf("%s", word);  // read a sigle word
	printf("Total score = %d\n", compute_score(word));
	return 0;
}

// Compute total score of letters in a word
int compute_score(char word[])
{
	int i, sum = 0;
	
	for(i = 0; i < strlen(word); i++)
	{
		switch(word[i])
		{
			case 'A':
			case 'E':
			case 'I':
			case 'L':
			case 'N':
			case 'O':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
					sum += 1;
					break;

			case 'D':
			case 'G':
					sum += 2;
					break;

			case 'B':
			case 'C':
			case 'M':
			case 'P':
					sum += 3;
					break;

			case 'F':
			case 'H':
			case 'V':
			case 'W':
			case 'Y':
					sum += 4;
					break;

			case 'K':
					sum += 5;
					break;

			case 'J':
			case 'X':
					sum += 8;
					break;

			case 'Q':
			case 'Z':
					sum += 10;
					break;
		}
	}

	return sum;
}

