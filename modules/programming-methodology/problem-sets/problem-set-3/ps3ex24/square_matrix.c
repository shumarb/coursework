// CS1010 Programming Methodology
// Problem Set 3 Exercise #24: square_matrix.c
//
// This program checks if a square matrix is 
// a diagonal matrix or an upper-triangular matrix.
//
// SHEIKH UMAR

#include <stdio.h>
#define N 10

int is_diagonal(int matrix[N][N], int size);
int is_upper_triangular(int matrix[N][N], int size);
int scan_matrix(int matrix[N][N]);

// main is complete and given
int main(void)
{
	int matrix[N][N]; 
	int size;

	size = scan_matrix(matrix);

	if (is_diagonal(matrix, size))
	{
		printf("Given matrix is a diagonal matrix.\n");
	}
	else
	{
		printf("Given matrix is not a diagonal matrix.\n");
	}

	if (is_upper_triangular(matrix, size))
	{
		printf("Given matrix is an upper triangular matrix.\n");
	}
	else
	{
		printf("Given matrix is not an upper triangular matrix.\n");
	}

	return 0;
}

// Read values into mtx
// Return the size of square matrix
int scan_matrix(int mtx[N][N])
{
	int i, j, size;
	
	printf("Enter the size of the square matrix: ");
	scanf("%d", &size);

	printf("Enter elements row by row:\n");
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			scanf("%d", &mtx[i][j]);
		}
	}
	return size;
}

// Return 1 if mtx is diagonal matrix,
// otherwise return 0.
int is_diagonal(int mtx[N][N], int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i != j && mtx[i][j] != 0)
			{
				return 0;
			}
		}
	}

	return 1;
}

// Return 1 if mtx is upper-triangular matrix,
// otherwise return 0.
int is_upper_triangular(int mtx[N][N], int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i > j && mtx[i][j] != 0)
			{
				return 0;
			}
		}
	}

	return 1;
}
