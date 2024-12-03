#include "retangulo.h"

Retangulo criaRetangulo(int comp, int larg)
{
    Retangulo retangulo = {comp, larg};

    return retangulo;
}

double calculaAreaReatangulo(Retangulo r)
{
    return r.comp * r.larg;
}

double calculaPrecoAreaRetangulo(Retangulo r, double preco)
{
    return calculaAreaReatangulo(r) * preco;
}
