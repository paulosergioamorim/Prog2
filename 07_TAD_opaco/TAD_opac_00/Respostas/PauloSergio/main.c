#include <stdio.h>
#include "circulo.h"
#include "ponto.h"

int main(int argc, char const *argv[])
{
    float x1 = 0;
    float x2 = 0;
    float y1 = 0;
    float y2 = 0;
    float r = 0;

    scanf("%f %f %f %f %f", &x1, &y1, &r, &x2, &y2);

    tCirculo circulo = Circulo_Cria(x1, y1, r);
    tPonto ponto = Pto_Cria(x2, y2);

    printf("%d\n", Circulo_Interior(circulo, ponto));

    Circulo_Apaga(circulo);
    Pto_Apaga(ponto);

    return 0;
}
