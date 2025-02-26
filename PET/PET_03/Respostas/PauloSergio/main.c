#include "conta.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_MEMSIZE_CONTAS 10

void AdicionaConta(Conta **contas, int *contasCount, int *contasMemsize, Conta *conta);

void ImprimeRelatorioConta(Conta *conta);

void ImprimeExtratoConta(Conta *conta, int limit);

int main() {
    Conta **contas = malloc(DEFAULT_MEMSIZE_CONTAS * sizeof(Conta *));
    int contasCount = 0;
    int contasMemsize = DEFAULT_MEMSIZE_CONTAS;
    int option = 0;

    while (1) {
        scanf("%d%*c", &option);

        if (option == 0)
            break;

        if (option == 1) {
            int nConta = 0;
            float valor = 0;
            scanf("%d %f%*c", &nConta, &valor);

            Conta *conta = BuscaConta(contas, contasCount, nConta);

            if (!conta)
                continue;

            Saque(conta, valor);

            continue;
        }

        if (option == 2) {
            int nConta = 0;
            float valor = 0;
            scanf("%d %f%*c", &nConta, &valor);

            Conta *conta = BuscaConta(contas, contasCount, nConta);

            if (!conta)
                continue;

            Deposito(conta, valor);
            continue;
        }

        if (option == 3) {
            int nContaOrigem = 0;
            int nContaDestino = 0;
            float valor = 0;
            scanf("%d %d %f%*c", &nContaOrigem, &nContaDestino, &valor);

            Conta *contaOrigem = BuscaConta(contas, contasCount, nContaOrigem);
            Conta *contaDestino = BuscaConta(contas, contasCount, nContaDestino);

            if (!contaOrigem || !contaDestino)
                continue;

            Transferencia(contaOrigem, contaDestino, valor);
            
            continue;
        }

        if (option == 4) {
            char nome[100] = "";
            int cpf = 0;
            int nConta = 0;
            scanf("%s %d %d%*c", nome, &cpf, &nConta);

            Usuario *usuario = CriaUsuario(nome, cpf);
            Conta *conta = CriaConta(usuario, nConta);

            AdicionaConta(contas, &contasCount, &contasMemsize, conta);
        }

        if (option == 5) {
            printf("===| Imprimindo Relatorio |===\n");

            for (int i = 0; i < contasCount; i++)
                ImprimeRelatorioConta(contas[i]);
        }

        if (option == 6) {
            int nConta = 0;
            int limit = 0;
            
            scanf("%d %d%*c", &nConta, &limit);
            
            Conta *conta = BuscaConta(contas, contasCount, nConta);
            
            printf("===| Imprimindo Extrato |===\n");
            
            ImprimeExtratoConta(conta, limit);
        }
    }

    for (int i = 0; i < contasCount; i++) {
        DestroiUsuario(RecuperaUsuario(contas[i]));
        DestroiConta(contas[i]);
    }

    free(contas);

    return 0;
}

void AdicionaConta(Conta **contas, int *contasCount, int *contasMemsize, Conta *conta)
{
    if (*contasCount + 1 == *contasMemsize) {
        *contasMemsize *= 2;
        contas = realloc(contas, *contasMemsize * sizeof(Conta *));
    }

    contas[*contasCount] = conta;
    (*contasCount)++;
}

void ImprimeRelatorioConta(Conta *conta)
{
/*
Conta: 2
Saldo: R$ 120.00
Nome: matheus
CPF: 444555666
*/
    Usuario *usuario = RecuperaUsuario(conta);
    printf("Conta: %d\n", RecuperaNConta(conta));
    printf("Saldo: R$ %.2f\n", RecuperaSaldo(conta));
    printf("Nome: %s\n", RecuperaNomeUsuario(usuario));
    printf("CPF: %d\n\n", RecuperaCpfUsuario(usuario));
}

void ImprimeExtratoConta(Conta *conta, int limit)
{
    ImprimeRelatorioConta(conta);

    float *movimentacoes = RecuperaMovimentacoes(conta);
    int qtdMovimentacoes = RecuperaQtdMovimentacoes(conta);
    
    limit = (limit > qtdMovimentacoes) ? qtdMovimentacoes : limit;
    printf("Ultimas %d transações\n", limit);
    
    for (int i = qtdMovimentacoes - 1; i >= qtdMovimentacoes - limit; i--)
        printf("%.2f\n", movimentacoes[i]);

    printf("\n");
}
