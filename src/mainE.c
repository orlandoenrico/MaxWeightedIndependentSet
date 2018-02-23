/*
mainE.c
Autor: Orlando Enrico Liz Silvério Silva
Data: 17/11/17
*/
#include <stdio.h>
#include <stdlib.h>
#include "exato.h"

int main(){
    unsigned int M, N, i;
    
    //ńúmero de esquinas e números de pares de esquinas vizinhas
    if(scanf("%u %u", &N, &M)!=2) printf("erro\n");

    esquina *e = (esquina *) malloc(N*sizeof(esquina));
    inicializaVizinhas(N, e);

    for(i=0; i<N; i++)
        if(scanf("%u", &e[i].peso)!=1) printf("erro\n");

    for (i = 0; i < M; i++){
        unsigned int x, y;

        if(scanf("%u %u", &x, &y)!=2) printf("erro\n");
        //marca os vizinhos de um vértice com bitmask
        e[x-1].vizinhas |= 1<<(y-1);
        e[y-1].vizinhas |= 1<<(x-1);
    }
    //função que encontra o conjunto independente com peso máximo
    MWIS(N, e);
    free(e);

    return 0;
}