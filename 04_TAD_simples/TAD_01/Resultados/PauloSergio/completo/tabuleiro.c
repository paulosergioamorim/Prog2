#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro()
{
    tTabuleiro tabuleiro;
    tabuleiro.pecaVazio = '-';
    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';

    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y)
{
    tabuleiro.posicoes[x][y] = peca == PECA_1 ? tabuleiro.peca1 : tabuleiro.peca2;
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
            if (EstaLivrePosicaoTabuleiro(tabuleiro, i, j))
                return 1;

    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca)
{
    if (peca == PECA_1)
        return tabuleiro.posicoes[x][y] == tabuleiro.peca1;

    return tabuleiro.posicoes[x][y] == tabuleiro.peca2;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y)
{
    return tabuleiro.posicoes[x][y] == tabuleiro.pecaVazio;
}

int EhPosicaoValidaTabuleiro(int x, int y)
{
    return 0 <= x && x <= TAM_TABULEIRO - 1 && 0 <= y && y <= TAM_TABULEIRO - 1;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro)
{
    for (int j = 0; j < TAM_TABULEIRO; j++)
    {
        printf("\t");
        for (int i = 0; i < TAM_TABULEIRO; i++)
            printf("%c", tabuleiro.posicoes[i][j]);
        printf("\n");
    }
}
