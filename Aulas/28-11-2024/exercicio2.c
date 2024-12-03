#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 0;
    int y = 0;
    int *pX = &x;
    int *pY = &y;

    if (pX > pY)
        printf("O endereço de X (%p) é maior que o endereço de Y (%p)\n", pX, pY);
    
    else
        printf("O endereço de Y (%p) é maior que o endereço de X (%p)\n", pY, pX);

    return 0;
}
