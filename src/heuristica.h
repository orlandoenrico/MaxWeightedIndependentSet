/*
heuristica.h
Autor: Orlando Enrico Liz Silvério Silva
Data: 17/11/17
*/
#ifndef HEURISTICA_H
#define HEURISTICA_H

typedef struct no{
    unsigned int vizinho;
    struct no* prox;
}no;

typedef struct esquina{
    unsigned int id;
    unsigned int peso;
}esquina;

/*------------------------------------------------------------------------------
 Função:  cria as arestas do grafo que estabelecem vizinhos.
 Entrada: lista de adjacência e o índice dos vizinhos.
------------------------------------------------------------------------------*/
void addVizinho(no *lista, unsigned int x, unsigned int y);

/*------------------------------------------------------------------------------
 Função:  cria o heap utilizado para a ordenação.
 Entrada: número de vértices (esquinas) e vetor com pesos, identificador e 
 	 	  vizinhos de cada vértice e um nó i.
------------------------------------------------------------------------------*/
void constroiHeap(esquina *e, unsigned int N, unsigned int i);

/*------------------------------------------------------------------------------
 Função:  ordena os vértices decrescentemente pelo seu peso.
 Entrada: número de vértices (esquinas) e vetor com pesos e id de cada 
 		  vértice.
------------------------------------------------------------------------------*/
void heapSort(esquina *e, unsigned int N);

/*------------------------------------------------------------------------------
 Função:  imprime uma aproximação do Conjunto Independente com Peso Máximo.
 Entrada: lista de adjacência, número de vértices (esquinas) e vetor com pesos
  		  e id de cada vértice.
------------------------------------------------------------------------------*/
void ISAproximacao(no *lista, esquina *e, unsigned int N);

/*------------------------------------------------------------------------------
 Função:  desaloca o vetor de listas.
 Entrada: lista de adjacência e o seu tamanho.
------------------------------------------------------------------------------*/
void desalocaLista(no *lista, unsigned int N);

#endif