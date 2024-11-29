#include "candidato.h"
#include <stdio.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id)
{
    tCandidato candidato = {nome, partido, cargo, id, 0};

    return candidato;
}

tCandidato LeCandidato()
{
    char *nome;
    char *partido;
    char cargo = 0;
    int id = 0;

    scanf("%s, %s, %c, %d", nome, partido, &cargo, &id);

    return CriaCandidato(nome, partido, cargo, id);
}

int VerificaIdCandidato(tCandidato candidato, int id)
{
    return candidato.id == id;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{
    return candidato1.votos == candidato2.votos;
}

char ObtemCargo(tCandidato candidato)
{
    return 0;
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
    printf("%s (%s), %d voto(s), %.2f\n", candidato.nome, candidato.partido, ObtemVotos(candidato), percentualVotos);
}
