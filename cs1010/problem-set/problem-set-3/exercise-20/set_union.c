// CS1010 Programming Methodology
// Problem Set 3 Exercise #20: union.c
//
// This program reads two sets of distinct integers
// and prints out the union of two sets.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>
#define MAX 10

int exist(int arr[], int size, int val);
int read_array(int set[], char *index);
int get_union(int setA[], int sizeA, int setB[], int sizeB);
void print_array(int set[], int size);
void sort_array(int set[], int size);

int main(void)
{
	int set_A[2 * MAX], set_B[MAX];  // two sets
	int size_A, size_B;

	size_A = read_array(set_A, "1st");
	size_B = read_array(set_B, "2nd");

	// update set_A to be union of set_A and set_B
	// return updated size of set_A
	size_A = get_union(set_A, size_A, set_B, size_B);

	// sort set_A in ascending order
	sort_array(set_A, size_A);
	
	print_array(set_A, size_A);

	return 0;
}

// Read elements of a set one by one
int read_array(int set[], char *index)
{
	int j, size;

	printf("Size of %s set? ", index);
	scanf("%d", &size);
	printf("\tEnter %d values: ", size);
	for(j = 0; j < size; j++)
	{
		scanf("%d", &set[j]);
	}
	return size;
}

// Update setA to be the union of setA and setB
int get_union(int set_A[], int size_A, int set_B[], int size_B)
{
	int i;
	for(i = 0; i < size_B; i++)
	{
		if(!exist(set_A, size_A, set_B[i]))
		{
			set_A[size_A] = set_B[i];
			size_A++;
		}
	}
	return size_A;
}

// Return 1 if val exists in arr, or 0 otherwise
int exist(int arr[], int size, int val)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(arr[i] == val)
		{
			return 1;
		}
	}
	return 0;
}

// Sort array in ascending order of elements
void sort_array(int set[], int size)
{
	int j, k, temp;
	for(j = 0; j < size - 1; j++)
	{
		for(k = j + 1; k < size; k++)
		{
			if(set[j] > set[k])
			{
				temp = set[k];
				set[k] = set[j];
				set[j] = temp;
			}
		}
	}
}

// Print elements of array
void print_array(int set[], int size)
{
	int i;

	printf("Union of two sets is (in ascending order):");
	for (i = 0; i < size; i++) {
			printf(" %d", set[i]);
	}
	printf("\n");
}

