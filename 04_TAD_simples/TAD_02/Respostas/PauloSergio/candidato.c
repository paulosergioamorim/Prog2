#include "candidato.h"
#include <stdio.h>
#include <string.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id)
{
    tCandidato candidato = {"", "", cargo, id, 0};
    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);

    return candidato;
}

tCandidato LeCandidato()
{
    char nome[50] = "";
    char partido[50] = "";
    char cargo = 0;
    int id = 0;

    scanf("%*c");
    scanf("%49[^,], %49[^,], %c, %d", nome, partido, &cargo, &id);

    return CriaCandidato(nome, partido, cargo, id);
}

int VerificaIdCandidato(tCandidato candidato, int id)
{
    return candidato.id == id;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{
    return candidato1.id == candidato2.id;
}

char ObtemCargo(tCandidato candidato)
{
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato)
{
    candidato.votos++;

    return candidato;
}

int ObtemVotos(tCandidato candidato)
{
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos)
{
    return 100 * (float)candidato.votos / totalVotos;
}

void ImprimeCandidato(tCandidato candidato, float percentualVotos)
{
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, ObtemVotos(candidato), percentualVotos);
}
