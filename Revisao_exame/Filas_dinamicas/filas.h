#ifndef FILAS_H
#define FILAS_H

typedef struct No {
    int valor;
    char caractere;
    struct No* prox;
} No;

typedef struct Fila {
    struct No* inicio;
    struct No* fim;
}Fila;

Fila* init();
Fila* insert_int(Fila* f, int v);
Fila* insert_char(Fila* f, char c);
Fila* delete_int(Fila* f, int *v);
Fila* delete_char(Fila* f, int *c);
void libera_fila(Fila* f);

#endif