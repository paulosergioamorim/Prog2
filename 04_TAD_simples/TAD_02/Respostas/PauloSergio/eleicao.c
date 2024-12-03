#include "eleicao.h"
#include <stdio.h>
#include <stdlib.h>

int ComparaCandidatosPorVotos(const void *pCandidatoA, const void *pCandidatoB);

tEleicao InicializaEleicao()
{
    tEleicao eleicao;
    int totalCandidatos = 0;

    eleicao.totalPresidentes = 0;
    eleicao.totalGovernadores = 0;
    eleicao.totalEleitores = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosPresidente = 0;
    eleicao.votosNulosGovernador = 0;

    scanf("%d%*c", &totalCandidatos);

    for (int i = 0; i < totalCandidatos; i++)
    {
        tCandidato candidato = LeCandidato();
        char cargo = ObtemCargo(candidato);

        if (cargo == 'P')
        {
            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
            eleicao.totalPresidentes++;
        }
        else if (cargo == 'G')
        {
            eleicao.governadores[eleicao.totalGovernadores] = candidato;
            eleicao.totalGovernadores++;
        }
    }

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao)
{
    scanf("%d%*c", &eleicao.totalEleitores);

    if (eleicao.totalPresidentes > MAX_CANDIDATOS_POR_CARGO ||
        eleicao.totalPresidentes > MAX_CANDIDATOS_POR_CARGO ||
        eleicao.totalEleitores > MAX_ELEITORES)
    {
        printf("ELEICAO ANULADA\n");
        exit(0);
    }

    for (int i = 0; i < eleicao.totalEleitores; i++)
        eleicao.eleitores[i] = LeEleitor();

    for (int i = 0; i < eleicao.totalEleitores; i++)
        for (int j = i + 1; j < eleicao.totalEleitores; j++)
        {
            if (!EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j]))
                continue;

            printf("ELEICAO ANULADA\n");
            exit(0);
        }

    for (int i = 0; i < eleicao.totalEleitores; i++)
    {
        int votoP = ObtemVotoPresidente(eleicao.eleitores[i]);
        int votoG = ObtemVotoGovernador(eleicao.eleitores[i]);
        int votoPAnulado = 1;
        int votoGAnulado = 1;

        if (votoP == 0)
        {
            eleicao.votosBrancosPresidente++;
            votoPAnulado = 0;
        }
        else
            for (int j = 0; j < eleicao.totalPresidentes; j++)
            {
                tCandidato candidato = eleicao.presidentes[j];

                if (!VerificaIdCandidato(candidato, votoP))
                    continue;

                candidato = IncrementaVotoCandidato(candidato);
                eleicao.presidentes[j] = candidato;
                votoPAnulado = 0;
            }

        if (votoPAnulado)
            eleicao.votosNulosPresidente++;

        if (votoG == 0)
        {
            eleicao.votosBrancosGovernador++;
            votoGAnulado = 0;
        }
        else
            for (int j = 0; j < eleicao.totalGovernadores; j++)
            {
                tCandidato candidato = eleicao.governadores[j];

                if (!VerificaIdCandidato(candidato, votoG))
                    continue;

                candidato = IncrementaVotoCandidato(candidato);
                eleicao.governadores[j] = candidato;
                votoGAnulado = 0;
            }

        if (votoGAnulado)
            eleicao.votosNulosGovernador++;
    }

    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao)
{
    int totalVotosPresidente = 0;
    int totalVotosGovernador = 0;
    int totalVotosNulos = eleicao.votosNulosPresidente + eleicao.votosNulosGovernador;
    int totalVotosBrancos = eleicao.votosBrancosPresidente + eleicao.votosBrancosGovernador;
    int totalVotosInvalidosPresidente = eleicao.votosNulosPresidente + eleicao.votosBrancosPresidente;
    int totalVotosInvalidosGovernador = eleicao.votosNulosGovernador + eleicao.votosBrancosGovernador;

    for (int i = 0; i < eleicao.totalPresidentes; i++)
        totalVotosPresidente += ObtemVotos(eleicao.presidentes[i]);

    for (int i = 0; i < eleicao.totalGovernadores; i++)
        totalVotosGovernador += ObtemVotos(eleicao.governadores[i]);

    totalVotosPresidente += totalVotosInvalidosPresidente;
    totalVotosGovernador += totalVotosInvalidosGovernador;

    qsort(eleicao.presidentes, eleicao.totalPresidentes, sizeof(tCandidato), ComparaCandidatosPorVotos);
    qsort(eleicao.governadores, eleicao.totalGovernadores, sizeof(tCandidato), ComparaCandidatosPorVotos);

    printf("- PRESIDENTE ELEITO: ");

    if (EhMesmoCandidato(eleicao.presidentes[0], eleicao.presidentes[1]))
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    else
    {
        tCandidato vencedor = eleicao.presidentes[0];

        if (ObtemVotos(vencedor) < totalVotosInvalidosPresidente)
            printf("SEM DECISAO\n");
        else
        {
            float percentual = CalculaPercentualVotos(vencedor, totalVotosPresidente);
            ImprimeCandidato(vencedor, percentual);
        }
    }

    printf("- GOVERNADOR ELEITO: ");

    if (EhMesmoCandidato(eleicao.governadores[0], eleicao.governadores[1]))
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    else
    {
        tCandidato vencedor = eleicao.governadores[0];

        if (ObtemVotos(vencedor) < totalVotosInvalidosGovernador)
            printf("SEM DECISAO\n");
        else
        {
            float percentual = CalculaPercentualVotos(vencedor, totalVotosGovernador);
            ImprimeCandidato(vencedor, percentual);
        }
    }

    printf("- NULOS E BRANCOS: %d, %d\n", totalVotosNulos, totalVotosBrancos);
}

int ComparaCandidatosPorVotos(const void *pCandidatoA, const void *pCandidatoB)
{
    tCandidato candidatoA = *(tCandidato *)pCandidatoA;
    tCandidato candidatoB = *(tCandidato *)pCandidatoB;

    int votosA = ObtemVotos(candidatoA);
    int votosB = ObtemVotos(candidatoB);

    return votosA < votosB;
}