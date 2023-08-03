// CS1010 Programming Methodology
// Problem Set 4 Exercise #13: younger.c
//
// This program reads in the particulars of two persons,
// prints out the name of the younger one.
//
// SHEIKH UMAR

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	int day, month, year;
} date_t;

typedef struct {
	char name[10];  // single word name
	date_t bday;    // birthday
} person_t;

person_t scan_person();
int is_younger(person_t per1, person_t per2);

int main(void)
{
	person_t person1, person2;
	int result;

	printf("Particular of 1st person: ");
	person1 = scan_person();

	printf("Particular of 2nd person: ");
	person2 = scan_person();

	result = is_younger(person1, person2);

	// person 1 is younger
	if (result == -1)
	{
		printf("%s is younger\n", person1.name);
	}

	// person 2 is younger
	else if (result == 1)
	{
		printf("%s is younger\n", person2.name);
	}
	
	// return value 0 means of the same age
	else
	{ 
		printf("%s and %s are of the same age\n", person1.name, person2.name);
	}

	return 0;
}

// Read and return a person's particulars (name and bday)
// Returns a structure and its values are assigned to either person1 or person2
person_t scan_person()
{
	person_t info;
	scanf("%s %d %d %d", info.name, &info.bday.day, &info.bday.month, &info.bday.year);

	return info;	
}

// Compare ages of two persons, per1 and per2.
// Return -1 if per1 is younger.
// Return  1 if per2 is younger.
// Return  0 if they are of the same age.
int is_younger(person_t per1, person_t per2)
{
	if(per2.bday.year > per1.bday.year)
	{
		return 1;
	}
	else if(per1.bday.year > per2.bday.year)
	{
		return -1;
	}
	else
	{
		if(per2.bday.month > per1.bday.month)
		{
			return 1;
		}
		else if(per1.bday.month > per2.bday.month)
		{
			return -1;
		}
		else
		{
			if(per2.bday.day > per1.bday.day)
			{
				return 1;
			}
			else if(per1.bday.day > per2.bday.day)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}

