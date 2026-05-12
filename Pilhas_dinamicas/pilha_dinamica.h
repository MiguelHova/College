#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

typedef struct pilha{
    int info;
    struct pilha *prox;
} Pilha;

Pilha* init();
Pilha* push(Pilha* p, int n);
Pilha* pop(Pilha* p, int* n);
void list(Pilha* p);
void remover(Pilha* p);

#endif