#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 0;
    float y = 0;
    char z = 0;
    int *pX = &x;
    float *pY = &y;
    char *pZ = &z;
    
    printf("x = %d\n", x);
    printf("pX = %p\n", pX);
    printf("y = %f\n", y);
    printf("pY = %p\n", pY);
    printf("z = %x\n", z);
    printf("pZ = %p\n", pZ);

    *pX = 2;
    *pY = 1.2;
    *pZ = 'A';
    
    printf("x = %d\n", x);
    printf("pX = %p\n", pX);
    printf("y = %f\n", y);
    printf("pY = %p\n", pY);
    printf("z = %x\n", z);
    printf("pZ = %p\n", pZ);

    return 0;
}
