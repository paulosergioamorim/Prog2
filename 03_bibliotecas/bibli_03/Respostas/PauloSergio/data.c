#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano)
{
    if (mes < 1 || mes > 12 || dia < 1)
        return 0;

    if (mes == 2)
        if (verificaBissexto(ano))
            return 1 <= dia <= 29;
        else
            return 1 <= dia <= 28;

    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 1 <= dia && dia <= 31;
    default:
        return 1 <= dia && dia <= 30;
    }
}

void imprimeMesExtenso(int mes)
{
    char *meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio",
                       "Junho", "Agosto", "Setembro", "Outubro", "Novembro",
                       "Dezembro"};
    printf("%s", meses[mes - 1]);
}

void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%d ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

int verificaBissexto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}

int numeroDiasMes(int mes, int ano)
{
    if (mes < 1 || mes > 12)
        return 0;

    if (mes == 2)
        return verificaBissexto(ano) ? 29 : 28;

    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    default:
        return 30;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (ano1 > ano2)
        return 1;

    if (ano1 < ano2)
        return -1;

    if (mes1 > mes2)
        return 1;

    if (mes1 < mes2)
        return -1;

    if (dia1 > dia2)
        return 1;

    if (dia1 < dia2)
        return -1;

    return 0;
}

int calculaDiasAteMes(int mes, int ano)
{
    int dias = 0;
    int diaAtual = 1;
    int mesAtual = 1;

    for (dias; mesAtual < mes; dias++)
    {
        while (verificaDataValida(diaAtual, mesAtual, ano))
            diaAtual++;

        diaAtual = 1;
        mesAtual++;
    }

    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int dias = 0;
    int mesAtual = 1;

    return 0;
}
