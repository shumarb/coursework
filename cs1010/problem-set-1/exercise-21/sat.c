// CS1010 Programming Methodology
// Problem Set 1 Exercise #21: sat.c
//
// Program reads in the scores for the 3 majors:  Verbal, Maths, and Writing,
// and computes the SAT score.
// Program then computes the SAT score, which is a sum of the Verbal, Maths, and Writing scores
// Program then computes the IQ scores, based on the Maths and Verbal scores only
// Program prints out the IQ score.
// If each major score is more than 600, OR IQ score is at least 120
// Program prints out "Wow, this is amazing!"
// SHEIKH UMAR

#include <stdio.h>

// function prototypes
int compute_percentile(int verbal, int maths, int writing);
double compute_iqscore(int verbal, int maths);

int main(void) {

	int verbal, maths, writing;
	int percentage; // percentile of the SAT score
	double iq;      // IQ score

	printf("Enter scores: ");
	scanf("%d %d %d",&verbal, &maths, &writing);

	//Pass values of verbal, maths, and writing to compute_percentile function to compute percentile
	percentage=compute_percentile(verbal, maths, writing);
	
	//Pass values of verbal and maths to compute_iqscore to compute IQ
	iq=compute_iqscore(verbal, maths);

	printf("The SAT score is in the %d percentile.\n", percentage);
	printf("The IQ score is %.2f\n", iq);
	
	//Print out this message if each major score is >600 or IQ is >=120
	if (((verbal>600) &&  (maths>600) && (writing>600)) || iq>=120){
		printf("Wow, this is amazing!\n");
	}

	return 0;
}

//Function computes SAT score, then identifies and prints out the corresponding percentile
int compute_percentile(int verbal, int maths, int writing) {
	int score;
	int percentile;
	score = verbal+maths+writing;
	//Score <1500 corresponds to 10th percentile
	//Assign value of percentile as 10
	if (score<1500){
		percentile=10;
	}

	//1500<=score<2000  corresponds to 50th percentile
	//Assign value of percentile as 50
	else if (score>=1500 && score<2000){
		percentile=50;
	}

	//2000<=score<2200 corresponds to 95th percentile
	//Assign value of percentile as 95
	else if (score>=2000 && score<2200){
		percentile=95;
	}
	//Score other than the first three conditions corresponds to 99th percentile
	//Assign value of percentile as 99
	else{
		percentile=99;
	}
	//Return value of percentile to main function, which will display it
	return percentile;
}

//Function computes the IQ score based on verbal and maths scores only
double compute_iqscore(int verbal, int maths) {
	double i;
	i = (0.095*maths) + (0.003*verbal) + 50.241;
	//Return value of IQ to main function
	return i;
}

