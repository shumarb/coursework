// CS1010 AY2011/2 Semester 1 
// PE1 Ex2: winners.c
// Name: Sheikh Umar

#include <stdio.h>
int computes_winners(int, int, int);

int main(void)
{
	int factor, must_have, participants;       

	printf ("Enter factor-digit: ");
	scanf("%d", &factor);
	printf("Enter must-have-digit: ");
	scanf("%d", &must_have);
	printf("Enter number of participants: ");
	scanf("%d", &participants);

	printf("Number of winners: %d\n", computes_winners(factor, must_have, participants));
	
	return 0;
}

int computes_winners(int factor, int must_have, int participants)
{
	int num_winners = 0, i, number;

	for (i = 1; i <= participants; i++)
	{
		number = i;

		// if number is a multiple of factor digit
		if ((number % factor) == 0)
		{	
			// determine if number has a must_have digit
			while (number != 0)
			{	
				// number has a must_have digit
				// so increase number of winners by 1
				if ((number % 10) == must_have)
				{
					num_winners++;
					break;
				}
				
				number /= 10;
			}
		}
	}
	
	return num_winners;
}

