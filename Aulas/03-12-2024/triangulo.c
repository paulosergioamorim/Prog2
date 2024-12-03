#include "triangulo.h"

Triangulo criaTriangulo(int comp, int alt)
{
    Triangulo triangulo = {comp, alt};

    return triangulo;
}

double calculaAreaTriangulo(Triangulo t)
{
    return (double)t.comp * t.alt / 2;
}

double calculaPrecoAreaTriangulo(Triangulo t, double preco)
{
    return calculaAreaTriangulo(t) * preco;
}
