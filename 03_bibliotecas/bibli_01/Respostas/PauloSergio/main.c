#include "esfera_utils.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    float r = 0;
    scanf("%f", &r);
    float area = calcula_area(r);
    float volume = calcula_volume(r);
    printf("Area: %.2f\nVolume: %.2f\n", area, volume);

    return 0;
}
