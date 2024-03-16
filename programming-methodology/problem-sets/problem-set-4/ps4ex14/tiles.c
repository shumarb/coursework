// CS1010 Programming Methodology
// Problem Set 4 Exercise #14: tiles.c
//
// This program computes the difference
// in cost between the cheapest tile
// and the most expensive tile.
//
// SHEIKH UMAR

#include <math.h>
#include <stdio.h>
#define MAX_NUM 20  // max number of tiles

typedef struct {
	int length, width;
	double price;
} tile_t;

int scan_tiles(tile_t []);
double difference(tile_t [], int);

int main(void)
{
	int numTiles;  // actual number of tiles read in
	tile_t tiles[MAX_NUM];
	numTiles = scan_tiles(tiles);
	printf("Largest difference = $%.2f\n", difference(tiles, numTiles));
	return 0;
}

// Read tiles' data into array tiles
// returns the number of tiles read 
int scan_tiles(tile_t tiles[])
{
	int i,numTiles;
	printf("Enter the number of tiles: ");
	scanf("%d", &numTiles);
	
	printf("Enter data for %d tiles:\n", numTiles);	
	for (i = 0; i < numTiles; i++)
	{
		scanf("%d %d %lf", &tiles[i].length, &tiles[i].width, &tiles[i].price);
	}

	return numTiles;
}

// Return the difference in cost between cheapest
// tile and most expensive tile in the array tiles
double difference(tile_t tiles[], int numTiles)
{
	double min, max, price;
	int i;

	min = max = (tiles[0].length) * (tiles[0].width) * (tiles[0].price);
	for (i = 1; i < numTiles; i++)
	{
		price = (tiles[i].length) * (tiles[i].width) * (tiles[i].price);
		min = fmin(min, price);// Find smallest price obtained
		max = fmax(max, price); // Find largest price obtained
	}

	return (max - min); // Return largest difference with largest and smallest prices
}
