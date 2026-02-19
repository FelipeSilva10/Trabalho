#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo *criaGrafo(int numeroLocalidades){
    Grafo* grafo;
    grafo = (Grafo*)malloc(sizeof(Grafo));
    if(grafo != NULL){

        grafo->numeroLocalidades = numeroLocalidades;
        grafo->listaAdj = (rua**)malloc(numeroLocalidades * sizeof(rua*));

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
    }
}


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


void dijkstra(Grafo* grafo, int origem, int destino){

    int n = grafo->numeroLocalidades;

    int visited[n] = {};
    int dist[n] = {};
    int prev[n] = {};

    for(int i=0;i<n;i++) dist[i] = 9999999, prev[i] = -1;

    rua* cur = grafo->listaAdj[origem];

    dist[origem] = 0;

    for(int i=0;i<n;i++){

        int u = -1;

        for(int j=0;j<n;j++){
            if(!visited[j] && (u == -1 || dist[j] < dist[i])) u = j;
        }

        if(dist[u] == 9999999) break;

        visited[u] = 1;

        rua* r = grafo->listaAdj[u];


        while(r != NULL){
            int v = r->destino;

            if(dist[u] + r->distancia < dist[v]){
                dist[v] = dist[u] + r->distancia;
                prev[v] = u;
            }

            r = r->proxima;
        }
    }

    printf("Distancia minima: %d\n", dist[destino]);
    printf("Caminho (ID): ");
    printf("%d ", origem);

    int caminho[n] = {};
    int tam = 0;

    for(int v = destino; prev[v] != -1; v = prev[v]){
        caminho[tam++] = v;
    }

    for(int i = tam-1;i>=0;i--){
        printf("%d ", caminho[i]);
    }
    printf("\n");

}

void mst(Grafo* g){

    int origem = 0; // considerei id = 0 como raiz da arvore
    int n = g->numeroLocalidades;

    int pai[n];
    int key[n];
    int visited[n];

    for(int i=0;i<n;i++){
        key[i] = INT_MAX;
        visited[i] = 0;
        pai[i] = -1;
    }

    key[origem] = 0;

    for(int count=0; count<n-1; count++){

        int u = -1;
        for(int i=0;i<n;i++){
            if(!visited[i] && (u==-1 || key[i] < key[u]))
                u = i;
        }

        visited[u] = 1;

        rua *r = g->listaAdj[u];
        while(r){
            int v = r->destino;

            if(!visited[v] && r->distancia < key[v]){
                key[v] = r->distancia;
                pai[v] = u;
            }

            r = r->proxima;
        }
    }

    printf("Arestas da arvore geradora minima:\n");
    int total = 0;

    for(int i=0;i<n;i++){
        if(pai[i] != -1){
            printf("%d - %d\n", pai[i], i);
            total += key[i];
        }
    }

    printf("Custo total: %d\n", total);

}


void imprimeGrafo(Grafo *grafo){
    if (grafo != NULL){
        for(int i = 0; i < grafo->numeroLocalidades; i++){
            rua *atual = grafo->listaAdj[i];
            if(atual == NULL) break;
            printf("Localidade %d:\n", i);

            while(atual != NULL){
                printf("Da localidade %d para a localidade %d, a distancia eh de %d\n",i, atual->destino, atual->distancia);
                atual = atual->proxima;
            }
            printf("\n");
        }
    }
    }
