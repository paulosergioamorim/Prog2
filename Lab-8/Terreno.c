#include "Terreno.h"
#include <stdio.h>
#include <stdlib.h>

struct terreno
{
    void *terreno;
    enum TERRENO tipo;
};

/**
* Inicializa o struct terreno, atribuindo os parametros aos membros
internos do Terreno_pt
*/
Terreno_pt InicializaTerreno(void *terreno, enum TERRENO tipo) {
    Terreno_pt pTerreno = malloc(sizeof(struct terreno));

    pTerreno->terreno = terreno;
    pTerreno->tipo = tipo;

    return pTerreno;
}

/**
 * Calcula a área do terreno.
 */
double Area(Terreno_pt t) {
    switch (t->tipo) {
        case CIRCULO:
            Circulo terrenoCirculo = (Circulo) t->terreno;
            return get_area_circulo(terrenoCirculo);
        case TRIANGULO:
            Triangulo terrenoTriangulo = (Triangulo) t->terreno;
            return get_area_triangulo(terrenoTriangulo);
        case RETANGULO:
            Retangulo terrenoRetangulo = (Retangulo) t->terreno;
            return get_area_retangulo(terrenoRetangulo);
        default:
            return 0.0;
    }
}

/**
 * Libera todas as posições da memória
 */
void liberaTerreno(Terreno_pt t) 
{
    free(t->terreno);
    free(t);   
}