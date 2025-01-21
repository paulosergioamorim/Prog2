#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"

void nextPlayer(int *pPlayerId);

struct Jogo
{
    tTabuleiro *tabuleiro;
    tJogador *jogador1;
    tJogador *jogador2;
};

/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo *CriaJogo()
{
    tJogo *jogo = malloc(sizeof(struct Jogo));
    assert(jogo);

    return jogo;
}

/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 *
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo *jogo)
{
    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo->jogador2 = CriaJogador(ID_JOGADOR_2);

    for (int i = ID_JOGADOR_1; !AcabouJogo(jogo); nextPlayer(&i))
    {
        JogaJogador(i == ID_JOGADOR_1 ? jogo->jogador1 : jogo->jogador2, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);

        if (VenceuJogador(i == ID_JOGADOR_1 ? jogo->jogador1 : jogo->jogador2, jogo->tabuleiro))
        {
            printf("JOGADOR %d Venceu!\n", i);
            return;
        }
    }

    printf("Sem vencedor!\n");
}

/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 *
 * @param jogo o jogo atual.
 *
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo *jogo)
{
    return !TemPosicaoLivreTabuleiro(jogo->tabuleiro);
}

/**
 * Verifica se o usuário deseja jogar novamente.
 *
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    char option = 0;
    printf("Jogar novamente? (s,n)\n");

    scanf("%*[^a-z]");
    scanf("%c", &option);

    if (option == 's')
        return 1;

    return 0;
}

/**
 * Libera a memória de uma estrutura do tipo tJogo.
 *
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo *jogo)
{
    DestroiTabuleiro(jogo->tabuleiro);
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    free(jogo);
}

void nextPlayer(int *pPlayerId)
{
    *pPlayerId = *pPlayerId == ID_JOGADOR_1 ? ID_JOGADOR_2 : ID_JOGADOR_1;
}
