#include "locadora.h"
#include "filme.h"
#include <stdio.h>
#include <stdlib.h>

int compararFilmesLocadora(const void *pFilme1, const void *pFilme2);

/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora()
{
    tLocadora locadora = {{}, 0, 0};

    return locadora;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado(tLocadora locadora, int codigo)
{
    for (int i = 0; i < locadora.numFilmes; i++)
        if (ehMesmoCodigoFilme(locadora.filme[i], codigo))
            return 1;

    return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
 */
tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme)
{
    locadora.filme[locadora.numFilmes] = filme;
    locadora.numFilmes++;

    return locadora;
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora(tLocadora locadora)
{
    char codigo = 0;

    while (1)
    {
        scanf("%c", &codigo);

        if (codigo == '#')
        {
            scanf("%*c");
            break;
        }

        scanf("%*c");
        tFilme filme = leFilme(codigo - '0');

        locadora = cadastrarFilmeLocadora(locadora, filme);
    }

    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora(tLocadora locadora, int *codigos, int quantidadeCodigos)
{
    for (int i = 0; i < quantidadeCodigos; i++)
    {
        if (verificarFilmeCadastrado(locadora, codigos[i]))
        {
            printf("Filme  %d  nao  cadastrado\n", codigos[i]);
            continue;
        }

        for (int j = 0; j < locadora.numFilmes; j++)
        {
            if (!ehMesmoCodigoFilme(locadora.filme[j], codigos[i]))
                continue;

            if (obterQtdAlugadaFilme(locadora.filme[j]) < obterQtdEstoqueFilme(locadora.filme[j]))
            {
                locadora.filme[j] = alugarFilme(locadora.filme[j]);
                continue;
            }

            printf("Filme %d  - ", obterCodigoFilme(locadora.filme[j]));
            imprimirNomeFilme(locadora.filme[j]);
            printf(" nao  disponivel  no  estoque.  Volte  mais tarde.\n");
        }
    }

    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora(tLocadora locadora)
{
    int codigos[MAX_FILMES];
    int quantidadeCodigos = 0;

    char codigo = 0;

    while (1)
    {
        scanf("%c%*c", &codigo);

        if (codigo == '#')
            break;

        codigos[quantidadeCodigos] = codigo - '0';
        quantidadeCodigos++;
    }

    return alugarFilmesLocadora(locadora, codigos, quantidadeCodigos);
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora(tLocadora locadora, int *codigos, int quantidadeCodigos)
{
    for (int i = 0; i < quantidadeCodigos; i++)
        for (int j = 0; j < locadora.numFilmes; j++)
            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]))
                locadora.filme[j] = devolverFilme(locadora.filme[j]);

    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora(tLocadora locadora)
{
    int codigos[MAX_FILMES];
    int quantidadeCodigos = 0;

    char codigo = 0;

    while (1)
    {
        scanf("%c%*c", &codigo);

        if (codigo == '#')
            break;

        codigos[quantidadeCodigos] = codigo - '0';
        quantidadeCodigos++;
    }

    return devolverFilmesLocadora(locadora, codigos, quantidadeCodigos);
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora(tLocadora locadora)
{
    qsort(locadora.filme, locadora.numFilmes, sizeof(tLocadora), compararFilmesLocadora);

    return locadora;
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora(tLocadora locadora)
{
    for (int i = 0; i < locadora.numFilmes; i++)
    {
        printf("%d - ", obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
    }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora(tLocadora locadora)
{
    printf("Lucro total R$%d\n", locadora.lucro);
}

int compararFilmesLocadora(const void *pFilme1, const void *pFilme2)
{
    tFilme filme1 = *(tFilme *)pFilme1;
    tFilme filme2 = *(tFilme *)pFilme2;

    return compararNomesFilmes(filme1, filme2);
}