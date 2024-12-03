#pragma once

typedef struct triangulo {
    int comp;
    int alt;
} Triangulo;

Triangulo criaTriangulo(int comp, int alt);

double calculaAreaTriangulo(Triangulo t);

double calculaPrecoAreaTriangulo(Triangulo t, double preco);