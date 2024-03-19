// CS1010 Programming Methodology
// Problem Set 3 Exercise #25: matrix_diagonal.c
//
// This program reads a matrix
// and checks for descending diagonal
// matrix and anti-diagonal matrix.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 10

int read_matrix(int matrix[MAX][MAX]);
int is_desc_diagonal(int matrix[MAX][MAX], int size);
int is_anti_diagonal(int matrix[MAX][MAX], int size);

int main(void) {

	int size, matrix[MAX][MAX];

	size = read_matrix(matrix);

	if ( is_desc_diagonal(matrix, size) ) {
		printf("Given matrix is a descending diagonal matrix.\n");
	} else {
		printf("Given matrix is not a descending diagonal matrix.\n");
	}

	if ( is_anti_diagonal(matrix, size) ) {
		printf("Given matrix is an anti-diagonal matrix.\n");
	} else {
		printf("Given matrix is not an anti-diagonal matrix.\n");
	}

	return 0;
}

// Read data into matrix, return size
int read_matrix(int matrix[MAX][MAX]) {

	printf("Enter the size of square matrix: ");

	printf("Enter values:\n");

	return 0; // stub
}

// Check if diagonal values are in decreasing
// consecutive numbers and all the non-diagonal
// values are 0. Return 1 if so, 0 otherwise
int is_desc_diagonal(int matrix[MAX][MAX], int size) {

	return 0;  // stub
}

// Check if all the values are zeroes except those
// on the anti-diagonal. Return 1 if so, 0 otherwise
int is_anti_diagonal(int matrix[MAX][MAX], int size) {

	return 0;  // stub
}
