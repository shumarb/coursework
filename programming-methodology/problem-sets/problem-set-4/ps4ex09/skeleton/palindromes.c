// CS1010 Programming Methodology
// Problem Set 4 Exercise #09: palindromes.c
//
// This program reads a list of input strings,
// reports how many of them are palindrome.
//
// <Replace this with your name>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 81

int count_palindrome(char str[]);
void read_string(char str[]);
int is_palindrome(char str[]);

int main(void) {

	int count;   // number of palindrome strings

	char str[MAX_LEN];

	count = count_palindrome(str);

	printf("Number of palindromes = %d\n", count);

	return 0;
}


// Count the number of palindromes
// in the input strings
int count_palindrome(char str[]) {

	printf("How many strings? ");

	printf("Enter  strings, each on a line:\n");

	return 0; // stub
}


// Read one string using fgets and store into str
void read_string(char str[]) {

}


// Check if str is a palindrome or not
// Return 1 if so, 0 otherwise
int is_palindrome(char str[]) {

	return 0; // stub
}
