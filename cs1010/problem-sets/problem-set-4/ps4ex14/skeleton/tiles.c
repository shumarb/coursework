// CS1010 Programming Methodology
// Problem Set 4 Exercise #14: tiles.c
//
// This program computes the difference
// in cost between the cheapest tile
// and the most expensive tile.
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>

#define MAX_NUM 20  // max number of tiles

typedef struct {
	// write the members


} tile_t;

int scan_tiles(tile_t tiles[]);
double difference(tile_t tiles[], int numTiles);

int main(void) {

	int numTiles;  // actual number of tiles read in

	tile_t tiles[MAX_NUM];

	numTiles = scan_tiles(tiles);

	printf("Largest difference = $%.2f\n", difference(tiles, numTiles));

	return 0;
}


// Read tiles' data into array tiles
// returns the number of tiles read 
int scan_tiles(tile_t tiles[]) {

	printf("Enter the number of tiles: ");

	printf("Enter data for  tiles:\n");

	return 0;  // stub
}


// Return the difference in cost between cheapest
// tile and most expensive tile in the array tiles
double difference(tile_t tiles[], int numTiles) {

	return 0;  // stub
}
