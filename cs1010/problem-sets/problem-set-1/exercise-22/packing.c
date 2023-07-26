// CS1010 Programming Methodology
// Problem Set 1 Exercise #22: packing.c
//
// Program reads in lengths and widths of slab and tray, then
// calculates the minimum unused area for vertical and horizontal arrangements
// of slabs in tray, and prints out the smaller value

#include <stdio.h>

int vertical(int, int, int, int);
int horizontal(int, int, int, int);

int main(void)
{
	int tray_length, tray_width;
	int slab_length, slab_width;
	int answer1, answer2;

	printf("Enter size of tray: ");
	scanf("%d %d", &tray_length, &tray_width);

	printf("Enter size of slab: ");
	scanf("%d %d", &slab_length, &slab_width);
	
	// answer 1 is for vertical arrangement
	// answer 2 is for horizontal arrangement, must do swap
	answer1 = vertical(tray_length, tray_width, slab_length, slab_width);
	answer2 = horizontal(tray_length, tray_width, slab_length, slab_width);

	if(answer1 < answer2)
	{
		printf("Minimum unused area = %d\n",answer1);
	}
	else
	{
		printf("Minimum unused area = %d\n",answer2);
	}

	return 0;
}

int vertical(int tray_l, int tray_w, int slab_l, int slab_w)
{
	int tray_area = (tray_l * tray_w);
	int slab_area = (slab_l * slab_w);

	int col = (tray_w / slab_w);
	int row = (tray_l / slab_l);

	int used_area = (slab_area * col * row);
	return (tray_area - used_area);
}

int horizontal(int tray_l, int tray_w, int slab_l, int slab_w)
{
	int tray_area = (tray_l * tray_w);
	int slab_area = (slab_l * slab_w);

	int col = (tray_l / slab_w);
	int row = (tray_w / slab_l);

	int used_area = (slab_area * col * row);
	return (tray_area - used_area);
}

