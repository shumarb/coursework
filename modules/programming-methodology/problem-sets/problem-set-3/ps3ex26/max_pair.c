// CS1010 Programming Methodology
// Problem Set 3 Exercise #26: max_pair.c
//
// This program finds the pair of the same value
// that appears most frequently in a given matrix
// and reports its frequency.
//
// SHEIKH UMAR

#include <math.h>
#include <stdio.h>
#define NCOLS 4
#define NROWS 4

int check_row(int mtx[NROWS]);
int get_max_pairs(int mtx[NROWS][NCOLS]);

int main(void)
{
	int j, k, mtx[NROWS][NCOLS];

	printf("Enter values:\n");
	for (j = 0; j < NROWS; j++)
	{
		for (k = 0; k < NCOLS; k++)
		{
			scanf("%d", &mtx[j][k]);
		}
	}

	printf("Max number of pairs: %d\n", get_max_pairs(mtx));

	return 0;
}

// Return the maximum number of pairs of the
// same value within the same row or column
int get_max_pairs(int mtx[NROWS][NCOLS])
{
	int index, j, k, digits[10] = {0}, maximum_number_of_pairs = digits[0];

	// Search for consecutive elements with same value in each row.
	// Increase corresponding digit found by 1
	for (j = 0; j < NROWS; j++)
	{
		for (k = 0; k < NCOLS - 1; k++)
		{
			if (mtx[j][k] == mtx[j][k + 1])
			{
				index = mtx[j][k];
				digits[index]++;
			}
		}
	}

	// Search for consecutive elements with same value in each column.
	// Increase corresponding digit found by 1
	for (j = 0; j < NROWS; j++)
	{
		for (k = 0; k < NCOLS - 1; k++)
		{
			if (mtx[k][j] == mtx[k + 1][j])
			{
				index = mtx[k][j];
				digits[index]++;
			}
		}
	}

	for (j = 1; j < 10; j++)
	{
		maximum_number_of_pairs = fmax(maximum_number_of_pairs, digits[j]);
	}

	return maximum_number_of_pairs;
}
