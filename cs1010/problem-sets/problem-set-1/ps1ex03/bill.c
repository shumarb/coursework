// CS1010 Programming Methodology
// Problem Set 1 Exercise #03: bill.c
//
// Program takes in a net price (key-ed in as integer type
// and converts it to type double for calculation.
// Program displays service and GST charges
// Program then displays total bill
//
// SHEIKH UMAR

#include <stdio.h>

int main(void) {
	int price;
	double service, gst, total;

	printf("Enter menu price: $");
	scanf("%d", &price);
	
	// Calculate service charge, make this answer into double type
	service = (double)(0.1 * price);
	printf("10%% Service Charge: $%.2lf\n", service);

	// Calculate GST, make this answer into double type
	gst = (double)(0.07 * (price + service));
	printf("7%% GST: $%.2lf\n", gst);
	
	// Calculate total bill,comprising of price, service and gst
	// Make price a double type from integer type
	total = (double)(price + service + gst);
	printf("Your total bill: $%.2lf\n", total);

	return 0;
}
