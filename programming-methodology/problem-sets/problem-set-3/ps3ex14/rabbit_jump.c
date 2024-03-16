// CS1010 Programming Methodology
// Problem Set 3 Exercise #14: rabbit_jump.c
//
// A bunny can jump at most 50 centimetres.
// It needs to cross a river, with rocks
// positioned in a straight line in the river.
// This program computes the minimum number
// of jumps for the rabbit to cross to the
// other side of the river.
//
// SHEIKH UMAR

#include <stdio.h>
#define N 50 

int count_jumps(int [], int);

int main(void)
{
	int is_test = 0, j, number_of_jumps, size, rocks[N];

	printf("Enter the number of rocks: ");
	scanf("%d", &size);

	printf("Enter locations of %d rocks: ", size);
	for (j = 0; j < size; j++)
	{
		scanf("%d", &rocks[j]);
	}
	
	if (is_test) {
		printf("* You have entered: ");
		for (j = 0; j < size; j++)
		{
			printf("%d ", rocks[j]);
		}
		printf("\n");
	}
	
	number_of_jumps = count_jumps(rocks, size);
	if (number_of_jumps == 0)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("%d jumps\n", number_of_jumps);
	}
	
	return 0;
}

// Count the minimum number of jumps the rabbit needs
// to take to get to the other side of the river.
int count_jumps(int rocks[], int num_rocks)
{
	int count = 0, done = 0, index = 0, j, start = 0, stop = 0;

	// Keep checking for number of jumps
	// as long as done == 0 && rabbit does not start at the river bank (last element of array)
	while(start != rocks[num_rocks - 1] && done == 0)
	{
		// If the rock next to current rock is more than 50cm away,
		// impossible for rabbit to reach river bank.
		// Set count to zero, and done to 1 as no need to jump
		if ((rocks[index] - start) > 50)
		{
			count = 0;
			done = 1;
		}
		else
		{
			// Now, next rock is 50cm away from where rabbit is currently at
			// Check if rabbit can jump directly to river bank 
			// If can, increase number of jumps by 1, and set done to 1 as rabbit has reached river bank 
			// so no need to jump further
			if ((rocks[num_rocks - 1] - start) <= 50)
			{
				count++;
				done = 1;
			}

			// Rabbit can't jump directly to river bank,
			// so find the furthest rock that the rabbit can jump to
			// at every iteration
			else
			{
				for (j = index; j < (num_rocks - 1) && stop == 0; j++)
				{
					if (((rocks[j] - start) <= 50) && ((rocks[j + 1] - start) > 50))
					{
						count++; 			// Rabbit jumps to most-attainable rock
						start = rocks[j]; 	// Set rock that rabbit has jumped to as next starting point
						index = j + 1;		// Take note of index of rock that rabbit is unable to jump to for future checks
						stop = 1; 			// Get out of for loop
					}
				}
				stop = 0; // Reset stop to 0
			}
		}
	}

	return count;
}

