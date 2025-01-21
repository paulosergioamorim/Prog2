#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "jogador.h"
#include "jogada.h"
#include "tabuleiro.h"

struct Jogador
{
    int id;
};

/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 *
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador *CriaJogador(int idJogador)
{
    tJogador *jogador = malloc(sizeof(struct Jogador));
    assert(jogador);
    jogador->id = idJogador;

    return jogador;
}

/**
 * Libera a memória de uma estrutura do tipo tJogador.
 *
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador *jogador)
{
    if (jogador)
        free(jogador);
}

/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 *
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro)
{
    int x = 0;
    int y = 0;
    tJogada *jogada = CriaJogada();

    while (1)
    {
        printf("Jogador %d\n", jogador->id);
        LeJogada(jogada);

        if (!FoiJogadaBemSucedida(jogada))
        {
            printf("Formato inválido!\n");
            continue;
        }

        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);

        if (!EhPosicaoValidaTabuleiro(x, y))
        {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
            continue;
        }

        if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
        {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
            continue;
        }

        break;
    }

    int peca = jogador->id == ID_JOGADOR_1 ? PECA_1 : PECA_2;
    MarcaPosicaoTabuleiro(tabuleiro, peca, x, y);
    printf("Jogada [%d,%d]!\n", x, y);
    DestroiJogada(jogada);
}

/**
 * Verifica se o jogador venceu o jogo.
 *
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro)
{
    int venceu = 0;
    int peca = jogador->id == ID_JOGADOR_1 ? PECA_1 : PECA_2;

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        venceu = 1;

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, peca))
            {
                venceu = 0;
                break;
            }
        }

        if (venceu)
            return 1;
    }

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        venceu = 1;

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, jogador->id))
            {
                venceu = 0;
                break;
            }
        }

        if (venceu)
            return 1;
    }

    venceu = 1;

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, i, jogador->id))
        {
            venceu = 0;
            break;
        }
    }

    if (venceu)
        return 1;

    venceu = 1;

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, TAM_TABULEIRO - i - 1, jogador->id))
        {
            venceu = 0;
            break;
        }
    }

    if (venceu)
        return 1;

    return 0;
}
