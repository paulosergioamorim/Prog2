#include "data.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int dia1 = 0;
    int mes1 = 0;
    int ano1 = 0;
    int dia2 = 0;
    int mes2 = 0;
    int ano2 = 0;
    scanf("%d/%d/%d\n%d/%d/%d", &dia1, &mes1, &ano1, &dia2, &mes2, &ano2);

    if (!verificaDataValida(dia1, mes1, ano1) || !verificaDataValida(dia2, mes2, ano2))
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return;
    }

    printf("Primeira data: ");
    imprimeDataExtenso(dia1, mes1, ano1);
    printf("Segunda data: ");
    imprimeDataExtenso(dia2, mes2, ano2);

    int comparacao = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
    int diferenca = 0;

    if (comparacao == 1)
    {
        printf("A segunda data eh mais antiga\n");
        diferenca = calculaDiferencaDias(dia2, mes2, ano2, dia1, mes1, ano1);
    }

    else if (comparacao == -1)
    {
        printf("A primeira data eh mais antiga\n");
        diferenca = calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2);
    }

    else
    {
        printf("As datas sao iguais\n");
        return 0;
    }

    printf("A diferenca em dias entre as datas eh: %d dias", diferenca);

    return 0;
}
