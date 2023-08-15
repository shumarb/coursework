// countInputs.c
// To count the number of input values user entered.
//
// SHEIKH UMAR
#include <stdio.h>

int main(void) {    
    int num_values = 0, value;
    printf("Enter integers, terminate with ctrl-d\n");

    while (scanf("%d", &value) == 1)
    {
        num_values++;
    }

    printf("Number of values entered = %d\n", num_values);

    return 0;
}

