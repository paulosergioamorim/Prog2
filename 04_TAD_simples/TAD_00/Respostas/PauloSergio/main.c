#include <stdio.h>
#include "ponto.h"

int main(int argc, char const *argv[])
{
    Ponto p1;
    Ponto p2;
    float x1 = 0;
    float x2 = 0;
    float y1 = 0;
    float y2 = 0;
    
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    p1 = pto_cria(x1, y1);
    p2 = pto_cria(x2, y2);
    printf("%g", pto_distancia(p1, p2));

    return 0;
}
