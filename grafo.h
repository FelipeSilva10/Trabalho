#ifndef GRAFO_H
#define GRAFO_H

typedef struct rua{
int destino;
int origem;
int distancia;
struct rua *proxima;
} rua;

typedef struct Grafo{
    int numeroLocalidades;
    rua **listaAdj;
}Grafo;

Grafo *criaGrafo(int numeroLocalidades);
void liberaGrafo(Grafo *Grafo);
int insereRua(Grafo *Grafo, int origem, int destino, int distancia);
int removeRua(Grafo *Grafo, int origem, int destino);
void imprimeGrafo(Grafo *Grafo);
void dijkstra(Grafo *Grafo, int origem, int destino);
void mst(Grafo *Grafo);

#endif // GRAFO_H_INCLUDED
