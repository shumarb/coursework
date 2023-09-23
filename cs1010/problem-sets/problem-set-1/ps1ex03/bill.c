// CS1010 Programming Methodology
// Problem Set 1 Exercise #03: bill.c
//
// Program computes total bill based on a menu price
//
// SHEIKH UMAR

#include <stdio.h>

int main(void)
{
	double gst, net_price, service_charge;

	printf("Enter menu price: $");
	scanf("%lf", &net_price);

	service_charge = net_price * 0.1;
	printf("10%% Service Charge: $%.2lf\n", service_charge);

	gst = 0.07 * (net_price + service_charge);
	printf("7%% GST: $%.2lf\n", gst);

	printf("Your total bill: $%.2lf\n", gst + net_price + service_charge);

	return 0;
}
