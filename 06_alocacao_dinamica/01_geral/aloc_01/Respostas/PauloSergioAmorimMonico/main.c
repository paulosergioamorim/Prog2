#include <stdio.h>
#include "utils.h"

int main(int argc, char const *argv[])
{
    int tamanho = 0;
    scanf("%d%*c", &tamanho);

    int *vetor = CriaVetor(tamanho);
    LeVetor(vetor, tamanho);
    float media = CalculaMedia(vetor, tamanho);
    printf("%.2f\n\n", media);
    LiberaVetor(vetor);

    return 0;
}
