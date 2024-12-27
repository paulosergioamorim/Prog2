#include "store.h"
#include <stdio.h>
#include <stdlib.h>

int ordernarPorVendas(const void *pA, const void *pB);

/**
 * @brief Inicia uma struct do tipo tLoja, inicializando seus parâmetros.
 * @return loja inicializada
 */
tStore abreLoja()
{
    tStore loja;
    loja.faturamento = 0;
    loja.nmProdutos = 0;
    loja.nmVendas = 0;

    return loja;
}

/**
 * @brief Adiciona um novo produto à loja.
 * @param loja A loja.
 * @param produto O produto.
 * @return A loja atualizada.
 */
tStore adicionaProduto(tStore loja, tProduct produto)
{
    loja.produtos[loja.nmProdutos] = produto;
    loja.nmProdutos++;

    return loja;
}

/**
 * @brief Varre a loja em busca do produto com o id desejado.
 * Retorna -1 caso não tenha sido encontrado.
 * @param loja A loja.
 * @param id O id do produto procurado.
 * @return O produto.
 */
int buscaProduto(tStore loja, int id)
{
    for (int i = 0; i < loja.nmProdutos; i++)
        if (ehMesmoId(loja.produtos[i], id))
            return i;

    return -1;
}

/**
 * @brief Aumenta o estoque de um produto da loja.
 * @param loja A loja.
 * @param id O id do produto.
 * @param qtd A quantidade a ser adicionada ao estoque do produto.
 * @return A loja com o produto com o estoque atualizado.
 */
tStore aumentaEstoqueLoja(tStore loja, int id, int qtd)
{

    int indexOfProduto = buscaProduto(loja, id);

    if (indexOfProduto == -1)
        return loja;

    tProduct produto = loja.produtos[indexOfProduto];
    loja.produtos[indexOfProduto] = aumentaEstoqueProduto(produto, qtd);

    return loja;
}

/**
 * @brief Realiza a venda de um produto de uma loja.
 * @param loja A loja.
 * @param id O id do produto.
 * @param qtd A quantidade a ser retirada do estoque.
 * @return A loja com o produto com o estoque atualizado.
 */
tStore vendeProdutoLoja(tStore loja, int id, int qtd)
{
    int indexOfProduto = buscaProduto(loja, id);

    if (indexOfProduto == -1)
        return loja;

    tProduct produto = loja.produtos[indexOfProduto];

    produto = vendeProduto(produto, qtd);
    loja.produtos[indexOfProduto] = produto;
    loja.faturamento += obtemPrecoComDesconto(produto) * qtd;
    loja.nmVendas += qtd;

    return loja;
}

/**
 * @brief Atualiza o desconto de um produto de uma loja.
 * @param loja A loja.
 * @param id O id do produto.
 * @param desconto O novo desconto.
 * @return A loja com o produto com o desconto atualizado.
 */
tStore atualizaDescontoLoja(tStore loja, int id, float desconto)
{
    int indexOfProduto = buscaProduto(loja, id);

    if (indexOfProduto == -1)
        return loja;

    tProduct produto = loja.produtos[indexOfProduto];
    loja.produtos[indexOfProduto] = atualizaDesconto(produto, desconto);

    return loja;
}

/**
 * @brief Imprime todos os produtos atuais de uma loja
 * @brief Deve possuir quebra de linha ao final
 * @param loja A loja.
 */
void imprimeProdutosLoja(tStore loja)
{
    for (int i = 0; i < loja.nmProdutos; i++)
        imprimeProduto(loja.produtos[i]);
}

/**
 * @brief Imprime o relatorio de vendas da loja.
 * @param loja A loja.
 */
void imprimeRelatorio(tStore loja)
{

    printf("RELATORIO DE VENDAS ATUALIZADO:\n");
    printf("TOTAL DE VENDAS: %d\n", loja.nmVendas);
    printf("FATURAMENTO: %.2f\n", loja.faturamento);
    printf("PRODUTOS EM ESTOQUE: %d\n", obtemEstoqueLoja(loja));
    imprimeMaisVendido(loja);
}

/**
 * @brief Obtem a quantidade de produtos total da Loja em estoque.
 * @param loja A loja.
 * @return A quantidade de produtos total da Loja em estoque.
 */
int obtemEstoqueLoja(tStore loja)
{
    int totalEstoque = 0;

    for (int i = 0; i < loja.nmProdutos; i++)
        totalEstoque += obtemEstoque(loja.produtos[i]);

    return totalEstoque;
}

/**
 * @brief Imprime o produto mais vendido da loja(em caso de empate no numero de vendas deve ser impresso o produto a mais tempo na loja).
 * @param loja A loja.
 */
void imprimeMaisVendido(tStore loja)
{
    tProduct produtoMaisVendido;
    qsort(loja.produtos, loja.nmProdutos, sizeof(tProduct), ordernarPorVendas);
    produtoMaisVendido = loja.produtos[0];
    printf("PRODUTO MAIS VENDIDO:\n");
    imprimeProduto(produtoMaisVendido);
}

int ordernarPorVendas(const void *pA, const void *pB)
{
    tProduct produtoA = *(tProduct *) pA;
    tProduct produtoB = *(tProduct *) pB;
    int vendasA = obtemVendas(produtoA);
    int vendasB = obtemVendas(produtoB);

    return vendasB > vendasA;
}
