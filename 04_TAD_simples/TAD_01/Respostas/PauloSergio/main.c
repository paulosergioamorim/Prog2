#include "jogo.h"

int main(int argc, char const *argv[])
{
    tJogo jogo = CriaJogo();
    
    do
    {
        ComecaJogo(jogo);
    } while (ContinuaJogo());

    return 0;
}
