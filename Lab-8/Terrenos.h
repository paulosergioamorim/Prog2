#pragma once
#include "Terreno.h"

typedef struct terrenos Terrenos;

typedef Terrenos *Terrenos_pt;

Terrenos_pt InicializaTerrenos(int qtde);

/***
 * Adiciona no Terreno uma forma f descrita pelo enum TERRENO
 */
void adicionarArea(Terrenos_pt t, Terreno *f);

/**
 * Calcula a área dos terrenos.
 */
double AreaTotal(Terrenos_pt t);

/**
 * Calcula a média total de desmatamento
 */
double Media(Terrenos_pt terrenos);

/**
 * Calcula o desvio padrão de desmatamento
 */
double DesvioPadrao(Terrenos_pt terrenos);

void liberaTerrenos(Terrenos_pt t);