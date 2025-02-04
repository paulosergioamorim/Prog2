#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "prisioneiro.h"

/**
 * @brief Cria o prisioneiro a partir dos parâmetros fornecidos
 * @param nome Nome do prisioneiro
 * @param pena Pena a ser cumprida pelo prisioneiro
*/
tPrisioneiro criaPrisioneiro(char* nome, int pena) {
    tPrisioneiro prisioneiro;
    strcpy(prisioneiro.nome, nome);
    prisioneiro.pena = pena;
    prisioneiro.tempoPassado = 0;
}

/**
 * @brief Aumenta o tempo passado do prisioneiro
*/
void passaTempoPrisioneiro(tPrisioneiro* prisioneiro) {
    prisioneiro->tempoPassado++;
}

/**
 * @brief Imprime a fuga do prisioneiro na tela e chama a função de desalocação 
*/
void fogePrisioneiro(tPrisioneiro* prisioneiro) {

}

/**
 * @brief Retorna 1 quando a pena do prisioneiro termina
*/
int acabouPenaPrisioneiro(tPrisioneiro* prisioneiro) {
    return prisioneiro->tempoPassado > prisioneiro->pena; 
}

/**
 * @brief Imprime a liberação do prisioneiro na tela
*/
void liberaPrisioneiroCumpriuPena(tPrisioneiro* prisioneiro) {
    
}

/**
 * @brief Imprime a liberação do prisioneiro na tela para encerrar o programa
*/
void liberaPrisioneiroFimPrograma(tPrisioneiro* prisioneiro);
