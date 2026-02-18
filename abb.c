#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

struct No{
 char nome[100];
 int id;
 struct No *esq;
 struct No *dir;
};
struct No *inserir(struct No *raiz, char nome[], int id){
 if(raiz == NULL){
  struct No *novo = malloc(sizeof(struct No));
  strcpy(novo->nome, nome);
  novo->id = id;
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}else{
  int x = strcmp(raiz->nome, nome);
  if(x < 0){
   raiz->dir = inserir(raiz->dir, nome, id);
  }else if(x > 0){
   raiz->esq = inserir(raiz->esq, nome, id);
  }
 return raiz;
 }
}
struct No *buscar(struct No *raiz, char nome[]){
 if(raiz == NULL){
  return NULL;
 }else{
  int x = strcmp(raiz->nome, nome);
  if(x < 0){
   return buscar(raiz->dir, nome);
  }else if(x > 0){
   return buscar(raiz->esq, nome);
  }else{
   return raiz;
  }
 }
}
void ordem(struct No *raiz){
 if(raiz == NULL) return;
 ordem(raiz->esq);
 printf("%s", raiz->nome);
 printf("%d", raiz->id);
 ordem(raiz->dir);
}
void liberar(struct No *raiz){
 if(raiz == NULL){
  return;
 }else{
  liberar(raiz->esq);
  liberar(raiz->dir);
  free(raiz);
 }
}