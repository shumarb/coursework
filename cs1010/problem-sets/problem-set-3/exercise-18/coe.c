// CS1010 Programming Methodology
// Problem Set 3 Exercise #18: coe.c
//
// This program calculates COE final price for a month.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>
#define MAX 5000

int compute_coe(int bids[], int size, int num);
void print_bids(int bids[], int size);
void sort(int bids[], int size);

// main is complete and given
int main(void)
{
	int bids[MAX], coe_val, i, num_bids, num_coe;

	printf("Enter the number of available COEs: ");
	scanf("%d", &num_coe);

	printf("Enter the number of bids: ");
	scanf("%d", &num_bids);

	printf("Enter %d bids: ", num_bids);
	for (i = 0; i < num_bids; i++)
	{
		scanf("%d", &bids[i]);
	}

	sort(bids, num_bids);

	// for debugging
	// print_bids(bids, num_bids);

	coe_val = compute_coe(bids, num_bids, num_coe);

	printf("COE final price this month is $%d\n", coe_val);

	return 0;
}

// Print out the bids
// Complete and given
void print_bids(int bids[], int size) 
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", bids[i]);
	}
	printf("\n");
}

// Sort bids in descending order
void sort(int bids[], int size)
{
	int j, k, temp;

	for(j = 0; j < size-1; j++)
	{
		for(k = j + 1; k < size; k++)
		{
			if(bids[j] > bids[k])
			{
				temp = bids[k];
				bids[k] = bids[j];
				bids[j] = temp;
			}
		}
	}
}

// Return the final COE value
int compute_coe(int bids[], int num_bids, int num_coe)
{
	int counter = 0, done = 0, index, j;
	
	if(num_coe > num_bids)
	{
		index = 0;
	}
	else
	{
		index = num_bids - num_coe;
	}
	int coe_price = bids[index];

	for(j = 0; j < num_bids; j++)
	{
		if(bids[j] >= coe_price)
		{
			counter++;
		}
	}

	if(counter > num_coe)
	{
		int duplicate = 0;

		for(j = index + 1; j < num_bids - 1 && done == 0; j++)
		{
			if(bids[j] > bids[j - 1] && bids[j] < bids[j + 1])
			{
				coe_price = bids[j];
				done = 1;
			}
		}
		for(j = index; j < num_bids - 1; j++)
		{
			if(bids[j] == bids[j + 1])
			{
				duplicate = 1;
			}
		}
		if(duplicate == 1)
		{
			coe_price = bids[num_bids - 1];
		}
	}

	return coe_price;
}

