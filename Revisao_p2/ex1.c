/*
Escreva uma função recursiva que retorne o tamanho de uma lista
*/

//bibliotecas
#include<stdio.h>
#include<stdlib.h>

//typedef Lista e prototipo de funções, faremos uma lista encadeada simples para o exercício
typedef struct Lista {
    int dado;
    struct Lista *prox;
}Lista;

    //funções utilitarias
Lista* add(Lista* l, int v);
void show(Lista* l);
    //função principal
    
int size(Lista* l);
    
//main dã
int main() {
    Lista *l;    
    int n;

    l = NULL;

    l = add(l, 1);
    l = add(l, 2);
    l = add(l, 3);
    l = add(l, 4);
    l = add(l, 5);
    l = add(l, 6);
    l = add(l, 7);
    l = add(l, 8);
    l = add(l, 9);

    show(l);

    n = size(l);

    printf("\n");
    printf("O tamanho da lista eh %d", n);
    printf("\n");
    

    return 0;        
}
    
//definindo funções 

    //funções utilitarias
Lista* add(Lista* l, int v) {
    Lista* novo, *aux;

    novo = (Lista*) malloc(sizeof(Lista));

    aux = l;

    if(!novo) {
        printf("Erro ao alocar memoria");
        exit(1);
    }

    novo->dado =  v;
    novo->prox = NULL;

    if(!aux) {
        return novo;
    }

    
    while(aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;

    return l;
}


void show(Lista* l) {
    Lista *aux;

    aux = l;
    
    
    if(!aux) {
        printf("\nLista vazia\n");
        return;
    }
    
    printf("\n Lista:\n");

    while(aux) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    
    printf("\n");
 }


    //função principal   
int size(Lista* l) {
    Lista *aux = l;

    if(!aux) {
        return 0;
    } 

    aux = aux->prox;

    return size(aux) + 1;
}

