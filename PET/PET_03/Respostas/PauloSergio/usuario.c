#include "usuario.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

/**
 * @brief Cria um usuario.
 * @param nome nome do usuario.
 * @param cpf cpf do usuario.
 * @return Usuario criado.
 */
Usuario* CriaUsuario(char* nome, int cpf) {
    Usuario *usuario = malloc(sizeof(Usuario));
    assert(usuario);

    usuario->nome = malloc(100 * sizeof(char));
    strcpy(usuario->nome, nome);
    usuario->cpf = cpf;

    return usuario;
}

/**
 * @brief Retorna o nome de um usuario.
 * @param usuario  um usuario.
 * @return nome do usuario.
 */
char* RecuperaNomeUsuario(Usuario* usuario) {
    return usuario->nome;
}

/**
 * @brief Retorna o cpf de um usuario.
 * @param usuario  um usuario.
 * @return cpf do usuario.
 */
int RecuperaCpfUsuario(Usuario* usuario) {
    return usuario->cpf;
}

/**
 * @brief Destroi um usuario.
 * @param usuario  um usuario.
 */
void DestroiUsuario(Usuario* usuario) {
    free(usuario->nome);
    free(usuario);
}

