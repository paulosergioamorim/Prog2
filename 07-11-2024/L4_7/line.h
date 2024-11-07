#ifndef _LINE_
#define _LINE_

typedef struct
{
    tPonto pi;
    tPonto pf;
} tReta;

tPonto get_pi(tReta reta);
tPonto get_pf(tReta reta);
tReta cria_reta(tPonto pi, tPonto pf);
tReta le_reta();
void imprime_quadrante(tReta reta);

#endif