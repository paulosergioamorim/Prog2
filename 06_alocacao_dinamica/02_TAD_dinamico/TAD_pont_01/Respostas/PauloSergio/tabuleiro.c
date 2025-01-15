#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tabuleiro.h"

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro *CriaTabuleiro()
{
    tTabuleiro *pTabuleiro = malloc(sizeof(tTabuleiro));
    assert(pTabuleiro);

    pTabuleiro->peca1 = 'X';
    pTabuleiro->peca2 = '0';
    pTabuleiro->pecaVazio = '-';
    pTabuleiro->posicoes = malloc(TAM_TABULEIRO * sizeof(char *));
    assert(pTabuleiro->posicoes);

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        pTabuleiro->posicoes[i] = malloc(TAM_TABULEIRO * sizeof(char));
        assert(pTabuleiro->posicoes[i]);
    }

    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
            pTabuleiro->posicoes[i][j] = pTabuleiro->pecaVazio;

    return pTabuleiro;
}

/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 *
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro *tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
        free(tabuleiro->posicoes[i]);

    free(tabuleiro->posicoes);
    free(tabuleiro);
}

/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y)
{
    tabuleiro->posicoes[y][x] = peca == PECA_1 ? tabuleiro->peca1 : tabuleiro->peca2;
}

/**
 * Verifica se há alguma posição livre no tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
            if (EstaLivrePosicaoTabuleiro(tabuleiro, i, j))
                return 1;

    return 0;
}

/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 *
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 *
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca)
{
    if (peca == PECA_1)
        return tabuleiro->posicoes[y][x] == tabuleiro->peca1;

    return tabuleiro->posicoes[y][x] == tabuleiro->peca2;
}

/**
 * Verifica se a posição do tabuleiro está livre.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 *
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y)
{
    return tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio;
}

/**
 * Verifica se a posição do tabuleiro é válida.
 *
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 *
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y)
{
    return 0 <= x && x < TAM_TABULEIRO && 0 <= y && y < TAM_TABULEIRO;
}

/**
 * Imprime o tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro *tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        printf("\t");

        for (int j = 0; j < TAM_TABULEIRO; j++)
            printf("%c", tabuleiro->posicoes[i][j]);

        printf("\n");
    }
}