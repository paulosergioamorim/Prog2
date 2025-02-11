#include "Terrenos.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct terrenos {
    Terreno_pt * terrenos;
    int count;
    int qtde;
};

Terrenos_pt InicializaTerrenos(int qtde) {
    Terrenos_pt pTerrenos = malloc(sizeof(struct terrenos));
    pTerrenos->count = 0;
    pTerrenos->qtde = qtde;

    for (int i = 0; i < pTerrenos->qtde; i++)
    {
        char tipo = '\0';

        scanf("%c", &tipo);

        switch (tipo) {
            case 'C':
                int raio = 0;
                scanf("%d%*c", &raio);
                Circulo circulo = create_circulo(raio);
                pTerrenos->terrenos[i] = InicializaTerreno(circulo, CIRCULO);
            case 'R':
                int comprimento = 0;
                int largura = 0;
                scanf("%d %d%*c", &comprimento, &largura);
                Retangulo retangulo = create_retangulo(comprimento, largura);
                pTerrenos->terrenos[i] = InicializaTerreno(retangulo, RETANGULO);
            case 'T':
                int base = 0;
                int altura = 0;
                scanf("%d %d%*c", &base, &altura);
                Triangulo triangulo = create_triangulo(base, altura);
                pTerrenos->terrenos[i] = InicializaTerreno(triangulo, TRIANGULO);
        }
    }

    return pTerrenos;
}

/***
 * Adiciona no Terreno uma forma f descrita pelo enum TERRENO
 */
void adicionarArea(Terrenos_pt t, Terreno *f) {
    t[t->count] = *f;
}

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