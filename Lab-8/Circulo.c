#include "Circulo.h"
#include <stdlib.h>
#include <assert.h>

struct circulo {
    int raio;
};

Circulo create_circulo(int raio) {
    Circulo pCirculo = malloc(sizeof(struct circulo));
    assert(pCirculo);

    pCirculo->raio = raio;

    return pCirculo;
}

double get_area_circulo(Circulo circulo) {
    return circulo->raio * circulo->raio * PI; 
}

void free_circulo(Circulo circulo) {
    free(circulo);
}