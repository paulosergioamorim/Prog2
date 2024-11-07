#include <stdio.h>
#include "point.h"
#include "line.h"

int main(int argc, char const *argv[])
{
    int i = 0;
    scanf("%d", &i);

    for (i; i > 0; i--) {
        tReta reta = le_reta();
        imprime_quadrante(reta);
    }

    return 0;
}
