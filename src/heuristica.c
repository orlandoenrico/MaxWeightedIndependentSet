/*
heuristica.c
Autor: Orlando Enrico Liz Silvério Silva
Data: 17/11/17
*/
#include <stdio.h>
#include <stdlib.h>
#include "heuristica.h"

// insere uma aresta entre esquinas vizinhas
void addVizinho(no *lista, unsigned int x, unsigned int y){
    no *aux;
    no *v = (no*) malloc(sizeof(no));
    
    v->vizinho = y; //no a ser inserido
    v->prox = NULL;
  
    lista[x].vizinho++;
    if(lista[x].prox == NULL) //se a lista estiver vazia insere
        lista[x].prox = v;
    else{
        aux = lista[x].prox;
        if (aux->vizinho > y){ //insere na primeira posição
            v->prox = aux;
            lista[x].prox = v;
        //insere as vizinhas de forma ordenada
        }else{
            if(aux->prox == NULL){ 
                v->prox = aux->prox;
                aux->prox = v;  
            }else{
                while((aux->prox != NULL) && (aux->prox->vizinho < y))
                    aux = aux->prox;
                v->prox = aux->prox;
                aux->prox = v;  
            }
        }
    }
}

// heap é uma árvore binária representada num arranjo
void constroiHeap(esquina *e, unsigned int N, unsigned int i){
    esquina aux;
    unsigned int index = i; // raiz
    unsigned int esq = 2*i + 1; // nó da esquerda
    unsigned int dir = 2*i + 2; // nó da direita
 
    // se o filho da esquerda é menor que nó em questão
    if (esq < N && e[esq].peso < e[index].peso)
        index = esq;
    // se o filho da direita é menor que nó em questão
    if (dir < N && e[dir].peso < e[index].peso)
        index = dir;
    // se o index não for raiz
    if (index != i){
        aux = e[index];
        e[index] = e[i];
        e[i] = aux;
        constroiHeap(e, N, index);
    }
}
 
// Heap Sort
void heapSort(esquina *e, unsigned int N){
    int i;
    esquina aux;

    //constroi heap com o rearranjo do vetor
    for(i = N/2-1; i >= 0; i--)
        constroiHeap(e, N, i);
 
    for(i=N-1; i>=0; i--){
        aux = e[0];
        e[0] = e[i];
        e[i] = aux;
 
        constroiHeap(e, i, 0);
    }
}

// aproximação para encontrar o conjunto independente com peso máximo
void ISAproximacao(no *lista, esquina *e, unsigned int N){
    unsigned int i = 0, soma = 0, max = 0;
    no *aux;

    unsigned int *S = (unsigned int*) calloc(N, sizeof(unsigned int));
    unsigned int *escolhas = (unsigned int*) calloc(N,sizeof(unsigned int));
    //percorre o arranjo de vértices ordenado de forma decrescente pelo peso
    for(i=0; i<N; i++){
        //verifica se o vértice em questão está na lista de vértices que não satisfazem um C.I.
        if(S[e[i].id-1]==0){
            aux = lista[e[i].id-1].prox;
            while (aux != NULL) {
                S[aux->vizinho] = 1; //conjunto S recebe vértices vizinhos do vértice em questão
                aux = aux->prox;
            }
            soma+=e[i].peso; //soma-se o peso do vértice
            escolhas[max] = e[i].id; //escolha recebe o vértice em questão
            max++; //contabiliza um vértice para o conjunto final
        }
    }
    printf("%d %d\n", max, soma);
    for(i=0; i<max; i++)
        printf("%d ", escolhas[i]);
    printf("\n");

    free(S);
    free(escolhas);
}

//libera memória alocada para a lista de adjacência
void desalocaLista(no *lista, unsigned int N){
    unsigned int i;
    no *tmp, *aux;
    
    for(i=0; i<N; i++){
        tmp = lista[i].prox;
        while (tmp != NULL) {
            aux = tmp;
            tmp = tmp->prox;
            free(aux);
        }
    } 
    free(lista);
}