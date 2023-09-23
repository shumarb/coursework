// CS1010 Programming Methodology
// Problem Set 3 Exercise #21: min_max.c
//
// This program reports the minimum and
// maximum elements in a given matrix.
//
// SHEIKH UMAR

#include <math.h>
#include <stdio.h>
#define NCOLS 10
#define NROWS 10

void get_min_max(int [NROWS][NCOLS], int, int, int *, int *);

int main(void) {
	int mtx[NROWS][NCOLS];
	int col, i, j, max, min, row;

	printf("Enter the size of the matrix: ");
	scanf("%d %d", &row, &col);
	printf("Enter elements row by row:\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <col; j++)
		{
			scanf("%d", &mtx[i][j]);
		}
	}

	get_min_max(mtx, row, col, &min, &max);

	printf("Min = %d\n", min);
	printf("Max = %d\n", max);

	return 0;
}

// Return maximum and minimum elements through two pointers
void get_min_max(int mtx[][NCOLS], int num_rows, int num_cols, int *min_p, int *max_p)
{
	int i, j;
	*min_p = *max_p = mtx[0][0];

	for (i = 0; i < num_rows; i++)
	{
		for (j = 0; j < num_cols; j++)
		{
			if (mtx[i][j] > *max_p)
			{
				*max_p = mtx[i][j];
			}
		}
	}

	for (i = 0; i < num_rows; i++)
	{
		for (j = 0; j < num_cols; j++)
		{
			if (mtx[i][j] < *min_p)
			{
				*min_p = mtx[i][j];
			}
		}
	}
}
