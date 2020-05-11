// CS1010 Programming Methodology
// Problem Set 3 Exercise #22: normalization.c
//
// This program normalizes array slots
// according to given formula.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>
#include <math.h>
#define NROWS 10
#define NCOLS 10

void get_min_max(double mtx[NROWS][NCOLS], int num_rows, int num_cols, double *min_p, double *max_p);
void normalize_matrix(double mtx[NROWS][NCOLS], int num_rows, int num_cols);
void print_matrix(double mtx[NROWS][NCOLS], int num_rows, int num_cols);
void read_matrix(double mtx[NROWS][NCOLS], int *rows_p, int *cols_p);

// main is complete and given
int main(void)
{
	double mtx[NROWS][NCOLS];
	int num_rows, num_cols;

	read_matrix(mtx, &num_rows, &num_cols);
	normalize_matrix(mtx, num_rows, num_cols);
	print_matrix(mtx, num_rows, num_cols);
	
	return 0;
}

// Read values into the matrix
// Return size through two pointers
void read_matrix(double mtx[NROWS][NCOLS], int *rows_p, int *cols_p) {
	int j, k;

	printf("Enter the size of the matrix: ");
	scanf("%d %d", rows_p, cols_p);

	printf("Enter elements row by row:\n");
	for(j = 0; j < *rows_p; j++)
	{
		for(k = 0; k < *cols_p; k++)
		{
			scanf("%lf", &mtx[j][k]);
		}
	}
}

// Normalize given matrix,
// assume that not all elements have the same value
void normalize_matrix(double mtx[NROWS][NCOLS], int num_rows, int num_cols)
{
	double min, max;
	int j, k;
	get_min_max(mtx, num_rows, num_cols, &min, &max);

	for(j = 0; j < num_rows; j++)
	{
		for(k = 0; k < num_cols; k++)
		{
			mtx[j][k] = ((mtx[j][k] - min) / (max - min));
		}
	}
}

// Return maximum and minimum elements through two pointers
void get_min_max(double mtx[NROWS][NCOLS], int num_rows, int num_cols, double *min_p, double *max_p)
{
	int j, k;
	*min_p = *max_p = mtx[0][0];

	for(j = 0; j < num_rows; j++)
	{
		for(k = 0; k < num_cols; k++)
		{
			*min_p = fmin(*min_p, mtx[j][k]);
			*max_p = fmax(*max_p, mtx[j][k]);
		}
	}
}

// Print out a matrix
// complete and given
void print_matrix(double arr[NROWS][NCOLS], int num_rows, int num_cols)
{
	int i, j;

	printf("Normalized matrix:\n");
	for (i = 0; i < num_rows; i++)
	{
		for (j = 0; j < num_cols; j++)
		{
			printf("%.2lf ", arr[i][j]);
		}
		printf("\n");
	}
}

