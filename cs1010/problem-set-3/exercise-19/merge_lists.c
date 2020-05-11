// CS1010 Programming Methodology
// Problem Set 3 Exercise #19: merge_lists.c
//
// This program merges two sorted lists
// into one sorted list
//
// SHEIKH UMAR A0149874L

#include <stdio.h>
#define MAX_SIZE 50

void merge_lists(int list1[], int size1, int list2[], int size2, int list3[]);
void print_list(int list[], int size);
void read_list(int list[], int size);

// complete and given
int main(void)
{
	// three lists
	int list_1[MAX_SIZE], list_2[MAX_SIZE], list_3[MAX_SIZE * 2], size_1, size_2;

	printf("Number of elements in list1: ");
	scanf("%d", &size_1);
	read_list(list_1, size_1);

	printf("Number of elements in list2: ");
	scanf("%d", &size_2);
	read_list(list_2, size_2);

	merge_lists(list_1, size_1, list_2, size_2, list_3);
	print_list(list_3, (size_1 + size_2)); 

	return 0;
}

// Read values from file into arr
void read_list(int list[], int size)
{
	int i;

	printf("Enter %d elements: ", size);
	for(i = 0; i < size; i++)
	{
		scanf("%d",&list[i]);
	}
}

// Merge arrays list1 and list2 into list3
// in ascending order
void merge_lists(int list_1[], int size_1, int list_2[], int size_2, int list_3[])
{
	// size of combined elements = sum of sizes of both elements	
	int i, j = 0, size_3 = (size_1 + size_2);
	int k, min_index, temp;

	for(i = 0; i < size_1; i++)
	{
		list_3[i] = list_1[i];
	}

	for(i = size_1; i < size_3; i++)
	{
		list_3[i] = list_2[j];
		j++;
	}

	// List 3 is formed. Now sort it.
	for(i = 0; i < size_3 - 1; i++)
	{
		min_index = i;
		for(k = i + 1; k < size_3; k++)
		{
			if(list_3[k] < list_3[i])
			{
				min_index = k;
				temp = list_3[i];
				list_3[i] = list_3[k];
				list_3[min_index] = temp;
			}
		}
	}
}

// Print values of a list
void print_list(int list[], int size)
{
	int k;

	printf("Merged list: [");
	for(k = 0; k < size - 1; k++)
	{
		printf("%d, ",list[k]);
	}
	printf("%d]\n", list[size - 1]);
}

