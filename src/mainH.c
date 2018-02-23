/*
mainH.c
Autor: Orlando Enrico Liz Silvério Silva
Data: 17/11/17
*/
#include <stdio.h>
#include <stdlib.h>
#include "heuristica.h"

int main(){
    unsigned int M, N, i;

    if(scanf("%u %u", &N, &M)!=2) printf("erro\n");
    no *lista = (no *) malloc((N)*sizeof(no));

    esquina *e = (esquina *) malloc(N*sizeof(esquina));

    // Inicialização da lista. 
    for(i=0; i<N; i++){
        lista[i].vizinho = 0; 
        lista[i].prox = NULL;
        e[i].id = i+1;
        if(scanf("%u", &e[i].peso)!=1) printf("erro\n");
    }        

    for (i = 0; i < M; i++){
        unsigned int x, y;

        if(scanf("%u %u", &x, &y)!=2) printf("erro\n");
        //marca os vizinhos de um vértice com bitmask
        
        addVizinho(lista, x-1, y-1);
        addVizinho(lista, y-1, x-1);
    }

    heapSort(e, N);
    ISAproximacao(lista, e, N);

    desalocaLista(lista, N);
    free(e);

    return 0;
}

