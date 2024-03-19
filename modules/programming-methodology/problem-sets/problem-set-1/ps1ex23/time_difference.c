// CS1010 Programming Methodology
// Problem Set 1 Exercise #23: time_difference.c
//
// Program reads in 2 times, and prints out its difference
//
// SHEIKH UMAR

#include <stdio.h>

int main(void) {
	int h1, m1, s1;
	int h2, m2, s2;
	int h3, m3, s3;

	scanf("%d %d %d", &h1, &m1, &s1);
	scanf("%d %d %d", &h2, &m2, &s2);

	if ((h2 > h1) && (m2 > m1) && (s2 > s1))
	{
		h3 = h2 - h1;
		m3 = m2 - m1;
		s3 = s2 - s1;
	}
	else
	{
		if (s2 < s1)
		{
			m2--;
			s2 += 60;
			if (m2 < m1)
			{
				h2--;
				m2 += 60;
			}
		}
		
		h3 = h2 - h1;
		m3 = m2 - m1;
		s3 = s2 - s1;
	}

	printf("Time difference: %02d:%02d:%02d\n", h3, m3, s3);
	
	return 0;
}
