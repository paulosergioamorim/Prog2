#ifndef EXERC1_CIRCULARES_H
#define EXERC1_CIRCULARES_H
#define PI 3.1415

typedef struct crirculo
{
    double raio;
} Circulo;

Circulo criaCirculo(double raio);

double calculaAreaCirculo(Circulo c);

double calculaPrecoAreaCirculo(Circulo c, double preco);

#endif
