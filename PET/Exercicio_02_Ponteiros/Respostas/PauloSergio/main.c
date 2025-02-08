#include "prisao.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char nome[45] = "";
    int nCelas = 0;
    int capacidadeCelas = 0;
    scanf("%[^\n]%*c", nome);
    scanf("%d %d%*c", &nCelas, &capacidadeCelas);
    tPrisao prisao = criaPrisao(nome, nCelas, capacidadeCelas);
    executaPrisao(&prisao);

    return 0;
}
