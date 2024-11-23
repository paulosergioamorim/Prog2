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
    printf("Jogador %d\n", jogador.id);
    tJogada jogada = LeJogada();

    if (!FoiJogadaBemSucedida(jogada))
    {
        printf("Formato inválido!\n");
        return JogaJogador(jogador, tabuleiro);
    }

    int x = ObtemJogadaX(jogada);
    int y = ObtemJogadaY(jogada);

    if (!EhPosicaoValidaTabuleiro(x, y))
    {
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
        return JogaJogador(jogador, tabuleiro);
    }

    if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
    {
        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
        return JogaJogador(jogador, tabuleiro);
    }

    int peca = jogador.id == ID_JOGADOR_1 ? PECA_1 : PECA_2;
    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, peca, x, y);
    printf("Jogada [%d,%d]!\n", x, y);
    ImprimeTabuleiro(tabuleiro);

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    int peca = jogador.id == ID_JOGADOR_1 ? PECA_1 : PECA_2;
    
    if (
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca)
    )
        return 1;
    
    if (
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, peca)
    )
        return 1;
        
    if (
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca)
    )
        return 1;
    
    if (
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca)
    )
        return 1;
    
    if (
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, peca)
    )
        return 1;

    if (
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca)
    )
        return 1;
    
    if (
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca)
    )
        return 1;
    
    if (
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca)
    )
        return 1;

    return 0;
}
