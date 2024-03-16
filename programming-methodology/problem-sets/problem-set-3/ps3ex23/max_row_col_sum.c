// CS1010 Programming Methodology
// Problem Set 3 Exercise #23: max_row_col_sums.c
//
// This program prints out the maximum row sum
// and column sum in a given matrix.
//
// SHEIKH UMAR

#include <math.h>
#include <stdio.h> 
#define NCOLS 10
#define NROWS 10

int get_max_col_sum(int mtx[NROWS][NCOLS], int num_rows, int num_cols);
int get_max_row_sum(int mtx[NROWS][NCOLS], int num_rows, int num_cols);
void read_matrix(int mtx[NROWS][NCOLS], int *rows_p, int *cols_p);

// complete and given
int main(void)
{
	int mtx[NROWS][NCOLS], num_rows, num_cols;
	int max_row_sum, max_col_sum;

	read_matrix(mtx, &num_rows, &num_cols);

	max_row_sum = get_max_row_sum(mtx, num_rows, num_cols);
	max_col_sum = get_max_col_sum(mtx, num_rows, num_cols);
	printf("Max row sum = %d\n", max_row_sum);
	printf("Max col sum = %d\n", max_col_sum);

	return 0;
}

// Read values into the matrix
// Return the number of rows and columns through pointers
void read_matrix(int mtx[][NCOLS], int *rows_p, int *cols_p)
{
	int i, j;

	printf("Enter the size of the matrix: ");
	scanf("%d %d", rows_p, cols_p);

	printf("Enter elements row by row:\n");
	for (i = 0; i < *rows_p; i++)
	{
		for (j = 0; j < *cols_p; j++)
		{
			scanf("%d", &mtx[i][j]);
		}
	}
}

// Return maximum row sum
int get_max_row_sum(int mtx[NROWS][NCOLS], int num_rows, int num_cols)
{
	int i, is_test = 0, j, max_row = 0, sum_row = 0;

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < num_cols; j++)
		{
			max_row += mtx[i][j];
		}
	}

	if (is_test) {
		printf("\n * matrix: ");
		for (i = 0; i < num_rows; i++)
		{
			for (j = 0; j < num_cols; j++)
			{
				printf("%d ", mtx[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	

	for (i = 1; i < num_rows; i++)
	{
		sum_row = 0;
		for (j = 0; j < num_cols; j++){

			sum_row += mtx[i][j];
		}
		if (sum_row > max_row)
		{
			max_row = sum_row;
		}
	}

	return max_row;
}

// Return maximum column sum
int get_max_col_sum(int mtx[NROWS][NCOLS], int num_rows, int num_cols)
{
	int i, is_test = 0, j, max_col = 0, sum_col;
	int new_rows = num_cols, new_cols = num_rows;
	int new_mtx[new_rows][new_cols];

	for (i = 0; i < new_rows; i++)
	{
		for (j = 0; j < new_cols; j++)
		{
			new_mtx[i][j] = mtx[j][i];
		}
	}
	
	if (is_test) {
		printf("\n * matrix: ");
		for (i = 0; i < num_rows; i++)
		{
			for (j = 0; j < num_cols; j++)
			{
				printf("%d ", new_mtx[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < new_cols; j++)
		{
			max_col += new_mtx[i][j];
		}
	}

	for (i = 1; i < new_rows; i++)
	{
		sum_col = 0;
		for (j = 0;j < new_cols; j++)
		{
			sum_col += new_mtx[i][j];
		}
		if (sum_col > max_col)
		{
			max_col = sum_col;
		}
	}

	return max_col;
}
