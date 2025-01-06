#include <stdio.h>
#include "utils.h"

int main(int argc, char const *argv[])
{
    int l = 0;
    int c = 0;
    fflush(stdin);
    scanf("%d %d%*c", &l, &c);
    int **matriz = CriaMatriz(l, c);
    LeMatriz(matriz, l, c);
    ImprimeMatrizTransposta(matriz, l, c);
    LiberaMatriz(matriz, l);

    return 0;
}
