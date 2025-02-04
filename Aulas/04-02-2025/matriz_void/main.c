#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void) {
  struct matriz *m;
  
  m = inicializaMatriz(5, 3, sizeof(char));
  char valor = 'C';

  for (int i=0; i < 5; i++)
    for (int j =0; j < 3; j++)
      atribuiElemMatriz(m, i, j, &valor, TIPO_CHAR);

  imprimeMatriz(m,TIPO_CHAR);

  freeMatriz(m);

  return 0;
}