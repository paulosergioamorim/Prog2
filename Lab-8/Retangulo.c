#include "Retangulo.h"
#include <stdlib.h>
#include <assert.h>

struct retangulo {
    int largura;
    int comprimento;
};

Retangulo create_retangulo(int comprimento, int largura) {
    Retangulo pRetangulo = malloc(sizeof(struct retangulo));
    assert(pRetangulo);

    pRetangulo->comprimento = comprimento;
    pRetangulo->largura = largura;

    return pRetangulo;
}

double get_area_retangulo(Retangulo retangulo) {
    return retangulo->comprimento * retangulo->largura;
}

void free_retangulo(Retangulo retangulo) {
    free(retangulo);
}