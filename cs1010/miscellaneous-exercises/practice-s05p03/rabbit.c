/**
 * rabbit.c 
 * A rabbit can jump at most 50 centimetres. It needs to cross a
 * river, with rocks positioned in a straight line in the river.
 * The program computes the minimum number of jumps for the rabbit
 * to cross to the other side of the river.
 * 
 * SHEIKH UMAR
 */

#include <stdio.h>

int countJumps(int [], int);
void displaysArray(int [], int);
void displayLine();

int main(void) 
{
	int i, num_jumps, num_rocks;            // including opposite bank

	printf("Enter number of rocks: ");
	scanf("%d", &num_rocks);

	int rocks_array[num_rocks];
	for (i = 0; i < num_rocks; i++)
	{
		scanf("%d", &rocks_array[i]); 
	}

	num_jumps = countJumps(rocks_array, num_rocks);
	printf("%d\n", num_jumps);

	return 0;
}

// Counts the minimum number of jumps the rabbit needs
// to take to get to the other side of the river.
// Precond: size > 0
int countJumps(int rocks[], int size) 
{
	int current_rock, current_rock_index = 0, is_test = 0, num_jumps = 0, rocks_array_size = size + 1;
	int rocks_array[rocks_array_size];
	
	// Create a new array where the first index is 0
	// This is a clearer representatation of rabbit jumping from the river bank to the opposite river bank,
	// where the first element represents the river bank, and last element represents the river bank.
	rocks_array[0] = 0;
	for (int i = 1; i < rocks_array_size; i++) {
		rocks_array[i] = rocks[i - 1];
	}

	if (is_test)
	{
		printf("* rocks_array: ");
		displaysArray(rocks_array, rocks_array_size);
		displayLine();
	}

	current_rock = rocks_array[current_rock_index];
	while (1)
	{
		// 1. Break if rabbit is now at opposite river bank
		if (current_rock == rocks_array[rocks_array_size - 1])
		{
			if (is_test)
			{
				printf("* rocks_array: ");
				displaysArray(rocks_array, rocks_array_size);
				printf("* now at index %d, which is at opposite river bank\n", current_rock_index);
				displayLine();
			}
			break;
		} 
		else
		{
			// 2. Rabbit not at opposite river bank,
			// check if it is possible to jump to next rock
			// If impossible, return -1
			current_rock = rocks_array[current_rock_index];
			int next_rock = rocks_array[current_rock_index + 1];
			if ((next_rock - current_rock) > 50)
			{
				if (is_test)
				{
					printf("* rocks_array: ");
					displaysArray(rocks_array, rocks_array_size);
					printf("* impossible: current_rock: %d | next_rock: %d | difference: %d\n", current_rock, next_rock, (next_rock - current_rock));
					displayLine();
				}
				return -1;
			}
			else 
			{
				// 3. Rabbit not at opposite river bank
				// and rabbit can jump to next rock as it's <= 50 metres
				// check if rabbit can jump to opposite river bank
				// if yes, increase num_jumps by 1, and break
				int opposite_river_bank = rocks_array[rocks_array_size - 1];
				current_rock = rocks_array[current_rock_index];
				if ((opposite_river_bank - current_rock) <= 50)
				{
					if (is_test)
					{
						printf("* rocks_array: ");
						displaysArray(rocks_array, rocks_array_size);
						printf("* jump to opposite_river_bank | current_rock: %d, opposite_river_bank: %d\n", current_rock, opposite_river_bank);
						displayLine();
					}
					num_jumps++;
					break;
				}
				else
				{
					// 4. Rabbit not at opposite river bank,
					// rabbit can't jump to opposite river bank from current rock,
					// and rabbit can jump to rock next to current rock
					// so find furthest rock that rabbit can jump to
					// next rock range:[2nd rock, 2nd-last rock]
					// and rock after next rock:[3rd rock, last rock]
					for (int j = current_rock_index; j < rocks_array_size - 1; j++)
					{
						int next_rock = rocks_array[j];
						int rock_after_next_rock = rocks_array[j + 1];
						if (is_test)
						{
							printf("* so far, current_rock: %d, next_rock: %d, rock_after_next_rock: %d\n", current_rock, next_rock, rock_after_next_rock);
						}
						if ((next_rock - current_rock) <= 50 && (rock_after_next_rock - current_rock) > 50)
						{	
							if (is_test)
							{
								printf("* rocks_array: ");
								displaysArray(rocks_array, rocks_array_size);
								printf("* current_rock: %d, next_rock: %d, rock_after_next_rock: %d\n", current_rock, next_rock, rock_after_next_rock);
								printf("* currently at %d, jump to %d\n", current_rock, next_rock);
								displayLine();
							}
							current_rock_index = j;
							current_rock = next_rock;
							num_jumps++;
							break;
						}
					}
				}
			}
		}
	}

	return num_jumps;
}

// Displays array
void displaysArray(int rocks_array[], int size) 
{
	printf("[");
	for (int i = 0; i < size - 1; i++) 
	{
		printf("%d ", rocks_array[i]);
	}
	printf("%d]\n", rocks_array[size - 1]);
}

void displayLine()
{
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
