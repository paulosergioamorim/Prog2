#include <stdio.h>

int ContaOcorrencias(int *vet, int numElementos, int numeroProcurado);

int main(int argc, char const *argv[])
{
    int n = 0;
    int m = 0;
    int x = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &m);
        int numbers[m];

        for (int j = 0; j < m; j++)
            scanf("%d", &numbers[j]);

        int count = ContaOcorrencias(numbers, m, x);
        printf("%d\n", count);
    }

    return 0;
}

int ContaOcorrencias(int *vet, int numElementos, int numeroProcurado)
{
    if (numElementos == 0)
        return 0;

    return (*vet == numeroProcurado) + ContaOcorrencias(vet + 1, numElementos - 1, numeroProcurado);
}
