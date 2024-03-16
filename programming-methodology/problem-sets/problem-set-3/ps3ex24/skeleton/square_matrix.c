// CS1010 Programming Methodology
// Problem Set 3 Exercise #24: square_matrix.c
//
// This program checks if a square matrix is 
// a diagonal matrix or an upper-triangular matrix.
//
// <Replace this with your name>

#include <stdio.h>
#define N 10

int scan_matrix(int matrix[N][N]);
int is_diagonal(int matrix[N][N], int size);
int is_upper_triangular(int matrix[N][N], int size);
void print_matrix(int matrix[N][N], int size);

// main is complete and given
int main(void) {

	int matrix[N][N]; 
	int size;

	size = scan_matrix(matrix);

	if ( is_diagonal(matrix, size) ) {
		printf("Given matrix is a diagonal matrix.\n");
	} else {
		printf("Given matrix is not a diagonal matrix.\n");
	}

	if ( is_upper_triangular(matrix, size) ) {
		printf("Given matrix is an upper triangular matrix.\n");
	} else {
		printf("Given matrix is not an upper triangular matrix.\n");
	}

	return 0;
}

// Read values into mtx
// Return the size of square matrix
int scan_matrix(int mtx[N][N]) {

	printf("Enter the size of the square matrix: ");

	printf("Enter elements row by row:\n");

	return 0; // stub
}

// Return 1 if mtx is diagonal matrix,
// otherwise return 0.
int is_diagonal(int mtx[N][N], int size) {

	return 0; // stub
}

// Return 1 if mtx is upper-triangular matrix,
// otherwise return 0.
int is_upper_triangular(int mtx[N][N], int size) {

	return 0; // stub
}

// Print values of mtx
// not required in output - use it for debugging purpose
void print_matrix(int mtx[N][N], int size) {

	int row, col;

	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) { 
			printf("%d\t", mtx[row][col]);
		}
		printf("\n");
	}
}
