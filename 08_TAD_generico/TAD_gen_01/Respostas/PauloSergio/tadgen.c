#include "tadgen.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct generic {
  void *buff;
  int size;
  Type type;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto
 * inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric *CriaGenerico(Type type, int numElem) {
  tGeneric *pGeneric = malloc(sizeof(struct generic));
  assert(pGeneric);

  pGeneric->size = numElem;
  pGeneric->type = type;

  switch (type) {
  case INT:
    pGeneric->buff = malloc(numElem * sizeof(int));
    break;
  case FLOAT:
    pGeneric->buff = malloc(numElem * sizeof(float));
    break;
  }

  assert(pGeneric->buff);

  return pGeneric;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric *gen) {
  free(gen->buff);
  free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric *gen) {
  int val_int = 0;
  float val_float = 0;
  printf("\nDigite o vetor:\n");

  switch (gen->type) {
  case INT:
    for (int i = 0; i < gen->size; i++) {
      scanf("%d", &val_int);
      ((int *)gen->buff)[i] = val_int;
    }
    break;
  case FLOAT:
    for (int i = 0; i < gen->size; i++) {
      scanf("%f", &val_float);
      ((float *)gen->buff)[i] = val_float;
    }
    break;
  }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric *gen) {
  switch (gen->type) {
  case INT:
    for (int i = 0; i < gen->size; i++) {
      printf("%d", ((int *)gen->buff)[i]);

      if (i < gen->size - 1)
          printf(" ");
    }
    break;
  case FLOAT:
    for (int i = 0; i < gen->size; i++) {
      printf("%f", ((float *)gen->buff)[i]);

      if (i < gen->size - 1)
          printf(" ");
    }
    break;
  }
}
