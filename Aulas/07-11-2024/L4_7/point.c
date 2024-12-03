#include "point.h"
#include <stdio.h>

int get_quadrante(tPonto ponto)
{
    int x = get_x(ponto);
    int y = get_y(ponto);

    if (x == 0 || y == 0)
        return 0;
    if (x >= 0 && y >= 0)
        return 1;
    if (x > 0 && y < 0)
        return 4;
    if (x < 0 && y < 0)
        return 3;
    return 2;
}

tPonto cria_ponto(int x, int y)
{
    tPonto ponto = {x, y};
    return ponto;
}

tPonto le_ponto()
{
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    return cria_ponto(x, y);
}

int get_x(tPonto ponto)
{
    return ponto.x;
}

int get_y(tPonto ponto)
{
    return ponto.y;
}