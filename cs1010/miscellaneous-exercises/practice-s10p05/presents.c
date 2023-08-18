/**********************************************************
Program: presents.c
************************************************************/

#include <stdio.h>

int present_on_day(int);
int present_thru_days(int, int, int);

// The main program is called with an integer argument
// denoting the "n-th" day on which the number of presents
// will be determined.
//
// SHEIKH UMAR
int main(void) {
	int n;

    printf("Please enter the number of days: ");
	scanf("%d", &n);

	printf("You have entered the number of days as: %d\n", n);

	if (n == 1) {
		printf("The number of present received on day 1 is %d.\n", n);

		printf("The number of present received in 1 day is %d.\n", n);
	}
	else { // Here, n > 1 
		printf("The number of presents received on day %d is %d.\n", n, present_on_day(n));

		printf("The number of presents received in %d days is %d.\n", n, present_thru_days(n, 1, 0));
	}
	return 0;
}

// This function determines the number of presents to be received 
// on the n-th day.
// Pre-condition: n >= 1
int present_on_day(int n) {
	// base case: n == 1
	// this means n is day 1
	// and on day 1, only 1 gift received
	// hence return this number of gifts, which is 1.
	if (n == 1)
	{
		return 1;
	}

	// recursive case: n > 1, so return summation of 1 to n
	// by n + recursive call of function for number n - 1
	return n + present_on_day(n - 1);
}

// This function determines the number of presents to be received
// throughout n days.
// Pre-condition: n >= 1
int present_thru_days(int n, int n_so_far, int total) {
	// base case: (n + 1)-th day is reached
	// this means total gifts received in n days has been confirmed
	// so return total
	if ((n + 1) == n_so_far)
	{
		return total;
	}
	
	// recursive case: (n + 1)th day is not reached
	// this means total number of gifts received in n days not confirmed.
	// hence, this means number of gifts received per day up to n-th day not reached.
	// hence, calculate number of gifts received per day from from day 1 to day n,
	// add this to total, and repeat this step until day (n + 1)-th day is reached.
	total += present_on_day(n_so_far);
	return present_thru_days(n, (n_so_far + 1), total);
}

