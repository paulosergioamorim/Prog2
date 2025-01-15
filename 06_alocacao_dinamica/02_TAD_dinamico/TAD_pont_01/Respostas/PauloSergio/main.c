#include <stdlib.h>
#include "jogo.h"

int main(int argc, char const *argv[])
{
    tJogo *pJogo = NULL;
    
    do
    {
        pJogo = CriaJogo();
        ComecaJogo(pJogo);
        DestroiJogo(pJogo);
    } while (ContinuaJogo());

    return 0;
}
