// CS1010 Programming Methodology
// Problem Set 2 Exercise #21: tray.c
//
// Program reads in 2 dimensions, calculates total perimeter obtained
// by folding tray at a certain position three times,
// and prints out the least perimeter obtained out of the 3 foldings.

#include <math.h>
#include <stdio.h>

int main(void) {

	double new_length, new_width, answer;
	double perimeter_1, perimeter_2, perimeter_3, perimeter_4;

	printf("Enter size of tray: ");
	scanf("%lf %lf", &new_length, &new_width);

	if(new_length > new_width)
	{
		double temp = new_width;
		new_width = new_length;
		new_length = temp;
	}

	perimeter_1 = (2.0 * (new_length + new_width));
	// printf("%.2lf\n",perimeter_1);

	new_width /= 2.0;
	if(new_length <new_width)
	{
		double temp = new_width;
		new_width = new_length;
		new_length = temp;
	}
	perimeter_2 = (2.0 * (new_length + new_width));
	// printf("%.2lf\n",perimeter_2);

	new_length /= 2.0;
	if(new_length > new_width)
	{
		double temp = new_length;
		new_length = new_width;
		new_width = temp;
	}
	perimeter_3 = (2.0 * (new_length + new_width));
	// printf("%.2lf\n",perimeter_3);

	new_width /= 2.0;
	if(new_length < new_width)
	{
		double temp = new_width;
		new_width = new_length;
		new_length = temp;
	}
	perimeter_4 = (2.0 *(new_length + new_width));
	// printf("%.2lf\n",perimeter_4);

	// Compare all perimeters, print smallest value
	if((perimeter_1 < perimeter_2) && (perimeter_1 < perimeter_3) && (perimeter_1 < perimeter_4))
	{
		answer = perimeter_1;
	}
	else if((perimeter_2 < perimeter_1) && (perimeter_2 < perimeter_3) && (perimeter_2 < perimeter_4))
	{
		answer = perimeter_2;
	}
	else if((perimeter_3 < perimeter_1) && (perimeter_3 < perimeter_2) && (perimeter_3 < perimeter_4))
	{
		answer = perimeter_3;
	}
	else
	{
		answer = perimeter_4;
	}

	printf("Minimum perimeter after folding = %.2lf\n", answer);

	return 0;
}

