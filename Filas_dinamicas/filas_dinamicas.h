#ifndef FILAS_DINAMICAS_H
#define FILAS_DINAMICAS_H

typedef struct no{
    int info;;
    struct no *prox;
} No;

typedef struct fila{
    No *inicio;
    No *fim;
} Fila;

Fila* init();
Fila* insert(Fila* f, int n);
Fila* remover(Fila*f, int* n);
void list(Fila*f);
void liberar(Fila*f);


#endif