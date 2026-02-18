#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


typedef struct rua{
int destino;
int origem;
int distancia;
struct rua *proxima;} rua;


 struct grafo{
    int numeroLocalidades;
    rua **listaAdj;
};


Grafo *criaGrafo(int numeroLocalidades){
    Grafo *grafo;
grafo  = (Grafo*) malloc(sizeof(struct grafo));
if(grafo != NULL){
    grafo->numeroLocalidades = numeroLocalidades;

    grafo->listaAdj = (rua*) malloc (numeroLocalidades * sizeof(rua));
    if(grafo->listaAdj == NULL)
    {
        free(grafo);
        return NULL;
    }
    for(int i = 0; i<numeroLocalidades;  i++){
        grafo->listaAdj[i] = NULL;


    }
    return grafo;

}
else{
    return NULL;
}}


void liberaGrafo(Grafo *grafo){
    if(grafo != NULL){
    for(int i = 0; i < grafo->numeroLocalidades; i++){
            while(grafo->listaAdj[i] != NULL){
       rua *temp = grafo->listaAdj[i];
       grafo->listaAdj[i] = temp->proxima;
       free(temp);
    }
}
    free(grafo->listaAdj);
    free(grafo);
    }}


int insereRua(Grafo *grafo, int origem, int destino, int distancia){
    if(grafo != NULL){
        if(origem < 0 || origem >= grafo->numeroLocalidades){
            return 0;
        }
        if(destino < 0 || destino >= grafo->numeroLocalidades){
            return 0;
        }

       rua *nova1 = malloc(sizeof(rua));
    rua *nova2 = malloc(sizeof(rua));

    if(nova1 == NULL || nova2 == NULL){
        free(nova1);
        free(nova2);
        return 0;
    }

    nova1->destino = destino;
    nova1->distancia = distancia;
    nova1 -> proxima = grafo ->listaAdj[origem];
    grafo -> listaAdj[origem] = nova1;


    nova2 -> destino = origem;
    nova2-> distancia = distancia;
    nova2 -> proxima = grafo -> listaAdj[destino];
    grafo -> listaAdj[destino] = nova2;
    return 1;
    }
	return 0;}




    int removeRua(Grafo *grafo, int origem, int destino){
    if(grafo != NULL){
        if(origem < 0 || origem >= grafo->numeroLocalidades){
            return 0;
        }
        if(destino < 0 || destino >= grafo->numeroLocalidades){
            return 0;
        }
        rua *atual;
        rua *anterior;
        int encontrado = 0;

        atual = grafo->listaAdj[origem];
        anterior = NULL;

        while(atual != NULL){
            if(atual->destino == destino){
                if(anterior == NULL){
                    grafo->listaAdj[origem] = atual->proxima;
                } else{
                        anterior -> proxima = atual->proxima;}
                    free(atual);
                    encontrado ++;
                    break;
                }

                anterior = atual;
                atual = atual->proxima;
            }

    atual = grafo->listaAdj[destino];
    anterior = NULL;

    while(atual != NULL){
        if(atual->destino == origem){
                if(anterior == NULL){
                    grafo->listaAdj[destino] = atual->proxima;
                }else{
                         anterior->proxima = atual->proxima;}
                    free(atual);
                    encontrado++;
                    break;}

    anterior = atual;
    atual = atual -> proxima;}
    return encontrado;}}





void imprimeGrafo(Grafo *grafo){
    if (grafo != NULL){
        for(int i = 0; i < grafo->numeroLocalidades; i++){
                printf("Localidade %d", i);
            rua *atual = grafo->listaAdj[i];
            if(atual == NULL){
                printf("Não há ruas conectadas\n");
            }
            while(atual != NULL){
                printf("Da localidade %d para a localidade %d, a distancia eh de %d\n",i, atual->destino, atual->distancia);
                atual = atual->proxima;
            }
            printf("\n");
        }
    }
    }