// CS1010 Programming Methodology
// Problem Set 4 Exercise #19: fraction.c
//
// This program reads in two fractions, 
// checks if they equal and computes their sum.
//
// SHEIKH UMAR

#include <stdio.h>

typedef struct {
	int numer;  // numerator
	int denom;  // denominator 
} fraction_t;

int euclid_gcd(int , int );
int equals(fraction_t, fraction_t);
fraction_t simplify(fraction_t);
fraction_t add(fraction_t, fraction_t);

int main(void)
{
	fraction_t frac1, f1, frac2, f2, frac3;

	printf("Enter 1st fraction: ");
	scanf("%d %d", &frac1.numer, &frac1.denom);

	printf("Enter 2nd fraction: ");
	scanf("%d %d", &frac2.numer, &frac2.denom);

	printf("1st fraction is %d/%d\n", frac1.numer, frac1.denom);
	printf("2nd fraction is %d/%d\n", frac2.numer, frac2.denom);
	
	f1 = frac1;
	f2 = frac2;
	
	f1 = simplify(f1);
	f2 = simplify(f2);

	if (equals(f1,f2))
	{
		printf("Two fractions are the same.\n");
		frac3.numer = 2 * (f1.numer);
		frac3.denom = f1.denom;
		frac3 = simplify(frac3);
	}
	else
	{
		printf("Two fractions are not the same.\n");

		// Find Common denominator
		frac3.denom = (frac1.denom) * (frac2.denom);
		frac3.numer = ((frac1.numer) * (frac2.denom) + (frac2.numer) * (frac1.denom));
		frac3 = simplify(frac3);
	}

	printf("%d/%d + %d/%d = %d/%d\n", frac1.numer, frac1.denom, frac2.numer, frac2.denom, frac3.numer, frac3.denom);

	return 0;
}


// Return simplified version of fraction
fraction_t simplify(fraction_t frac)
{
	fraction_t reduced = frac;
	int val = euclid_gcd(reduced.numer, reduced.denom);

	if (val != 1)
	{
		reduced.numer /= val;
		reduced.denom /= val;
	}

	return reduced;
}


// Return greatest common divisor of a and b
int euclid_gcd(int a, int b)
{
	while(a != 0)
	{
		return euclid_gcd(b % a, a);
	}

	return b;
}

// Check whether two fractions equal
// Return 1 if so, 0 otherwise
int equals(fraction_t frac1, fraction_t frac2)
{
	if (frac1.numer == frac2.numer && frac1.denom == frac2.denom)
	{
		return 1;
	}

	return 0;
}

// Add frac1 to frac2, return the result
// in the simplified form
fraction_t add(fraction_t frac1, fraction_t frac2)
{
	fraction_t sum;
	sum.numer = frac1.numer + frac2.numer;
	sum.denom = frac1.denom + frac2.denom;

	return sum;
}
