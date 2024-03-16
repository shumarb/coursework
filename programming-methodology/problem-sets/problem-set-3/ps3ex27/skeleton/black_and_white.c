// CS1010 Programming Methodology
// Problem Set 3 Exercise #27: black_and_white.c
//
// This program flips or rotates a square matrix.
//
// <Replace this with your name>

#include <stdio.h>
#define N 10 

int read_img(int img[N][N]);
void flip(int img[N][N], int size);
void rotate(int img[N][N], int size);
void print_img(int img[N][N], int size);

int main(void) {

	printf("Enter choice:\n(1) flip\n(2) rotate\n");

	printf("Original image:\n");
	printf("Flipped image:\n");
	printf("Rotated image:\n");

	return 0;
}

// Read in a black-and-white image, return its size
int read_img(int img[N][N]) {

	printf("Enter the size of image: ");

	printf("Enter image:\n");

	return 0;  // stub
}

// Flip the img upside down
void flip(int img[N][N], int size) {

	// stub 

}

// Rotate the img 90 degree clockwise
void rotate(int img[N][N], int size) {

	// stub 

}

// Print out a binary img
// Complete and given
void print_img(int img[N][N], int size) {

	int row, col;
	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) {
			printf("%d ", img[row][col]);
		}
		putchar('\n');
	}
}
