#include<stdio.h>
#include<stdlib.h>
#include"filas_dinamicas.h"

Fila* init() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    
    if(!f) {
        printf("\nErro ao alocar memoria\n");
        exit(1);
    }
    
    f->inicio = f->fim = NULL;
    return f;
}

Fila* insert(Fila* f, int v) {
    No* n = (No*) malloc (sizeof(No));
    
    if(!n) {
        printf("\nErro ao alocar memoria\n");
        exit(1);
    }

    n->info = v; 
    n->prox = NULL;

    if(!f->inicio) {
        f->inicio = f->fim = n;
        
    } else {
        f->fim->prox = n;
        f->fim = n; 
    }
    

    return f;
}

Fila* remover(Fila*f, int* n) {
    No* node = f->inicio;

    if(!node) {
        printf("\nFila vazia\n");
        exit(0);
    }

    *n = f->inicio->info;
    f->inicio = f->inicio->prox;
    
    if(!f->inicio) {
        f->fim = NULL;
    }

    free(node);

    return f;
}

void list(Fila*f) {
    
    No* aux = f->inicio;

    printf("\n Fila: ");

    while(aux) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }

    printf("\n");
}

void liberar(Fila*f) {
    No* aux = f->inicio;

    while(aux) {
        f->inicio = f->inicio->prox;
        free(aux);
        aux = f->inicio;
    }

    f->fim = NULL;
}

