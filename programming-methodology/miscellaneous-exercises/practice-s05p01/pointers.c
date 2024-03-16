// pointers.c
// Exercise on using pointers.
//
// SHEIKH UMAR
#include <stdio.h>

int main(void) {
	int a, *a_ptr;
	float b, *b_ptr;

	printf("Enter an integer: ");
	scanf("%d", &a);
	printf("Enter a real number: ");
	scanf("%f", &b);

	a_ptr = &a;
	b_ptr = &b;
	printf("Values entered are %d and %.2f\n", *a_ptr, *b_ptr);

	while ((double) *a_ptr < (*b_ptr * *b_ptr))
	{
		*a_ptr *= *b_ptr;
	}

	printf("Final value of a = %d\n", *a_ptr);
	
	return 0;
}

