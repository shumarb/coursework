// magicNumber.c
// You must write a function get_magic().
//
// SHEIKH UMAR
#include <stdio.h>

int get_magic(int);


// Precon: User has entered 2 positive integers
// Postcon: Display magic number
int get_magic(int num)
{   
    int sum = 0;
    while (num != 0)
    {
        // Increase sum by last digit of num
        sum += (num % 10);
        
        // Remove last 2 digits of num
        num /= 100;
    }
    
    // Return last digit of magic number
    return (sum % 10);
}


int main(void) {

    int num1, num2;

    printf("Enter 1st value: ");
    scanf("%d", &num1);
    printf("Magic number = %d\n", get_magic(num1));

    printf("Enter 2nd value: ");
    scanf("%d", &num2);
    printf("Magic number = %d\n", get_magic(num2));
    
    return 0;
}

