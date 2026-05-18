/*
O insert de uma lista encadeada depende da situação, aqui faremos o código pensando em 
criar uma lista ordenada. 
*/


#include<stdio.h>
#include<stdlib.h>
#include"lista_encadeada.h"

Lista *search(Lista *l, int v) {
    Lista *p;
    
    for(p = l; (p!=NULL) && (p->info != v); p = p->prox);
    return p;
}

Lista *insert(Lista *l, int v) {
    Lista *novo = (Lista*) malloc (sizeof(Lista));
    Lista *aux, *proximo;

    novo->info = v;      

    //Caso de lista vazia
    if(!l) {
        novo->prox = NULL;
        return novo;
    } 

    //Caso que insere no começo
    if(v < l->info) {
        novo->prox = l;
        return novo; //Aqui novo se torna o novo head
    }

    //Caso que insere no meio ou fim
    aux= l;
    proximo = l->prox;

    while(proximo != NULL && v > proximo->info ) {
        aux = proximo;
        proximo = proximo->prox;
    }

    //encadeando
    novo->prox = proximo;
    aux->prox = novo;

    return l;
}


Lista *delete(Lista *l, int v) {
    Lista *aux, *anterior;

    //Para lista vazia
    if(!l) {
        printf("\nLista vazia\n");
        exit(0);
    }

    //Para lista com somente um elemento
    if (!l->prox && l->info == v) {
        aux = l;
        l = l->prox;
        free(aux);
        return l;
    }

    //Buscando elementos
    anterior = l;
    aux = l->prox;

    while(aux != NULL && aux->info != v) {
        anterior = aux;
        aux = aux->prox;
    }
    
    if(aux == NULL) {
        printf("\nElemento nao encontrado\n");
        return l;
    }

    //encadeando
    anterior->prox = aux->prox;
    free(aux);

    return l;
}
