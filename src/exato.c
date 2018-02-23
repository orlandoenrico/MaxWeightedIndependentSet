/*
exato.c
Autor: Orlando Enrico Liz Silvério Silva
Data: 17/11/17
*/
#include <stdio.h>
#include <stdlib.h>
#include "exato.h"

//Inicializa esquinas vizinhas
void inicializaVizinhas(unsigned int N, esquina *e){
    unsigned int i;
    for(i=0; i<N; i++)
        e[i].vizinhas = 0;
}

//Maximum Weighted Independent Set
//Conjunto Independente com Peso Máximo
void MWIS(unsigned int N, esquina *e){
    unsigned int conjunto = 0, aux = 0, soma = 0, max = 0, escolhas = 0;
    unsigned int i, j;
	unsigned int numConjuntos = (1<<N);

    //testa os 2^n grafos possíveis
 	for(conjunto = 1; conjunto < numConjuntos; conjunto++){
   		int flag = 1;
        
   		for (i = 0; i < N; i++){
            //se um vértice está no grafo em questão e seus vizinhos também
     		if((1<<i & conjunto) && (e[i].vizinhas & conjunto)){
                //o grafo não é independente
       			flag = 0;
       			break;
     		}else{
                //se for uma configuração válida
	     		aux = 0;
                //somam-se as demandas
	   			for(j = 0; j < N; j++){
	   		 		if((1<<j) & conjunto)
	   		 			aux += e[j].peso;
	   			}
	   		}
   		}
   	    
        //faz a verificação do conjunto independente com peso máximo
   		if (flag && aux >= soma){
            if(aux == soma && max > __builtin_popcountll(conjunto))
                break;
     		max = __builtin_popcountll(conjunto); //número de vértices 
     		soma = aux; //soma das demandas
     		escolhas = conjunto;
   		}
 	}
    //imprime o número de vértices escolhidos e a soma das demandas
 	printf("%u %u\n", max, soma);
    //imprime os vértices escolhidos
 	for(i = 0; i < N; i++){
        if((1<<i) & escolhas)
	   	   printf("%u ", i+1);
    }
	printf("\n");
}