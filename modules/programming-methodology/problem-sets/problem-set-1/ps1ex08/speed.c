// CS1010 Programming Methodology
// Problem Set 1 Exercise #08: speed.c
//
// Program calculates the speed of sound based on a given temperature
//
// SHEIKH UMAR

#include <math.h>
#include <stdio.h>

// function prototype
double speed_of_sound(double);

// main function is complete
int main(void) {

	double speed, temperature;

	printf("Temperature in degree Fahrenheit: ");
	scanf("%lf", &temperature);

	speed = speed_of_sound(temperature);
	printf("Speed = %.2f ft/sec\n", speed);

	return 0;
}

// Return speed of sound given temperature
double speed_of_sound(double temperature) {
	return ((1086.0) * sqrt(((5.0 * temperature) + 297.0) / 247.0));
}
