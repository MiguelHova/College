#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

//typedef(s)

typedef struct lista {
    int info;
    struct lista *prox;
} Lista;

Lista *search(Lista *l, int v);
Lista *insert(Lista *l, int v);
Lista *delete(Lista *l, int *v);

#endif