#pragma once

typedef struct triangulo * Triangulo;

Triangulo create_triangulo(int base, int altura);

double get_area_triangulo(Triangulo triangulo);

void free_triangulo(Triangulo triangulo);