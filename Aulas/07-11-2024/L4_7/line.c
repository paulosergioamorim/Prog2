#include <stdio.h>
#include "point.h"
#include "line.h"

void imprime_quadrante(tReta reta)
{
    tPonto pi = get_pi(reta);
    tPonto pf = get_pf(reta);
    int quadrantePi = get_quadrante(pi);
    int quadrantePf = get_quadrante(pf);

    if (quadrantePi == quadrantePf && quadrantePi != 0 && quadrantePf != 0)
        printf("MESMO\n");
    else
        printf("DIFERENTE\n");
}

tReta cria_reta(tPonto pi, tPonto pf)
{
    tReta reta = {pi, pf};
    return reta;
}

tReta le_reta()
{
    tPonto pi = le_ponto();
    tPonto pf = le_ponto();
    return cria_reta(pi, pf);
}

tPonto get_pi(tReta reta)
{
    return reta.pi;
}

tPonto get_pf(tReta reta)
{
    return reta.pf;
}
