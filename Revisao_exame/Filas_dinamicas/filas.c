#include<stdio.h>
#include<stdlib.h>
#include"filas.h"


//inicializa a fila
Fila* init() {
    Fila* f;
    f->fim = f->inicio = NULL;

    return f;
}


//insere no fim, sempre
Fila* insert_int(Fila* f, int v) {
    No* novo = (No*) malloc(sizeof(No));

    //alocando conteúdo
    novo->prox = NULL;
    novo->valor = v;

    //alocando ponteiros
        //caso a fila esteja vazia
    if(!f) {
        f->fim = f->inicio = novo;
        return f;
    }

        //Caso a fila tenha um ou mais elementos;
    f->fim->prox = novo;
    f->fim = novo;

    return f;
}

Fila* insert_char(Fila* f, char c) {
    No* novo = (No*) malloc(sizeof(No));

    //alocando conteúdo
    novo->prox = NULL;
    novo->caractere = c;

    //alocando ponteiros
        //caso a fila esteja vazia
    if(!f) {
        f->fim = f->inicio = novo;
        return f;
    }

        //Caso a fila tenha um ou mais elementos;
    f->fim->prox = novo;
    f->fim = novo;

    return f;
}

Fila* delete_int(Fila* f, int *v) {
    No* aux;

    aux = f->inicio;

    //Caso em que fila está vazia
    if(!f) {
        printf("/nA fila está vazia/n");
        return f;
    }


    //Caso em que há só um elemento
    if(!f->fim->prox) {
        f->inicio = f->fim = NULL;
        
        *v = aux->valor;

        free(aux);
        
        return f;
    }

    //Caso geral
    f->inicio = f->inicio->prox;

    *v = aux->valor;

    free(aux);

    return f;
}

Fila* delete_char(Fila* f, int *c) {
    No* aux;

    aux = f->inicio;

    //Caso em que fila está vazia
    if(!f) {
        printf("/nA fila está vazia/n");
        return f;
    }


    //Caso em que há só um elemento
    if(!f->fim->prox) {
        f->inicio = f->fim = NULL;

        *c = aux->caractere;

        free(aux);

        return f;
    }

    //Caso geral
    f->inicio = f->inicio->prox;
    
    *c = aux->caractere;
    
    free(aux);

    return f;
}

void libera_fila(Fila* f) {
    No* aux =  f->inicio;

    //Caso em que não há elementos
    if(!f) {
        printf("\nFila vazia\n");
        return;
    }

    //Caso geral

        //while limpa a lista até chegar no último nó. Note que limpa também o último nó
    //mas f->fim aponta para um ponteiro livrado, se tornando um dangling pointer.   
    while(f->inicio) {
        f->inicio = f->inicio->prox;

        free(aux);

        aux = f->inicio;
    }

    //agora f->fim é NULL, resolvendo o problema
    f->fim = f->inicio; 

    return f;
}

void show_int(Fila* f) {
    
    //fila vazia
    if(!f) return;

    //caso geral
    while(f->inicio) {
        printf("%d ", f->inicio->valor);
        f->inicio = f->inicio->prox;
    }

}

void show_char(Fila* f) {
    
    //fila vazia
    if(!f) return;

    //caso geral
    while(f->inicio) {
        printf("%d ", f->inicio->caractere);
        f->inicio = f->inicio->prox;
    }

}





