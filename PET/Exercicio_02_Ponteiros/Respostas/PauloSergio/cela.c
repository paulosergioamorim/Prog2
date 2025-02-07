#include "cela.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Cria uma cela da prisão a partir do parâmetro da capacidade das celas.
 * @param capacidade numero máximo de presidiários na cela
*/
tCela criaCela(int capacidade) {
    tCela cela;
    cela.capacidade = capacidade;
    cela.nPresidiarios = 0;

    return cela;
}

/**
 * @brief Retorna valor diferente de zero caso haja uma vaga na cela, e 0 caso contrario.
 * @param cela Cela que se deseja saber se há vaga
*/
int possuiVagaCela(tCela* cela) {
    return cela->nPresidiarios < cela->capacidade;
}

/**
 * @brief Retorna o numero atual de prisioneiros na cela
*/
int obtemNumeroPrisioneirosCela(tCela* cela) {
    return cela->nPresidiarios;
}

/**
 * @brief Insere o prisioneiro na cela, após já ter garantido que há vaga na cela
*/
void inserePrisioneiroCela(tCela* cela, tPrisioneiro prisioneiro) {
    if (!possuiVagaCela(cela))
        return;

    cela->prisioneiros[cela->nPresidiarios] = prisioneiro;
    cela->nPresidiarios++;
}

/**
 * @brief Retorna o presidiário da cela na posição fornecida
 * @param cela Cela que se deseja obter o prisioneiro
 * @param i Posição do prisioneiro desejado no vetor de prisioneiros da cela
*/
tPrisioneiro obtemPrisioneiroCela(tCela* cela, int i) {
    return cela->prisioneiros[i];
}

/**
 * @brief Chama a função individual de fuga para cada prisioneiro da cela
 * @param cela Cela onde ocorre a fuga
*/
void fogePrisioneirosCela(tCela* cela) {
    for (int i = 0; i < cela->nPresidiarios; i++)
        fogePrisioneiro(&cela->prisioneiros[i]);

    cela->nPresidiarios = 0;    
}

/**
 * @brief Chama a função individual de passar o dia para cada prisioneiro da cela
 * @param cela cela fornecida para o passar do dia
*/
void passaDiaCela(tCela* cela) {
    for (int i = 0; i < cela->nPresidiarios; i++)
        passaTempoPrisioneiro(&cela->prisioneiros[i]);

    for (int i = 0; i < cela->nPresidiarios; i++)
    {
        if (!acabouPenaPrisioneiro(&cela->prisioneiros[i]))
            continue;
        
        liberaPrisioneiroCumpriuPena(&cela->prisioneiros[i]);

        for (int j = i; j < cela->nPresidiarios - 1; j++)
            cela->prisioneiros[j] = cela->prisioneiros[j + 1];

        cela->nPresidiarios--;
    }    
}