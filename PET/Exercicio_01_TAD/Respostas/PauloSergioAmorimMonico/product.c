#include "product.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Lê um novo produto da entrada padrão.
 * @param nome Nome do produto.
 * @param desconto Desconto atual do produto.
 * @param preco Preço integral do produto.
 * @param estoque Quantidade disponível do produto.
 * @param id Identificador de cada produto.
 * @return Produto criado.
 */
tProduct leProduto() {
    char nome[50] = "";
    int id = 0;
    float preco = 0;
    float desconto = 0;
    int estoque = 0;

    scanf("%[^\n]%*c", nome);
    scanf("%d%*c", &id);
    scanf("%f%*c", &preco);
    scanf("%d%*c", &estoque);

    return criaProduto(nome, desconto, preco, estoque, id);
}

/**
 * @brief Cria um novo produto.
 * @param nome Nome do produto.
 * @param desconto Desconto atual do produto.
 * @param preco Preço integral do produto.
 * @param estoque Quantidade disponível do produto.
 * @param id Identificador de cada produto.
 * @return Produto criado.
 */
tProduct criaProduto(char* nome, float desconto, float preco, int estoque, int id) {
    tProduct produto;
    strcpy(produto.nome, nome);
    produto.desconto = desconto;
    produto.preco = preco;
    produto.estoque = estoque;
    produto.id = id;

    return produto;
}

/**
 * @brief Retorna o desconto atual de um produto
 * @param produto O produto.
 * @return O desconto.
*/
float obtemDesconto(tProduct produto) {
    return produto.desconto;
}

/**
 * @brief Retorna o preço de um produto
 * @param produto O produto.
 * @return O preço.
*/
float obtempreco(tProduct produto) {
    return produto.preco;
}

/**
 * @brief Retorna o preço de um produto com o desconto aplicado.
 * @param produto O produto.
 * @return O preço com desconto.
*/
float obtemPrecoComDesconto(tProduct produto) {
    float preco = obtempreco(produto);
    float descontoBruto = preco * obtemDesconto(produto);

    return preco - descontoBruto;
}

/**
 * @brief Retorna o estoque atual de um produto
 * @param produto O produto.
 * @return O estoque.
*/
int obtemEstoque(tProduct produto) {
    return produto.estoque;
}

/**
 * @brief Retorna as vendas atual de um produto
 * @param produto O produto.
 * @return As vendas.
*/
int obtemVendas(tProduct produto) {
    return produto.vendas;
}

/**
 * @brief Retorna o id de um produto
 * @param produto O produto.
 * @return O id.
*/
int obtemId(tProduct produto) {
    return produto.id;
}

/**
 * @brief Aumenta o estoque de um produto, caso qtd seja válido (>0).
 * @param produto O produto.
 * @param qtd A quantidade a ser adicionada ao estoque do produto.
 * @return Produto com o estoque atualizado.
*/
tProduct aumentaEstoqueProduto(tProduct produto, int qtd) {
    produto.estoque += qtd;

    return produto;
}

/**
 * @brief Realiza a venda de um produto, caso o estoque seja válido (>0) (>=qtd).
 * @param produto O produto.
 * @param qtd A quantidade a ser retirada do estoque.
 * @return Produto com o estoque atualizado.
*/
tProduct vendeProduto(tProduct produto, int qtd) {
    return aumentaEstoqueProduto(produto, -qtd);
}

/**
 * @brief Atualiza o desconto de um produto, caso válido (>=0 && <=1).
 * @param produto O produto.
 * @param desconto O novo desconto.
 * @return Produto com o desconto atualizado.
*/
tProduct atualizaDesconto(tProduct produto, float desconto) {
    if (desconto < 0 || desconto > 1)
        return produto;

    produto.desconto = desconto;

    return produto;
}

/**
 * @brief Checa se um id dado é o igual ao id de um produto
 * @param produto O produto.
 * @param id O id.
 * @return retorna true se o id for o mesmo do produto
*/
bool ehMesmoId(tProduct produto, int id) {
    return produto.id == id;
}

/**
 * @brief Imprime as informações do produto na forma:
 * Produto: <nome>, Preco atual: <preco>, Qtd no estoque: <estoque>, Qtd vendida: <vendas>
 * @brief Deve possuir quebra de linha ao final
 * @param produto O produto a ser impresso.
*/
void imprimeProduto(tProduct produto) {
    printf("Produto: %s, Preco atual: %.2f, Qtd no estoque: %d, Qtd vendida: %d\n", produto.nome, produto.preco, produto.estoque, produto.vendas);
}