/*
 *  freezer.c
 *  Unit 4 Exercise 5: Estimate temperature in a freezer
 *  given the elapsed time since power failure.
 *  Formula: T = (4*t^2 / (t+2)) - 20
 */
#include <stdio.h>

int main(void)
{
	int hours, minutes, is_test = 0; // is_test is for debugging
	float temperature;  // Temperature in freezer

	// Get the hours and minutes
	printf("Enter hours and minutes since power failure: ");
	scanf("%d %d", &hours, &minutes);

	float small_t = (float) hours + ((float) minutes / 60);
	if (is_test)
	{
		printf("small_t = %lf\n", small_t);
	}

	temperature = ((4.0 * small_t * small_t) / (small_t + 2.0)) - 20.0;

	printf("Temperature in freezer = %.2f\n", temperature);
	return 0;
}
