#pragma once

typedef struct retangulos {
    int comp;
    int larg;
} Retangulo;

Retangulo criaRetangulo(int comp, int larg);

double calculaAreaReatangulo(Retangulo r);

double calculaPrecoAreaRetangulo(Retangulo r, double preco);
