#include "jogo.h"
#include <stdio.h>

tJogo CriaJogo()
{
    tJogo jogo;

    return jogo;
}

void ComecaJogo(tJogo jogo)
{
    jogo.jogador1 = CriaJogador(1);
    jogo.jogador2 = CriaJogador(2);
    jogo.tabuleiro = CriaTabuleiro();

    for (int i = 0; !AcabouJogo(jogo); i++)
        jogo.tabuleiro = JogaJogador(i % 2 == 0 ? jogo.jogador1 : jogo.jogador2, jogo.tabuleiro);

    if (VenceuJogador(jogo.jogador1, jogo.tabuleiro))
        printf("JOGADOR 1 Venceu!\n");

    else if (VenceuJogador(jogo.jogador2, jogo.tabuleiro))
        printf("JOGADOR 2 Venceu!\n");

    else if (!TemPosicaoLivreTabuleiro(jogo.tabuleiro))
        printf("Sem vencedor!\n");

    if (ContinuaJogo())
        ComecaJogo(jogo);
}

int AcabouJogo(tJogo jogo)
{
    return VenceuJogador(jogo.jogador1, jogo.tabuleiro) || VenceuJogador(jogo.jogador2, jogo.tabuleiro) || !TemPosicaoLivreTabuleiro(jogo.tabuleiro);
}

int ContinuaJogo()
{
    char c = 0;
    printf("Jogar novamente? (s,n)\n");

    while (c != 's' && c != 'n')
        scanf("%c%*c", &c);

    if (c == 's')
        return 1;

    else if (c == 'n')
        return 0;
}
