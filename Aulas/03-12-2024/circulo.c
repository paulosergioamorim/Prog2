#include "circulo.h"

Circulo criaCirculo(double raio)
{
    Circulo c = { raio };

    return c;
}

double calculaAreaCirculo(Circulo c)
{
    return c.raio * c.raio * PI;
}

double calculaPrecoAreaCirculo(Circulo c, double preco)
{
    return calculaAreaCirculo(c) * preco;
}
