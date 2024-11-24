#include "jogo.h"
#include <stdio.h>

tJogo CriaJogo()
{
    tJogo jogo;

    return jogo;
}

void ComecaJogo(tJogo jogo)
{
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    jogo.tabuleiro = CriaTabuleiro();

    for (int i = ID_JOGADOR_1;
         !AcabouJogo(jogo);
         i = i == ID_JOGADOR_1 ? ID_JOGADOR_2 : ID_JOGADOR_1)
    {
        jogo.tabuleiro = JogaJogador(i == ID_JOGADOR_1 ? jogo.jogador1 : jogo.jogador2, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);

        if (VenceuJogador(i == ID_JOGADOR_1 ? jogo.jogador1 : jogo.jogador2, jogo.tabuleiro))
        {
            printf("JOGADOR %d Venceu!\n", i);
            printf("Jogar novamente? (s,n)\n");
            return;
        }
    }

    printf("Jogar novamente? (s,n)\n");
    printf("Sem vencedor!\n");
}

int AcabouJogo(tJogo jogo)
{
    return !TemPosicaoLivreTabuleiro(jogo.tabuleiro);
}

int ContinuaJogo()
{
    char c = 0;

    while (c != 's' && c != 'n')
        scanf("%c%*c", &c);

    if (c == 's')
        return 1;

    else if (c == 'n')
        return 0;
}
