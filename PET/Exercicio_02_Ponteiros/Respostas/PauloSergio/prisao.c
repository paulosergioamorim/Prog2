#include "prisao.h"
#include "cela.h"
#include <stdio.h>
#include <string.h>

int capacidadeTotalPrisao(tPrisao prisao);

/**
 * @brief Construtor do tipo prisão
 * @param nome Nome da prisão
 * @param nCelas Número de celas ocupadas
 * @param capacidadeCelas Número total de celas
 */

tPrisao criaPrisao(char *nome, int nCelas, int capacidadeCelas)
{
    tPrisao prisao;
    strcpy(prisao.nome, nome);
    prisao.nCelas = nCelas;
    prisao.capacidadeCelas = capacidadeCelas;
    prisao.dia = 1;

    for (int i = 0; i < prisao.nCelas; i++)
        prisao.celas[i] = criaCela(prisao.capacidadeCelas);

    return prisao;
}

/**
 * @brief Contém o loop do programa que deve imprimir o menu e selecionar opção
 */
void executaPrisao(tPrisao *prisao)
{
    char option = '\0';

    while (1)
    {
        /*
        Menu:
 I - Inserir detento
 P - Passar o dia
 F - Registrar fuga de cela
 E - Encerrar programa
 */

        imprimeDiaEMenuPrisao(prisao);

        scanf("%c%*c", &option);

        switch (option)
        {
        case 'E':
            return finalizaPrograma(prisao);
        case 'P':
            passaDiaPrisao(prisao);
            break;
        case 'I':
            inserePrisioneiroPrisao(prisao);

            if (obtemNumeroPrisioneirosPrisao(prisao) == capacidadeTotalPrisao(*prisao))
                return rebeliaoGeralPrisao(prisao);

            break;
        case 'F':
            registraFugaCelaPrisao(prisao);
            break;
        default:
            break;
        }
    }
}

/**
 * @brief Imprime o menu
 */
void imprimeDiaEMenuPrisao(tPrisao *prisao)
{
    printf("Dia %d na prisao de %s\n\n", prisao->dia, prisao->nome);
    printf("Menu:\n");
    printf("I - Inserir detento\n");
    printf("P - Passar o dia\n");
    printf("F - Registrar fuga de cela\n");
    printf("E - Encerrar programa\n");
}

/**
 * @brief Faz a leitura e adiciona o prisioneiro na prisão
 */
void inserePrisioneiroPrisao(tPrisao *prisao)
{
    int pena = 0;
    char nome[MAXTAM_NOME] = "";
    printf("Informe a pena e o nome do prisioneiro:\n");

    scanf("%d %[^\n]%*c", &pena, nome);

    if (pena <= 0)
        return printf("Valor invalido\n");

    tPrisioneiro prisioneiro = criaPrisioneiro(nome, pena);

    for (int i = 0; i < prisao->nCelas; i++)
    {
        if (!possuiVagaCela(&prisao->celas[i]))
            continue;

        inserePrisioneiroCela(&prisao->celas[i], prisioneiro);
        printf("Detento %s foi inserido na cela %d\n", nome, i);
        break;
    }
}
/**
 * @brief Passa o dia em cada uma das celas da prisão
 */
void passaDiaPrisao(tPrisao *prisao)
{
    prisao->dia++;

    for (int i = 0; i < prisao->nCelas; i++)
        passaDiaCela(&prisao->celas[i]);
}

/**
 * @brief Le da entrada padrão o índice da cela no qual ocorreu a fuga
 */
void registraFugaCelaPrisao(tPrisao *prisao)
{
    int i = 0;
    printf("Informe a cela em qual ocorreu a fuga:\n");
    scanf("%d%*c", &i);

    if (!(0 <= i && i < prisao->nCelas))
        return printf("Valor invalido\n");

    fogePrisioneirosCela(&prisao->celas[i]);
}

/**
 * @brief Finaliza o programa, havendo diferença na finalização caso tenha ou nao prisioneiros na prisao
 */
void finalizaPrograma(tPrisao *prisao)
{
    if (obtemNumeroPrisioneirosPrisao(prisao) > 0)
        return printf("Prisioneiros liberados para a finalizacao do programa!!!\n");
    
    printf("Fim do programa.\n");
}
/**
 * @brief Obtém o total de prisioneiros
 */
int obtemNumeroPrisioneirosPrisao(tPrisao *prisao)
{
    int total;

    for (int i = 0; i < prisao->celas; i++)
        total += obtemNumeroPrisioneirosCela(&prisao->celas[i]);

    return total;
}

/**
 * @brief Imprime mensagem de rebelião e realiza fuga de todos os prisioneiros
 */
void rebeliaoGeralPrisao(tPrisao *prisao)
{
    printf("REBELIAO GERAL\n");

    for (int i = 0; i < prisao->nCelas; i++)
        fogePrisioneirosCela(&prisao->celas[i]);

    printf("Fim do programa.\n");
}

int capacidadeTotalPrisao(tPrisao prisao)
{
    return prisao.nCelas * prisao.capacidadeCelas;
}
