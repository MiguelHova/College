/*
Criação de Pilha com funçõoes: push, pop, peek, criar, remover, listar
*/

#include<stdio.h>
#include<stdlib.h>
#include "Pilha.h"

Pilha* criar() {
    Pilha* np;

    np = (Pilha*) malloc (sizeof(Pilha));
    
    if(!np) {
        printf("\nErro ao alocar memoria\n");
        exit(1);
    }
    
    np->topo = -1;

    return np;
}


Pilha* remover(Pilha* p) {
    free(p);
    return (NULL);
}


int push(Pilha* p, int n) {
    if (p->topo >= 99) return -1;
    
    p->topo++;
    p->vetor[p->topo] = n;
    return 0;
}


int pop(Pilha* p, int* n) {
    if (p->topo <= -1) return -1;

    *n = p->vetor[p->topo];
    p->topo--;
    return 0;
}


int peek(Pilha* p) {
    if (p->topo <= -1) {
        printf("\npilha vazia..\n");
        return 0;
    } 
    
    printf("\no topo eh: %d\n", p->vetor[p->topo]);
    
    return 0;
}


int list(Pilha* p) {
    int i;
    
    if (p->topo <= -1) {
        printf("\npilha vazia..\n");
        return 0;
    } 
    
    printf("\n Pilha: ");
    
    for (i=0; i <= p->topo; i++) {
        printf("%d ", p->vetor[i]);
    }
    
    printf("\n");

    return 0;
}

