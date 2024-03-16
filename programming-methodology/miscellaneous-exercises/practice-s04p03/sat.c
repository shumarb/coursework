// CS1010 AY2012/3 Semester 1
// PE1 Ex1: sat.c
// Name: Sheikh Umar

#include <stdio.h>

double compute_iqscore(int, int);
int compute_percentile(int, int, int);
int determines_amazing(int, int, int);

int main(void) {

	double iq_score;
	int verbal, math, writing;

	printf("Enter scores: ");
	scanf("%d %d %d", &verbal, &math, &writing);

	printf("The SAT score is in the %d percentile.\n", compute_percentile(verbal, math, writing));

	iq_score = compute_iqscore(verbal, math);
	printf("The IQ score is %.2lf\n", iq_score);

	if(iq_score >= 120.0 || determines_amazing(verbal, math, writing))
	{
		printf("Wow, this is amazing!\n");
	}

	return 0;
}

double compute_iqscore(int verbal, int math)
{
	return ((0.095 * (double) math) + (0.003 * (double) verbal) + 50.241);
}

int determines_amazing(int verbal, int math, int writing)
{
	return ((verbal > 600) && (math > 600) && (writing > 600));
}

int compute_percentile(int verbal, int math, int writing)
{
	int sat_score;
	sat_score = verbal + math + writing;

	if (sat_score < 1500)
	{
		return 10;
	}
	
	if (sat_score >= 1500 && sat_score < 2000)
	{
		return 50;
	}

	if (sat_score >= 2000 && sat_score < 2200)
	{
		return 95;
	}

	return 99;
}

