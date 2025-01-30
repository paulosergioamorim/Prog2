#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(int argc, char const *argv[])
{
    int n = 0;
    scanf("%d%*c", &n);
    tAluno **alunos = malloc(n * sizeof(tAluno *));

    for (int i = 0; i < n; i++)
    {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (ComparaMatricula(alunos[i], alunos[j]) == 1)
            {
                tAluno *copia = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = copia;
            }

    for (int i = 0; i < n; i++)
        if (VerificaAprovacao(alunos[i]))
            ImprimeAluno(alunos[i]);

    for (int i = 0; i < n; i++)
        ApagaAluno(alunos[i]);

    free(alunos);

    return 0;
}
