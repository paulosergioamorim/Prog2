#include "jogador.h"
#include "jogada.h"
#include <stdio.h>

tJogador CriaJogador(int idJogador)
{
    tJogador jogador = {idJogador};
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada jogada = LeJogada();

    if (!FoiJogadaBemSucedida(jogada))
    {
        printf("Posicao invalida (FORA DO TABULEIRO)!\n");
        return JogaJogador(jogador, tabuleiro);
    }

    int x = ObtemJogadaX(jogada);
    int y = ObtemJogadaY(jogada);

    if (!EhPosicaoValidaTabuleiro(x, y))
    {
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", TAM_TABULEIRO, TAM_TABULEIRO);
        return JogaJogador(jogador, tabuleiro);
    }

    if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
    {
        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
        return JogaJogador(jogador, tabuleiro);
    }

    int peca = jogador.id == ID_JOGADOR_1 ? PECA_1 : PECA_2;
    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, peca, x, y);
    printf("JOGADA [%d,%d]!\n", x, y);
    ImprimeTabuleiro(tabuleiro);

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    int peca = jogador.id == ID_JOGADOR_1 ? PECA_1 : PECA_2;
    int venceu = 1;

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, i, peca))
            continue;

        venceu = 0;
        break;
    }

    if (venceu)
        return 1;

    venceu = 1;
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, TAM_TABULEIRO - (i + 1), peca))
            continue;

        venceu = 0;
        break;
    }

    if (venceu)
        return 1;

    venceu = 1;
    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, peca))
                continue;

            venceu = 0;
            break;
        }

    if (venceu)
        return 1;

    venceu = 1;
    for (int j = 0; j < TAM_TABULEIRO; j++)
        for (int i = 0; i < TAM_TABULEIRO; i++)
        {
            if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, peca))
                continue;

            venceu = 0;
            break;
        }

    return venceu;
}
