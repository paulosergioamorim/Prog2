#include "jogo.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    tJogo *jogo = NULL;

    do
    {
        jogo = CriaJogo();
        ComecaJogo(jogo);
        DestroiJogo(jogo);
    } while (ContinuaJogo());

    return 0;
}
