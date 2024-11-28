#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int verificaDataValida(int dia, int mes, int ano)
{
    if (mes < 1 || mes > 12 || dia < 1)
        return 0;

    if (mes == 2)
        if (verificaBissexto(ano))
            return 1 <= dia && dia <= 29;
        else
            return 1 <= dia && dia <= 28;

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
                       "Junho", "Julho", "Agosto", "Setembro", "Outubro",
                       "Novembro", "Dezembro"};
    printf("%s", meses[mes - 1]);
}

void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
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

    for (int mesAtual = 1; mesAtual < mes; mesAtual++)
        dias += numeroDiasMes(mesAtual, ano);

    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int dias = 0;
    int comparacao = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);

    if (comparacao == 0)
        return 0;

    if (ano2 > ano1)
        for (ano1; ano1 < ano2; ano1++)
            dias += calculaDiasAteMes(12, ano1) + numeroDiasMes(12, ano1);

    else if (ano1 > ano2)
        for (ano2; ano2 < ano1; ano2++)
            dias += calculaDiasAteMes(12, ano2) + numeroDiasMes(12, ano2);

    dias += abs(calculaDiasAteMes(mes2, ano2) - calculaDiasAteMes(mes1, ano1));
    dias += abs(dia2 - dia1);


    return dias;
}
