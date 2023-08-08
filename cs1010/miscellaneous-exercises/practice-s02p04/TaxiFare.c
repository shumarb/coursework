// TaxiFare.c
// This program computes taxi fare.
//
// SHEIKH UMAR
#include <stdio.h>
#include <math.h>
#define INCREMENT 0.22

float computeFare(int, int, int);

int main(void) {    
	int dayType; // 0 = weekends and public holidays;
	             // 1 = weekdays and non public holidays
	int boardHour, boardMin; // hour and minute of boarding
	int boardTime;           // converted from boardHour and boardMin
	int distance;            // distance of journey

	printf("Day type: ");
	scanf("%d", &dayType);
	printf("Boarding hour and minute: ");
	scanf("%d %d", &boardHour, &boardMin);
	printf("Distance: ");
	scanf("%d", &distance);

	// complete the next line
	// boardTime = ... 
	boardTime = 60 * boardHour + boardMin;
	printf("Boarding time is %d minutes\n", boardTime);

	printf("Total taxi fare is $%.2f\n", 
	       computeFare(dayType, boardTime, distance));

	return 0;
}

// Compute taxi fare based on
//   type: 0 = weekends and PH; 1 = weekdays
//   time: time passenger boarded taxi (in minutes from 0:00hr)
//   dist: distance of journey
// This function is called a stub as it returns a dummy value
float computeFare(int type, int time, int dist) {
	float basic_fare = 0.0, surcharge = 0.0;
	
	// 1. Computation for first 1km.
	// Add flag-down fare to basic fare for first 1km
	// and remove this first km from distance travelled
	// because next calculation is for 1001th metres onwards upto 10.2km of total trip
	basic_fare += 3.4;
	dist -= 1000;

	// 2. Computation for 1.01km (1001th metre) to 10.2km
	// Determine number of increments made for every 400m,
	// multiply this value by $0.22, and add this value to basic fare
	// This comprises of 2 scenarios: distance <= 9200km, and distance > 9200km
	int num_increment;
	if (dist <= 9200)
	{
		num_increment = ceil((float) dist / 400.0);
		basic_fare += (num_increment * INCREMENT);
	}
	else
	{
		// Distance to travel is > 9200,
		// so computation comprises of 2 parts: first 9.2km, and distance from 9201th metre to end of dist
		num_increment = ceil((float) 9200.0 / 400.0);
		basic_fare += (num_increment * INCREMENT);

		// Reduce distance by 9200m for calculation of distance between 9201st m to end of dist
		// calculate number of increments made for every 350m,
		// multiply this value by $0.22, and add this value to basic fare
		dist -= 9200;
		num_increment = ceil((float) dist / 350.0);
		basic_fare += (num_increment * INCREMENT);
	}

	// 3. Calculate surcharge based on day type and time
	if (type == 0)
	{
		// Midnight charge
		if (time >= 0 && time <= (5 * 60 + 59))
		{
			surcharge = basic_fare * 0.5;
		}

		if (time >= (18 * 60) && time <= (23 * 60 + 59))
		{
			surcharge = basic_fare * 0.25;
		}	
	}

	else
	{
		// Last step. Calculate surcharge based on time
		// Midnight charge
		if (time >= 0 && time <= (5 * 60 + 59))
		{
			surcharge = basic_fare * 0.5;
		}

		// Peak-hour charge
		if (time >= (6 * 60) && time <= (9 * 60 + 29))
		{
			surcharge = basic_fare * 0.25;
		}

		// Peak-hour charge
		if (time >= (18 * 60) && time <= (23 * 60 + 59))
		{
			surcharge = basic_fare * 0.25;
		}
	}

	return basic_fare + surcharge;
}

