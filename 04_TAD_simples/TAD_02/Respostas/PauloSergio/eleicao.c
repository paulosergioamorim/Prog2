#include "eleicao.h"
#include <stdio.h>

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

    scanf("%d", &totalCandidatos);

    for (int i = 0; i < totalCandidatos; i++)
    {
        tCandidato candidato = LeCandidato();

        if (candidato.cargo = 'P')
            eleicao.totalPresidentes++;
        else if (candidato.cargo == 'G')
            eleicao.totalGovernadores++;
    }

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao)
{
    scanf("%d", &eleicao.totalEleitores);

    if (eleicao.totalPresidentes > 3 ||
        eleicao.totalPresidentes > 3 ||
        eleicao.totalEleitores > 10)
    {
        printf("ELEICAO ANULADA\n");
        return;
    }

    for (int i = 0; i < eleicao.totalEleitores; i++)
        eleicao.eleitores[i] = LeEleitor();

    for (int i = 0; i < eleicao.totalEleitores; i++)
        for (int j = i + 1; j < eleicao.totalEleitores; j++)
        {
            if (!EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j]))
                continue;

            printf("ELEICAO ANULADA\n");
            return;
        }

    for (int i = 0; i < eleicao.totalEleitores; i++)
    {
        int votoP = ObtemVotoPresidente(eleicao.eleitores[i]);
        int votoG = ObtemVotoGovernador(eleicao.eleitores[i]);

        for (int j = 0; j < eleicao.totalPresidentes; j++)
        {
            
        }
    }

    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao)
{
}
