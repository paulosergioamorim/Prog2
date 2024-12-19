#include "utils_char.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int tamanho = 0;
    scanf("%d%*c", &tamanho);
    char *vec = CriaVetor(tamanho);
    ImprimeString(vec, tamanho);
    LeVetor(vec, tamanho);
    ImprimeString(vec, tamanho);
    LiberaVetor(vec);

    return 0;
}
