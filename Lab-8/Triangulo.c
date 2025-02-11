#include "Triangulo.h"
#include <stdlib.h>
#include <assert.h>

struct triangulo
{
    int base;
    int altura;
};

Triangulo create_triangulo(int base, int altura)
{
    Triangulo pTriangulo = malloc(sizeof(struct triangulo));
    assert(pTriangulo);

    pTriangulo->base = base;
    pTriangulo->altura = altura;

    return pTriangulo;
}

double get_area_triangulo(Triangulo triangulo)
{
    return (double)(triangulo->altura * triangulo->base) / 2;
}

void free_triangulo(Triangulo triangulo)
{
    free(triangulo);
}