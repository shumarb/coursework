// CS1010 Programming Methodology
// Problem Set 2 Exercise #12: count_primes.c
//
// Program reads in a limit, prints out number of primes
// from 1 to limit.
//
// SHEIKH UMAR
#include <stdio.h>
#include <math.h>
int is_prime(int num);

//int count_primes(int limit);

int main(void) {
	int i;
	int limit;
	int primes=0;

	printf("Enter limit: ");
	scanf("%d",&limit);
	//1 is not a prime.
	if(limit==1){
		printf("Number of primes (1-%d): 0\n",limit);
	}
	//Hardcode 2, as 2%1==2%2==0, Hence it is a prime.
	else if(limit==2){
		printf("Number of primes (1-%d): 1\n",limit);
	}
	else{
		for(i=3;i<=limit;i++){
			is_prime(i);
			if(is_prime(i)==0){
				primes++;
			}
		}
		primes++;//Include 2, if limit>2
		printf("Number of primes (1-%d): %d\n",limit,primes);
	}

	return 0;
}
// Return 1 if num is a prime, 0 otherwise
int is_prime(int num){
	int j;
	int non_prime=0;//non_prime=0 is for prime number

	for(j=2;j<=sqrt(num);j++){
		if((num%j)==0){
			non_prime=1;//Num is divisible by a number other than 1 and itself.
									//Num is not a prime.
		}
	}
	return non_prime;
}


// return the number of primes in range [2, limit]
// 1 is not a prime!i
/*
	 int count_primes(int limit) {
	 return 0;  // stub
	 }
*/
