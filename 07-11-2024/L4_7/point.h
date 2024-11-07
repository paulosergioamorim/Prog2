#ifndef _POINT_
#define _POINT_

typedef struct
{
    int x;
    int y;
} tPonto;

int get_quadrante(tPonto ponto);
int get_x(tPonto ponto);
int get_y(tPonto ponto);
tPonto cria_ponto(int x, int y);
tPonto le_ponto();
#endif