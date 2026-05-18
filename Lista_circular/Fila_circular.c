//Como convenção, guarda-se o elemento do "último nó"
//implementing a circular queue using circular list


#include<stdio.h>
#include<stdlib.h>
#include"Fila_circular.h"

Fila* init() {
    return NULL;
}


Fila* insert(Fila* fila, int v) {
    Fila* novo = (Fila*) malloc (sizeof(Fila));

    novo->info = v;

    //Caso de fila vazia
    if(!fila) {
        novo->prox = novo;
        return novo; // novo é o ultimo elemento;
    }

    //um ou mais elementos
    Fila *f = fila;

    f = f->prox; //f é o primeiro elemento 

    fila->prox = novo; //novo é o ultimo elemento 

    novo->prox = f; //circulando a lista

    return novo;
}


Fila* del(Fila* fila, int *v) {
    Fila* primeiro, *aux;

    //Caso de fila vazia
    if(!fila) {
        printf("\nFila vazia\n");
        exit(0);
    }

    //Caso de somente um elemento
    if(fila == fila->prox) {
        *v = fila->info;
        free(fila);
        fila = NULL;
        return fila;
    }

    //resto
    primeiro = fila->prox;
    aux = primeiro->prox;

    *v = primeiro->info;

    fila->prox = aux;
    free(primeiro);
    
    return fila;
}


void show_all(Fila* fila) {
    Fila* aux;

    aux = fila->prox;
    
    if(!aux) {
        printf("\nFila vazia...\n");
        return;
    }

    printf("\n\nFila: ");

    do {
        printf("%d ", aux->info);
        aux = aux->prox;

    } while (aux != fila);
    
    printf("\n");
}

