#include "eleicao.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    tEleicao eleicao = InicializaEleicao();
    eleicao = RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);

    return 0;
}
