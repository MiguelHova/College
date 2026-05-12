#include<stdio.h>
#include<stdlib.h>
#include"pilha_dinamica.h"

Pilha* init() {
    return NULL;
}

Pilha* push(Pilha* p, int n) {
    Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
    
if(!novo) {
        printf("\nErro ao alocar memoria\n");
        exit(1);
    }

    novo->info = n;
    novo->prox = p;
    return novo;
}


Pilha* pop(Pilha* p, int* n) {
    Pilha* p_antes = p;
    
    if(!p) {
        printf("\nA pilha está vazia\n");
        return NULL;
    }
    
    *n = p->info;
    p = p->prox;
    free(p_antes);

    return p;
}

void remover(Pilha* p) {
    Pilha* p_antes = p;

    while(p) {
        p = p->prox;
        free(p_antes);
        p_antes = p;
    }
}

void list(Pilha* p) {
    Pilha* referencia = p;

    if(!p) {
        printf("\nPilha vazia\n");
    }

    printf("\n");
    
    while(referencia) {
        printf("%d ", referencia->info);
        referencia = referencia->prox;
    }
    
    printf("\n");
}
