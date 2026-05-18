#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

typedef struct Fila {
    int info;
    struct Fila *prox;
} Fila;

Fila* init();
Fila* insert(Fila* fila, int v);
Fila* del(Fila* fila, int *v);
void show_all(Fila* fila);


#endif