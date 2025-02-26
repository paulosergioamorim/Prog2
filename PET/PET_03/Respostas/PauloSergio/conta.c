#include "conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TAM_INICIAL_MOVIMENTACOES 10

/**
 * @brief Cria uma nova conta.
 * @param usuario usuario da conta.
 * @param nConta numero da conta.
 * @return Conta criada.
 */
Conta* CriaConta(Usuario* usuario, int nConta){
    Conta *conta = malloc(sizeof(Conta));
    assert(conta);

    conta->usuario = usuario;
    conta->nConta = nConta;
    conta->saldo = 0;
    conta->movimentacoes = malloc(100 * sizeof(float));
    conta->qtdMovimentacoes = 0;
    
    return conta;
}

/**
 * @brief Busca uma conta.
 * @param contas lista de contas.
 * @param qtdContas numero de contas na lista.
 * @param nConta numero da conta a ser procurada.
 * @return Conta buscada, NULL se nao existir.
 */
Conta* BuscaConta(Conta** contas, int qtdContas, int nConta) {
    for (int i = 0; i < qtdContas; i++)
        if (contas[i]->nConta == nConta)
            return contas[i];

    return NULL;
}

/**
 * @brief Retorna o usuario de uma conta.
 * @param conta uma conta.
 * @return Usuario da conta.
 */
Usuario* RecuperaUsuario(Conta* conta) {
    return conta->usuario;
}

/**
 * @brief Retorna o numero de uma conta.
 * @param conta uma conta.
 * @return Numero da conta.
 */
int RecuperaNConta(Conta* conta) {
    return conta->nConta;
}

/**
 * @brief Retorna a quantidade de movimentacoes de uma conta de uma conta.
 * @param conta uma conta.
 * @return Quantidade de movimentacoes da conta.
 */
int RecuperaQtdMovimentacoes(Conta* conta) {
    return conta->qtdMovimentacoes;
}

/**
 * @brief Retorna o saldo de uma conta.
 * @param conta uma conta.
 * @return saldo da conta.
 */
float RecuperaSaldo(Conta* conta) {
    return conta->saldo;
}

/**
 * @brief Realiza o saque em uma conta.
 * @param conta conta que ocorre a operacao.
 * @param valor valor do saque realizado.
 * @return valor do saque realizado, 0 se nao foi possivel realizar.
 */
float Saque(Conta* conta, float valor) {
    if (conta->saldo < valor)
        return 0;

    conta->saldo -= valor;
    conta->movimentacoes[conta->qtdMovimentacoes] = -valor;
    conta->qtdMovimentacoes++;

    return valor;
}

/**
 * @brief Tranfere um valor deuma conta para outra.
 * @param contaOri conta origem da transferencia.
 * @param contaDes conta destino da transferencia.
 * @param valor valor da tranferencia realizada.
 * @return valor da tranferencia realizada, 0 se nao for possivel.
 */
float Transferencia(Conta* contaOri, Conta* contaDes, float valor) {
    float saque = 0;

    if ((saque = Saque(contaOri, valor)) == 0)
        return 0;

    Deposito(contaDes, valor);

    return saque;
}


/**
 * @brief Retorna o historico de movimentacos da conta.
 * @param conta uma conta.
 * @return as movimentacoes da conta.
 */
float* RecuperaMovimentacoes(Conta* conta){
    return conta->movimentacoes;
}

/**
 * @brief Realiza o deposito em uma conta.
 * @param conta conta que ocorre a operacao.
 * @param valor valor do deposito realizado.
 * @return valor do saque realizado, 0 se nao foi possivel realizar.
 */
void Deposito(Conta* conta, float valor) {
    conta->saldo += valor;
    conta->movimentacoes[conta->qtdMovimentacoes] = valor;
    conta->qtdMovimentacoes++;
}

/**
 * @brief Destroi uma conta.
 * @param conta uma conta.
 */
void DestroiConta(Conta* conta) {
    free(conta->movimentacoes);
    free(conta);
}
