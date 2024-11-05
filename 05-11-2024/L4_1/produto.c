#include <stdio.h>
#include "produto.h"

tProduto LeProduto()
{
    tProduto produto;
    scanf("%d;%f;%d", &produto.codigo, &produto.preco, &produto.quantidade);

    return produto;
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2)
{
    return p1.preco > p2.preco;
}

int EhProduto1MenorQ2(tProduto p1, tProduto p2)
{
    return EhProduto1MaiorQ2(p2, p1);
}

int TemProdutoEmEstoque(tProduto p)
{
    return p.quantidade > 0;
}

void ImprimeProduto(tProduto p)
{
    printf("COD:%d, PRE:%.2f; QTD: %d\n", p.codigo, p.preco, p.quantidade);
}
