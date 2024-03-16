// CS1010 Programming Methodology
// Problem Set 1 Exercise #24: lifts.c
// 
// Program reads in 2 lift numbers, and its starting and end levels.
// and prints out the answers for lift 1, then lift 2.
//
// SHEIKH UMAR

#include <stdio.h>

int main(void)
{
	int f1, f2, f3, f4;
	int l1, s1, e1;
	int l2, s2, e2;
	int t1, t2, t3, t4;
	int total_1, total_2;
	
	// first instruction
	printf("Enter 1st instruction: ");
	scanf("%d %d %d", &l1, &s1, &e1);
	
	// process first instruction
	f1 = (s1 - 1);
	if (f1 < 0)
	{
		f1 *= -1;
	}
	t1 = (f1 * 2);

	f2 = (e1 - s1);
	if (f2 < 0)
	{
		f2 *= -1;
	}
	t2 = (f2 * 2);
	
	total_1 = (t1 + t2);

	// second instruction
	printf("Enter 2nd instruction: ");
	scanf("%d %d %d", &l2, &s2, &e2);

	// process second instruction
	f3 = (s2 - 1);
	if (f3 < 0)
	{
		f3 *= -1;
	}
	t3 = (f3 * 2);

	f4 = (s2 - e2);
	if (f4 < 0)
	{
		f4 *= -1;
	}
	t4 = (f4 * 2);

	total_2 = (t4 + t3);

	// print out results
	// Check which entry has lift 1, then print out that result first
	if ((l1 == 1) && (l2 == 2))
	{
		printf("Lift 1 took %d sec. and ended at level %d\n", total_1, e1); 
		printf("Lift 2 took %d sec. and ended at level %d\n", total_2, e2);
	}

	else if ((l2==1) && (l1==2))
	{
		printf("Lift 1 took %d sec. and ended at level %d\n", total_2, e2); 
		printf("Lift 2 took %d sec. and ended at level %d\n", total_1, e1);
	}

	else if ((l1 == 1) && (l2 == 1))
	{

		f1 = (s1 - 1);
		if (f1 < 0)
		{
			f1 *= -1;
		}
		t1 = (f1 * 2);

		f2 = (e1 - s1);
		if (f2 < 0)
		{
			f2 *= -1;
		}
		t2 = (f2 * 2);

		total_1 = (t1 + t2);

		f3 = (s2 - e1);
		if (f3 < 0)
		{
			f3 *= -1;
		}
		t3 = (f3 * 2);

		f4 = (e2 - s2);
		if (f4 < 0)
		{
			f4 *= -1;
		}
		t4 = (f4 * 2);
	
		total_2 = (t3 + t4);
		int total = (total_1 + total_2);

		printf("Lift 1 took %d sec. and ended at level %d\n", total, e2); 
		printf("Lift 2 took 0 sec. and ended at level 1\n");
	}

	else
	{
		f1 = (s1 - 1);
		if (f1 < 0)
		{
			f1 *= -1;
		}
		t1 = (f1 * 2);

		f2 = (e1 - s1);
		if (f2 < 0)
		{
			f2 *= -1;
		}
		t2 = (f2 * 2);

		total_1 = (t1 + t2);

		f3 = (s2 - e1);
		if (f3 < 0)
		{
			f3 *= -1;
		}
		t3 = (f3 * 2);

		f4 = (e2 - s2);
		if (f4 < 0)
		{
			f4 *= -1;
		}
		t4 = (f4 * 2);

		total_2 = (t3 + t4);
		int total = (total_1 + total_2);

		printf("Lift 1 took 0 sec. and ended at level 1\n");
		printf("Lift 2 took %d sec. and ended at level %d\n",total, e2); 
	}

	return 0;
}
