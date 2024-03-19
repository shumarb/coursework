// speedOfSound.c
// Read a temperature and compute the speed of sound in air.
// You must write a function speed_of_sound().
//
// SHEIKH UMAR

#include <math.h>
#include <stdio.h>

float speed_of_sound(float);

float speed_of_sound(float degree) 
{
    return 1086.0 * sqrt(((5.0 * degree) + 297.0) / 247.0);
}

int main(void)
{
    float degree, speed;  

    printf("Temperature in degree Fahrenheit: ");
    scanf("%f", &degree);

    speed = speed_of_sound(degree);

    printf("Speed of sound in air of %.2f degree = %.2f ft/sec\n", degree, speed);

    return 0;
}
