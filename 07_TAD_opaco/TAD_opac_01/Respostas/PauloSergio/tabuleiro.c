#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tabuleiro.h"

struct Tabuleiro
{
    char piece1;
    char piece2;
    char empty;
    char **vec;
};

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro *CriaTabuleiro()
{
    tTabuleiro *tabuleiro = malloc(sizeof(struct Tabuleiro));
    assert(tabuleiro);
    tabuleiro->piece1 = 'X';
    tabuleiro->piece2 = '0';
    tabuleiro->empty = '-';

    tabuleiro->vec = malloc(TAM_TABULEIRO * sizeof(char *));
    assert(tabuleiro->vec);

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        tabuleiro->vec[i] = malloc(TAM_TABULEIRO * sizeof(char));
        assert(tabuleiro->vec[i]);

        for (int j = 0; j < TAM_TABULEIRO; j++)
            tabuleiro->vec[i][j] = tabuleiro->empty;
    }

    return tabuleiro;
}

/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 *
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro *tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
        if (tabuleiro->vec[i])
            free(tabuleiro->vec[i]);

    if (tabuleiro->vec)
        free(tabuleiro->vec);
        
    if (tabuleiro)
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
    if (peca == PECA_1)
        tabuleiro->vec[y][x] = tabuleiro->piece1;

    else if (peca == PECA_2)
        tabuleiro->vec[y][x] = tabuleiro->piece2;
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
        return tabuleiro->vec[y][x] == tabuleiro->piece1;

    if (peca == PECA_2)
        return tabuleiro->vec[y][x] == tabuleiro->piece2;

    return 0;
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
    return tabuleiro->vec[y][x] == tabuleiro->empty;
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
            printf("%c", tabuleiro->vec[i][j]);

        printf("\n");
    }
}