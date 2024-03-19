// CS1010 Programming Methodology
// Problem Set 4 Exercise #20: spending.c
//
// This program prints the spending of
// a particular customer in descending order.
//
// SHEIKH UMAR

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX_CUSTOMER 20
#define MAX_LENGTH 50
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

int find_records(customer_t [MAX_CUSTOMER], int, record_t [MAX_RECORD], int, char [MAX_LENGTH], record_t [MAX_RECORD]);
void sort_records(record_t result[MAX_RECORD], int size);

int main(void)
{

	int num_customers, num_records, j, val;
	char name[MAX_LENGTH];

	customer_t customers[MAX_CUSTOMER];
	record_t records[MAX_RECORD], result[MAX_RECORD];

	printf("Enter the number of customers: ");
	scanf("%d", &num_customers);

	printf("Enter customers:\n");
	for (j = 0; j < num_customers; j++)
	{
		scanf("%d %s", &customers[j].id, customers[j].name);
	}

	printf("Enter the number of records: ");
	scanf("%d", &num_records);

	printf("Enter records:\n");
	for (j = 0; j < num_records; j++)
	{
		scanf("%d %s %d", &records[j].cusID, records[j].category, &records[j].spending);
	}

	printf("Enter name: ");
	scanf("%s", name);

	// now call find_records function
	val = find_records(customers, num_customers, records, num_records, name, result);
	if (val == 0)
	{
		printf("No record can be found for %s\n", name);
	}
	else
	{
		sort_records(result, val);
		printf("The records for %s are as follows: \n", name);
		// Print out only spending category and spending fee of name
		for (j = 0; j < val; j++)
		{
			printf("%s %d\n", result[j].category, result[j].spending);
		}
	}

	return 0;
}

// Find all spending records for customer with given 'name'
// and store them into the result array.
// Return the number of elements in result array.
int find_records(customer_t customers[MAX_CUSTOMER], int num_customers, record_t records[MAX_RECORD], int num_records, char name[MAX_LENGTH], record_t result[MAX_RECORD])
{
	int id, j, k = 0, is_done = 0;
	for (j = 0; j < num_customers && is_done == 0; j++)
	{
		if (strcmp(name, customers[j].name) == 0)
		{
			id = customers[j].id;
			is_done = 1;
		}
	}
	
	// If done == 0, name is not found in records, so return 0.
	if (is_done == 0)
	{
		return 0;
	}

	// If done==1, a name is found in records, so run through records array
	// to store records of name's ID, spending category and price into results
	else
	{
		for (j = 0; j < num_records; j++)
		{
			if (id == records[j].cusID)
			{
				result[k++] = records[j];
			}
		}
	}

	return k;
}

// Sort 'result' array in ascending order of spendings
void sort_records(record_t result[MAX_RECORD], int size)
{
	record_t temp;
	int j, k;
	for (j = 0; j < size - 1; j++)
	{
		for (k = j + 1; k < size; k++)
		{
			if (result[j].spending < result[k].spending)
			{
				temp = result[j];
				result[j] = result[k];
				result[k] = temp;
			}
		}
	}
}
