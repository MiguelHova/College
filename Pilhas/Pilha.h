#ifndef PILHA_H
#define PILHA_H

typedef struct pilha {
    int vetor[100];
    int topo;
} Pilha;

Pilha* criar();
Pilha* remover(Pilha* p);
int push(Pilha* p, int n);
int pop(Pilha* p, int* n);
int peek(Pilha* p);
int list(Pilha* p);

#endif