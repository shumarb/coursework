// CS1010 Programming Methodology
// Problem Set 4 Exercise #17: roster.c
//
// This program reads student number and major,
// and prints out the student roster in
// ascending order of student number.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>
#include <string.h>
#define NUM_STUD 1000  // max 1000 students in class 

typedef struct {
	char number[10];    // student number
	char major[15]; 
} student_t;

int read_roster(student_t roster[]);
void sort_roster(student_t roster[], int size);
void print_roster(student_t roster[], int size);

int main(void)
{
	int size;  // actual number of students
	student_t roster[NUM_STUD]; // class roster

	// read student info.
	size = read_roster(roster);

	// sort roster accoding to ascending order of student
	sort_roster(roster, size);

	// print roster
	print_roster(roster, size);

	return 0;
}

// Read student and major of students into array 'roster',
// return the number of students read.
int read_roster(student_t roster[])
{
	int len, j, size;

	printf("Enter the number of students in class: ");
	scanf("%d", &size);

	printf("Enter student number and major of each student:\n");
	for(j = 0; j < size; j++)
	{
		scanf("%s %s", roster[j].number, roster[j].major);	
	}
	len = strlen(roster[j].major);
	if(roster[j].major[len] == '\n')
	{
		roster[j].major[len] = '\0';
	}

	return size; 
}

// Sort roster according to ascending order of student number
void sort_roster(student_t roster[], int size)
{
	int j, k;
	student_t temp;

	// Use selection sort
	for(j = 0; j < size - 1; j++)
	{
		for(k = j + 1; k < size; k++)
		{
			// If number on left is more than number on its right, swap.
			if(strcmp(roster[j].number, roster[k].number) > 0)
			{
				// printf("To swap: %s with %s\n", roster[j].number, roster[k].number);
				temp = roster[k];
				roster[k] = roster[j];
				roster[j] = temp;
			}
		}
	}
}

// Print the roster
// Complete and given
void print_roster(student_t roster[], int size)
{
	int i;
	printf("Sorted list:\n");
	for (i = 0; i < size; i++)
	{
		printf("%-10s%-12s\n", roster[i].number, roster[i].major);
	}
}

