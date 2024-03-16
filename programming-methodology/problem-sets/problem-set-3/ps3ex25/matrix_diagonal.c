// CS1010 Programming Methodology
// Problem Set 3 Exercise #25: matrix_diagonal.c
//
// This program reads a matrix
// and checks for descending diagonal
// matrix and anti-diagonal matrix.
//
// SHEIKH UMAR

#include <stdio.h>
#define MAX 10

int is_anti_diagonal(int matrix[MAX][MAX], int size);
int is_desc_diagonal(int matrix[MAX][MAX], int size);
int read_matrix(int matrix[MAX][MAX]);

int main(void)
{
	int matrix[MAX][MAX], size;

	size = read_matrix(matrix);

	if (is_desc_diagonal(matrix, size))
	{
		printf("Given matrix is a descending diagonal matrix.\n");
	}
	else
	{
		printf("Given matrix is not a descending diagonal matrix.\n");
	}

	if (is_anti_diagonal(matrix, size))
	{
		printf("Given matrix is an anti-diagonal matrix.\n");
	}
	else
	{
		printf("Given matrix is not an anti-diagonal matrix.\n");
	}

	return 0;
}

// Read data into matrix, return size
int read_matrix(int matrix[MAX][MAX])
{
	int j, k, size;

	printf("Enter the size of square matrix: ");
	scanf("%d", &size);

	printf("Enter values:\n");
	for (j = 0; j < size; j++)
	{
		for (k = 0; k < size; k++)
		{
			scanf("%d", &matrix[j][k]);
		}
	}

	return size;
}

// Check if diagonal values are in decreasing
// consecutive numbers and all the non-diagonal
// values are 0. Return 1 if so, 0 otherwise
int is_desc_diagonal(int matrix[MAX][MAX], int size)
{
	int j, k;
 
	for (j = 0; j < size; j++)
	{
		for (k = 0; k < size; k++)
		{
			if (j != k && matrix[j][k] != 0)
			{
				return 0;
			}
		}
	}

	for (j = 0; j < size - 1; j++)
		{
			for (k = 0; k < size; k++)
			{
				if (j == k && ((matrix[j][k] - matrix[j + 1][k + 1]) != 1))
				{
					return 0;
				}
			}
		}

	return 1;
}

// Check if all the values are zeroes except those
// on the anti-diagonal. Return 1 if so, 0 otherwise
int is_anti_diagonal(int matrix[MAX][MAX], int size)
{
	int j, k;

	for (j = 0; j < size; j++)
	{
		for (k = 0; k < size; k++)
		{
			if (((j + k) != (size - 1)) && matrix[j][k] != 0)
			{
				return 0;
			}
		}
	}

	return 1; 
}
