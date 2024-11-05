#include <stdio.h>
#include "produto.h"

int main()
{
    int n = 0;
    scanf("%d", &n);

    tProduto maiorProduto;
    tProduto menorProduto;

    for (int i = 0; i < n; i++)
    {
        tProduto produto = LeProduto();

        if (i == 0)
        {
            maiorProduto = produto;
            menorProduto = produto;   
        }

        if (!TemProdutoEmEstoque(produto))
        {
            printf("FALTA:");
            ImprimeProduto(produto);
        }

        if (EhProduto1MaiorQ2(produto, maiorProduto))
            maiorProduto = produto;

        if (EhProduto1MenorQ2(produto, menorProduto))
            menorProduto = produto;
    }

    printf("MAIOR:");
    ImprimeProduto(maiorProduto);
    printf("MENOR:");
    ImprimeProduto(menorProduto);

    return 0;

    return 0;
}