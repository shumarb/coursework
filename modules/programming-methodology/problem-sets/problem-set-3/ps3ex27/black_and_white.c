// CS1010 Programming Methodology
// Problem Set 3 Exercise #27: black_and_white.c
//
// This program flips or rotates a square matrix.
//
// SHEIKH UMAR

#include <stdio.h>
#define N 10 

int read_img(int img[N][N]);
void flip(int img[N][N], int size);
void print_img(int img[N][N], int size);
void rotate(int img[N][N], int size);

int main(void)
{
	int img[N][N];
	int size, choice;
	size = read_img(img);

	printf("Enter choice:\n(1) flip\n(2) rotate\n");
	scanf("%d", &choice);

	printf("Original image:\n");
	print_img(img, size);

	if (choice == 1)
	{
		printf("Flipped image:\n");
		flip(img, size);
		print_img(img, size);
	}
	else
	{
		printf("Rotated image:\n");
		rotate(img, size);
		print_img(img, size);
	}

	return 0;
}

// Read in a black-and-white image, return its size
int read_img(int img[N][N])
{
	int j, k, size;
	printf("Enter the size of image: ");
	scanf("%d", &size);

	printf("Enter image:\n");
	for (j = 0; j < size; j++)
	{
		for (k = 0; k < size; k++)
		{
			scanf("%d", &img[j][k]);
		}
	}

	return size;
}

// Flip the img upside down
void flip(int img[N][N], int size)
{
	int j, temp, start = 0, end = size - 1;
	while(end > start)
	{
		for (j = 0; j < size; j++)
		{
			temp = img[start][j];
			img[start][j] = img[end][j];
			img[end][j] = temp;
		}
		start++;
		end--;
	}
}

// Rotate the img 90 degree clockwise
void rotate(int img[N][N], int size)
{
	int row, col, swap;

	// First, flip matrix
	flip(img,size);

	// Then, flip according to main diagonal
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < row; col++)
		{
			swap = img[row][col];
			img[row][col] = img[col][row];
			img[col][row] = swap;
		}
	}
}

// Print out a binary img
// Complete and given
void print_img(int img[N][N], int size)
{
	int row, col;
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			printf("%d ", img[row][col]);
		}
		putchar('\n');
	}
}
