#include <stdio.h>
#include <stdlib.h>

int TrocaInteiros(int *n1, int *n2)
{
    if (*n1 <= *n2)
        return 0;

    int c = *n1;
    *n1 = *n2;
    *n2 = c;

    return 1;
}

int main(int argc, char const *argv[])
{
    int n1, n2;

    while (scanf("%d %d", &n1, &n2) == 2)
    {
        if (TrocaInteiros(&n1, &n2))
            printf("TROCADO: %d %d\n", n1, n2);
        else
            printf("ORIGINAL: %d %d\n", n1, n2);
    }

    return 0;
}
