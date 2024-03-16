// perfectNumber.c 
// Repeatedly reads a non-negative value, and stops when zero is read.
// For each positive value read, it checks if the value is a perfect number.
//
// SHEIKH UMAR
#include <stdio.h>

int is_perfect(int);

int main(void) {
	int num;

	printf("Enter number: ");
	scanf("%d", &num);

	while(num != 0)
	{
		if(is_perfect(num))
		{
			printf("%d is a perfect number.\n", num);
		}
		else
		{
			printf("%d is not a perfect number.\n", num);
		}

		printf("Enter number: ");
		scanf("%d", &num);
	}

	return 0;
}

int is_perfect(int num)
{
	int total = 0, i;

	for(i = 1; i <= (num / 2); i++)
	{
		if((num % i) == 0)
		{
			total += i;
		}
	}

	return total == num;
}
