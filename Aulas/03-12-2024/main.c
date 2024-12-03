#include "terrenos.h"
#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d%*c", &n);

    for (int i = 0; i < n; i++)
    {
        char c = 0;
        scanf("%c", &c);

        double area = 0;
        
        if (c == 'C')
        {
            int r = 0;
            scanf("%d", &r);
            Circulo c = criaCirculo(r);
            area = calculaPrecoAreaCirculo(c, PRECO_TERRENO_CIRCULO);
        }
        else if (c == 'R')
        {
            int comp = 0;
            int larg = 0;
            scanf("%d %d", &comp, &larg);
            Retangulo r = criaRetangulo(comp, larg);
            area = calculaPrecoAreaRetangulo(r, PRECO_TERRENO_RETANGULO);
        }
        else if (c == 'T')
        {
            int comp = 0;
            int alt = 0;
            scanf("%d %d", &comp, &alt);
            Triangulo t = criaTriangulo(comp, alt);
            area = calculaPrecoAreaTriangulo(t, PRECO_TERRENO_TRIANGULO);
        }

        printf("Preco: %.2lf\n", area);
        scanf("%*c");
    }

    return 0;
}