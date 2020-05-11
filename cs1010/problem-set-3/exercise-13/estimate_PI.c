// CS1010 Programming Methodology
// Problem Set 3 Exercise #13: estimate_PI.c
//
// This program reads in a list of
// distinct integers and computes
// the estimate value for pi.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>
#include <math.h>
#define MAX 100

double estimate_PI(int list[], int size);
int gcd(int num1, int num2);

int main(void)
{
	int j, list[MAX], size;

	printf("Enter the size of the list: ");
	scanf("%d", &size);
	printf("Enter %d elements: ", size);
	for(j = 0; j < size; j++)
	{
		scanf("%d", &list[j]);
	}

	printf("Estimated pi = %.4lf\n", estimate_PI(list, size));

	return 0;
}

// Return the estimate value of PI
double estimate_PI(int list[], int size)
{
	double num_pairs = 0, num_gcd_pairs = 0;
	int j, k;

	for(j = 0; j < size - 1; j++)
	{
		for(k = j + 1; k < size; k++)
		{
			if(list[j] != list[k])
			{
				//printf("%d %d, ",list[j], list[k]);
				num_pairs++;
				if(gcd(list[j], list[k]) == 1)
				{
					num_gcd_pairs++;
				}
			}
		}
	}

	//printf("%.2lf %.2lf\n", num_pairs, num_gcd_pairs);
	return sqrt((6.0 * num_pairs) / num_gcd_pairs);
}

int gcd(int a, int b)
{
	int c;
	while(a != 0)
	{
		c = a;
		a = b % a;
		b = c;
	}
	return b;
}
