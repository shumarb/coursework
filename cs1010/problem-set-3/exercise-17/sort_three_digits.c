// CS1010 Programming Methodology
// Problem Set 3 Exercise #17: sort_three_digits.c
//
// This program sorts a list of integers
// in ascending order of their first 3 digits.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>
#define SIZE 100 

void sort_array(int arr[], int size);
int is_less_than(int num1, int num2);

// main is complete and given
int main(void)
{
	int i, num, val[SIZE];

	printf("Enter the number of elements: ");
	scanf("%d", &num);

	printf("Enter %d elements: ", num);
	for (i = 0; i < num; i++)
	{
		scanf("%d", &val[i]);
	}

	sort_array(val, num);

	printf("Sorted array: [");
	for (i = 0; i < num - 1; i++)
	{
		printf("%d, ", val[i]);
	}
	printf("%d]\n", val[num - 1]);

	return 0;
}

// Original selection sort, need to be modified
// to sort integers according to the first 3 digits
void sort_array(int arr[], int size)
{
	int j, k, l, temp;

	for(l = 0; l < size - 1; l++)
	{
		for(j = l + 1; j < size; j++)
		{
			if(arr[j] > arr[l])
			{
				temp = arr[l];
				arr[l] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for(j = 0; j < size - 1; j++)
	{
		for(k = j + 1; k < size; k++)
		{
			if(is_less_than(arr[j], arr[k]))
			{
				temp = arr[k];
				arr[k] = arr[j];
				arr[j] = temp;
			}
		}		
	}
}

// Compare integers according to first 3 digits,
// return 1 if first argument is smaller, 0 otherwise
int is_less_than(int num1, int num2)
{
	while(num1 >= 1000)
	{
		num1 /= 10;
	}
	while(num2 >= 1000)
	{
		num2 /= 10;
	}

	return (num1 > num2);
}

