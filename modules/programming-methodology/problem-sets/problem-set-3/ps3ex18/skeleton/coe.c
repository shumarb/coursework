// CS1010 Programming Methodology
// Problem Set 3 Exercise #18: coe.c
//
// This program calculates COE final price for a month.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 5000

void print_bids(int bids[], int size);
void sort(int bids[], int size);
int compute_coe(int bids[], int size, int num);

// main is complete and given
int main(void) {

	int i, num_coe, bids[MAX], num_bids, coe_val;

	printf("Enter the number of available COEs: ");
	scanf("%d", &num_coe);

	printf("Enter the number of bids: ");
	scanf("%d", &num_bids);

	printf("Enter %d bids: ", num_bids);
	for (i = 0; i < num_bids; i++) {
		scanf("%d", &bids[i]);
	}

	sort(bids, num_bids);

	// for debugging
	//print_bids(bids, num_bids);

	coe_val = compute_coe(bids, num_bids, num_coe);

	printf("COE final price this month is $%d\n", coe_val);

	return 0;
}

// Print out the bids
// Complete and given
void print_bids(int bids[], int size) {

	int i;

	for (i = 0; i < size; i++) {
		printf("%d ", bids[i]);
	}
	printf("\n");
}

// Sort bids in descending order
void sort(int bids[], int size) {

	// stub
}

// Return the final COE value
int compute_coe(int bids[], int num_bids, int num_coe) {

	return 0; // stub
}
