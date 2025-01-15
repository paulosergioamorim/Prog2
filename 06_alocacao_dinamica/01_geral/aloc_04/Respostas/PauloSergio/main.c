#include "utils_char2.h"

int main(int argc, char const *argv[])
{
    int tamanhoAtual = TAM_PADRAO;
    char *vetor = CriaVetorTamPadrao();

    vetor = LeVetor(vetor, &tamanhoAtual);

    ImprimeString(vetor);
    LiberaVetor(vetor);

    return 0;
}
