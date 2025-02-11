#pragma once

typedef struct retangulo * Retangulo;

Retangulo create_retangulo(int comprimento, int largura);

double get_area_retangulo(Retangulo retangulo);

void free_retangulo(Retangulo retangulo);