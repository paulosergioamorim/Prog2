#include <stdio.h>

int SomaElementosPares(int *vet, int numElementos);

int main()
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int m = 0;
        scanf("%d", &m);

        int vec[m];

        for (int j = 0; j < m; j++)
            scanf("%d", &vec[j]);

        printf("%d\n", SomaElementosPares(vec, m));
    }

    return 0;
}

int SomaElementosPares(int *vet, int numElementos)
{
    if (numElementos == 0)
        return 0;
    if (*vet % 2 == 0)
        return *vet + SomaElementosPares(vet + 1, numElementos - 1);
    return SomaElementosPares(vet + 1, numElementos - 1);
}
