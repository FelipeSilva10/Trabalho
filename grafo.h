typedef struct grafo Grafo;
Grafo *criaGrafo(int numeroLocalidades);
void liberaGrafo(Grafo *grafo);
int insereRua(Grafo *grafo, int origem, int destino, int distancia);
int removeRua(Grafo *grafo, int origem, int destino);
void imprimeGrafo(Grafo *grafo);
void dijkstra(Grafo *grafo, int origem, int destino);