#ifndef ABB_H
#define ABB_H

typedef struct No No;
struct No *inserir(struct No *raiz, char nome[], int id);
struct No *buscar(struct No *raiz, char nome[]);
void ordem(struct No *raiz);
void liberar(struct No *raiz);

#endif