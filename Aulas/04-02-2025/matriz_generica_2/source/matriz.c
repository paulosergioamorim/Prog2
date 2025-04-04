#include <stdlib.h> /* malloc, free, exit */
#include <stdio.h> /* printf */
#include <string.h> /* strcat */

/* O TIPO DE DADOS DE CADA ELEMENTO DA MATRIZ 
 * É O "DESTE_TIPO_" DEFINIDO NA IMPLEMENTAÇÃO
 * DA MESMA MANEIRA, O FORMATO DE IMPRESSÃO DE 
 * CADA ELEMENTO É O "DESTE_FORMATO_",
 * TAMBÉM DEFINIDO NA IMPLEMENTAÇÃO 
 */
#define DESTE_TIPO_ int
#define DESTE_FORMATO_ "%d"

#include "matriz.h"

 typedef struct Matriz_st {
 unsigned int lin;
 unsigned int col;
 DESTE_TIPO_ ** v;
}  Matriz_t;

Matriz_pt criaMatriz (unsigned int m, unsigned int n) {
	Matriz_pt mat = (Matriz_pt) malloc(sizeof( Matriz_t));
		
	mat->lin = m;
	mat->col = n;
	mat->v = (DESTE_TIPO_**) malloc(m*sizeof(DESTE_TIPO_*));
	if (mat->v == NULL) {
			printf("Memória insuficiente!\n");
			exit(1);
	}
			
	for (unsigned i=0; i<m; i++)
	{	mat->v[i] = (DESTE_TIPO_*) malloc(n*sizeof(DESTE_TIPO_));
		if (mat->v[i] == NULL) {
			printf("Memória insuficiente!\n");
			exit(1);
		}
	}
	return mat;
}



void liberaMatriz (Matriz_pt mat){
	
	for (unsigned i=0; i<mat->lin; i++)
	{	free(mat->v[i]);
	}
	free(mat->v);
	free(mat);
}


DESTE_TIPO_ acessaMatriz (Matriz_pt mat, unsigned int i, unsigned int j) {
	unsigned int k; /* índice do elemento no vetor */
	if ( i>=linhasMatriz(mat) || j >= colunasMatriz(mat)) {
		printf("Acesso inválido!\n");
		exit(1);
	}
	return mat->v[i][j];
}




void atribuiElemMatriz (Matriz_pt mat, 
						unsigned int i, 
                        unsigned int j, 
                        DESTE_TIPO_ valor) 
{
	if ( i>=linhasMatriz(mat) ||  j>=colunasMatriz(mat)) {
		printf("Atribuição inválida!\n");
		exit(1);
	}
	mat->v[i][j] = valor;
}


unsigned int linhasMatriz (Matriz_pt mat) {
	return mat->lin;
}


unsigned int colunasMatriz (Matriz_pt mat) {
 return mat->col;
}


void exibeMatriz (Matriz_pt mat)
{
	char formato[10] = " ";
	strcat (formato, DESTE_FORMATO_);
	strcat (formato, " ");
	
	for (unsigned int i=0; i < linhasMatriz (mat); i++)
	{
		for (unsigned j = 0; j < colunasMatriz (mat); j++)
		{
			printf (formato , acessaMatriz (mat,i,j));
		}
		printf ("\n");
	}
	printf ("\n\n");
}

void preencheSequencialMatriz (Matriz_pt mat)
{
	DESTE_TIPO_ valor = 1;
    for (unsigned int i=0; i < linhasMatriz (mat); i++)
    {
		for (unsigned int j=0; j<colunasMatriz(mat); j++)
		{
			atribuiElemMatriz (mat, i,j, valor);
			valor++;
		}
	}
}



Matriz_pt  multiplicaMatrizes (Matriz_pt mat1, Matriz_pt mat2)
{
	DESTE_TIPO_ valor;
	
	if (colunasMatriz (mat1) != linhasMatriz (mat2))
	{
		printf("Dimensões não permitem multiplicação das matrizes!\n");
		exit(1);
	}
	
	Matriz_pt resultado = criaMatriz ( 	linhasMatriz  (mat1),
										colunasMatriz (mat2) );
	
	for (unsigned int i = 0; i < linhasMatriz (resultado); i++)
	{
		for (unsigned int j = 0; j < colunasMatriz (resultado); j++)
		{	
			valor = (DESTE_TIPO_) 0;
			for (unsigned int k = 0; k < colunasMatriz (mat1) ; k++)
			{
				valor += acessaMatriz (mat1,i,k) * 
						 acessaMatriz (mat2,k,j);
			}
			atribuiElemMatriz (resultado,i,j,valor);
		}
	}
	return (resultado);
}






