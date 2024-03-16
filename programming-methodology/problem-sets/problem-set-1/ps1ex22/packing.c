// CS1010 Programming Methodology
// Problem Set 1 Exercise #22: packing.c
//
// Program reads in lengths and widths of slab and tray, then
// calculates the minimum unused area for vertical and horizontal arrangements
// of slabs in tray, and prints out the smaller value
//
// SHEIKH UMAR

#include <stdio.h>

int horizontal(int, int, int, int);
int vertical(int, int, int, int);

int main(void)
{
	int slab_length, slab_width;
	int tray_length, tray_width;
	int vertical_arrangement_area, horizontal_arrangement_area;

	printf("Enter size of tray: ");
	scanf("%d %d", &tray_length, &tray_width);

	printf("Enter size of slab: ");
	scanf("%d %d", &slab_length, &slab_width);

	horizontal_arrangement_area = horizontal(tray_length, tray_width, slab_length, slab_width);
	vertical_arrangement_area = vertical(tray_length, tray_width, slab_length, slab_width);

	if (vertical_arrangement_area < horizontal_arrangement_area)
	{
		printf("Minimum unused area = %d\n", vertical_arrangement_area);
	}
	else
	{
		printf("Minimum unused area = %d\n", horizontal_arrangement_area);
	}

	return 0;
}

int vertical(int tray_l, int tray_w, int slab_l, int slab_w)
{
	int tray_area = (tray_l * tray_w);
	int slab_area = (slab_l * slab_w);

	int number_column = (tray_w / slab_w);
	int number_row = (tray_l / slab_l);

	int used_area = (slab_area * number_column * number_row);

	return (tray_area - used_area);
}

int horizontal(int tray_l, int tray_w, int slab_l, int slab_w)
{
	int tray_area = (tray_l * tray_w);
	int slab_area = (slab_l * slab_w);

	int number_column = (tray_l / slab_w);
	int number_row = (tray_w / slab_l);

	int used_area = (slab_area * number_column * number_row);
	
	return (tray_area - used_area);
}
