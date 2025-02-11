#pragma once

#include <math.h>
#define PI 3.14

typedef struct circulo * Circulo;

Circulo create_circulo(int raio);

double get_area_circulo(Circulo circulo);

void free_circulo(Circulo circulo);