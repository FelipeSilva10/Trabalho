#ifndef ABB_H
#define ABB_H

typedef struct No{
 char nome[100];
 int id;
 struct No *esq;
 struct No *dir;
}No;

struct No *inserir(struct No *raiz, char nome[], int id);
struct No *buscar(struct No *raiz, char nome[]);
void ordem(struct No *raiz);
void liberar(struct No *raiz);
#endif
