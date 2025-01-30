#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "aluno.h"

#define MAX_NOME 100

struct Aluno
{
    char *nome;
    int matricula;
    int notas[3];
};

/**
 * @brief Cria um novo aluno vazio. Os atributos inteiros devem receber valor -1, e o ponteiro do nome deve apontar para NULL;
 *
 * @return tAluno Retorna uma estrutura tAluno com os dados do aluno criado.
 */
tAluno *CriaAluno()
{
    tAluno *pAluno = malloc(sizeof(tAluno));
    assert(pAluno);

    pAluno->nome = NULL;
    pAluno->matricula = pAluno->notas[0] = pAluno->notas[1] = pAluno->notas[2] = -1;

    return pAluno;
}

/**
 * @brief Função para liberar toda a memória alocada dinamicamente para estrututas do tipo tAluno
 *
 * @param aluno Ponteiro para estrutura do tipo tAluno a ser apagada.
 */
void ApagaAluno(tAluno *aluno)
{
    if (aluno->nome)
        free(aluno->nome);

    if (aluno)
        free(aluno);
}

/**
 * @brief Lê os dados de um aluno.
 *
 * @param Ponteiro para aluno (alocado dinamicamente), cujos dados serão preenchidos nessa função
 */
void LeAluno(tAluno *aluno)
{
    char nome[MAX_NOME] = "";
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    aluno->nome = malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(aluno->nome, nome);

    scanf("%d%*c", &aluno->matricula);
    scanf("%d %d %d%*c", &aluno->notas[0], &aluno->notas[1], &aluno->notas[2]);
}

/**
 * @brief Compara as matrículas de dois alunos.
 *
 * @param aluno1 Ponteiro para o primeiro aluno a ser comparado.
 * @param aluno2 Ponteiro para o segundo aluno a ser comparado.
 * @return int Retorna 1 se a matrícula do aluno1 é maior que a do aluno2, -1 se a matrícula do aluno1 é menor que a do aluno2 e 0 se as matrículas são iguais.
 */
int ComparaMatricula(tAluno *aluno1, tAluno *aluno2)
{
    if (aluno1->matricula > aluno2->matricula)
        return 1;

    if (aluno1->matricula < aluno2->matricula)
        return -1;

    return 0;
}

/**
 * @brief Calcula a média das notas de um aluno.
 *
 * @param aluno Ponteiro para aluno a ter a média calculada.
 * @return int Retorna a média das notas do aluno.
 */
int CalculaMediaAluno(tAluno *aluno)
{
    int sum = 0;

    for (int i = 0; i < 3; i++)
        sum += aluno->notas[i];

    return sum / 3;
}

/**
 * @brief Verifica se um aluno foi aprovado ou reprovado.
 *
 * @param aluno Ponteiro para aluno a ser verificado.
 * @return int Retorna 1 se o aluno foi aprovado e 0 se foi reprovado.
 */
int VerificaAprovacao(tAluno *aluno)
{
    return CalculaMediaAluno(aluno) >= 7;
}

/**
 * @brief Imprime os dados de um aluno.
 *
 * @param aluno Ponteiro para aluno a ser impresso.
 */
void ImprimeAluno(tAluno *aluno)
{
    if (aluno && aluno->nome)
        printf("%s\n", aluno->nome);
}