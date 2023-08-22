// check_order.c 
// Repeatedly reads positive integer, until the input value 
// is zero, or the data are not in increasing order.
//
// SHEIKH UMAR
#include <stdio.h>

int main(void) {
	int current_number, previous_number, is_increasing = 1;
	printf("Enter positive integer: ");
	scanf("%d", &current_number);

	previous_number = current_number;
	while (1)
	{
		printf("Enter positive integer: ");
		scanf("%d", &current_number);
		
		// Exit loop if user enters 0
		if (current_number == 0)
		{
			break;
		}

		// if latest number user entered is less or equal to than previous number
		// then data is not in increasing order
		if (current_number <= previous_number)
		{
			is_increasing = 0;
			break;
		}

		// update previous number to value that user just entered
		// before asking user for a positive integer
		previous_number = current_number;
	}

	if (is_increasing)
	{
		printf("Data are in increasing order.\n");
	}
	else
	{
		printf("Data are not in increasing order.\n");
	}

	return 0;
}

