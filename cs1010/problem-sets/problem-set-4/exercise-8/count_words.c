// CS1010 Programming Methodology
// Problem Set 4 Exercise #08: count_words.c
//
// This program reads in a sentence, counts
// the number of English word inside.
//
// SHEIKH UMAR

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

int count_words(char sentence[]);

int main(void) {
	int len;
	char text[MAX];
	printf("Enter a sentence: ");
	fgets(text, MAX, stdin);
	len = strlen(text);
	if (text[len-1] == '\n') {
		text[len-1] = '\0';
	}
	printf("Word count = %d\n", count_words(text));
	return 0;
}

// count the number of English word inside a sentence
int count_words(char sentence[]) {
	int i,count=0;

	// Change non-alphabets to space
	for(i=0;i<strlen(sentence);i++){
		if( !isalpha(sentence[i]) ){
			sentence[i] = ' ';
		}
	}
	
	// Increase count if current element is a character
	// and next element is either a space of NULLSPACE
	for(i=0;i<strlen(sentence);i++){
		if( isalpha(sentence[i]) && !isalpha(sentence[i+1]) ){
			count++;
		}
	}
	return count;
}
