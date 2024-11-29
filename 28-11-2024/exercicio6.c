#include <stdio.h>
#include <stdlib.h>

void LeDadosParaVetor(int *vet, int tam);
void OrdeneCrescente(int *vet, int tam);
void ImprimeDadosDoVetor(int *vet, int tam);

int main(int argc, char const *argv[])
{
    int casos = 0;
    scanf("%d", &casos);

    while (casos)
    {
        int tam = 0;
        scanf("%d", &tam);
        int vet[tam];

        LeDadosParaVetor(vet, tam);
        OrdeneCrescente(vet, tam);
        ImprimeDadosDoVetor(vet, tam);

        casos--;
    }

    return 0;
}

void LeDadosParaVetor(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
        scanf("%d", &vet[i]);
}

void OrdeneCrescente(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
        for (int j = i + 1; j < tam; j++)
        {
            if (vet[i] <= vet[j])
                continue;

            int c = vet[i];
            vet[i] = vet[j];
            vet[j] = c;
        }
}

void ImprimeDadosDoVetor(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
        printf("%d ", vet[i]);

    printf("\n");
}
