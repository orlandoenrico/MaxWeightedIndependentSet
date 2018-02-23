/*
exato.h
Autor: Orlando Enrico Liz Silvério Silva
Data: 17/11/17
*/
#ifndef EXATO_H
#define EXATO_H

typedef struct esquina{
	unsigned int peso;
	unsigned int vizinhas;
}esquina;

/*------------------------------------------------------------------------------
 Função:  inicializa os vizinhos de cada vértice.
 Entrada: número de vértices (esquinas) e vetor com pesos e vizinhos de cada
 		  vértice.
------------------------------------------------------------------------------*/
void inicializaVizinhas(unsigned int N, esquina *e);

/*------------------------------------------------------------------------------
 Função:  imprime o Conjunto Independente com Peso Máximo.
 Entrada: número de vértices (esquinas) e vetor com pesos e vizinhos de cada 
 		  vértice.
------------------------------------------------------------------------------*/
void MWIS(unsigned int N, esquina *e);

#endif