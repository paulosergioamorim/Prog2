#include <stdio.h>
#include "product.h"
#include "store.h"

int main(int argc, char const *argv[])
{
    tStore loja = abreLoja();
    char opcao = '\0';
    int id = 0;
    int quantidade = 0;
    float desconto = 0;
    fflush(stdin);

    while (1)
    {
        printf("Menu:\n");
        printf(" C - Cadastrar Produto\n");
        printf(" E - Estocar Produto\n");
        printf(" V - Vender Produto\n");
        printf(" D - Atualizar desconto de Produto\n");
        printf(" I - Imprimir Produtos\n");
        printf(" R - Imprimir Relatorio de Vendas\n");
        printf(" F - Finalizar Programa\n");

        scanf("%c%*c", &opcao);

        switch (opcao)
        {
        case 'F':
            return 0;
        case 'C':
            tProduct produto = leProduto();
            loja = adicionaProduto(loja, produto);
            break;
        case 'E':
        case 'V':
            printf("Digite o id do Produto: ");
            scanf("%d%*c", &id);
            printf("Digite o numero de unidades: ");
            scanf("%d%*c", &quantidade);

            if (opcao == 'E')
            {
                loja = aumentaEstoqueLoja(loja, id, quantidade);
                break;
            }

            loja = vendeProdutoLoja(loja, id, quantidade);
            break;
        case 'D':
            printf("Digite o id do Produto: ");
            scanf("%d%*c", &id);
            printf("Digite o novo desconto: ");
            scanf("%f%*c", &desconto);
            loja = atualizaDescontoLoja(loja, id, desconto);
            break;
        case 'I':
            imprimeProdutosLoja(loja);
            break;
        case 'R':
            imprimeRelatorio(loja);
            break;
        }

        printf("\n");
    }

    return 0;
}
