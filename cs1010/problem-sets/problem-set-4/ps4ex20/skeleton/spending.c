// CS1010 Programming Methodology
// Problem Set 4 Exercise #20: spending.c
//
// This program prints the spending of
// a particular customer in descending order.
//
// <Replace this with your name>

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50
#define MAX_CUSTOMER 20
#define MAX_RECORD 100

typedef struct {
	int id;
	char name[MAX_LENGTH+1];
} customer_t;

typedef struct {
	int cusID;
	char category[MAX_LENGTH+1];
	int spending;
} record_t;

int find_records(customer_t customers[MAX_CUSTOMER], int num_customers,
		record_t records[MAX_RECORD], int num_records, char name[MAX_LENGTH],
		record_t result[MAX_RECORD]);
void sort_records(record_t result[MAX_RECORD], int size);

int main(void) {

	// the following variables are suggested
	// you may want to add more
	char name[MAX_LENGTH];
	customer_t customers[MAX_CUSTOMER];
	record_t records[MAX_RECORD], result[MAX_RECORD];

	printf("Enter the number of customers: ");

	printf("Enter customers:\n");

	printf("Enter the number of records: ");

	printf("Enter records:\n");

	printf("Enter name: ");

	// now call find_records function

	// now call sort_records function

	printf("No record can be found for %s\n", name);
	
	printf("The records for %s are as follows: \n", name);

	return 0;
}

// Find all spending records for customer with given 'name'
// and store them into the result array.
// Return the number of elements in result array.
int find_records(customer_t customers[MAX_CUSTOMER], int num_customers,
		record_t records[MAX_RECORD], int num_records, char name[MAX_LENGTH],
		record_t result[MAX_RECORD]) {

	return 0; // stub
}

// Sort 'result' array in ascending order of spendings
void sort_records(record_t result[MAX_RECORD], int size) {

	// stub
}
