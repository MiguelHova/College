#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

Pilha* init() {
    return NULL;
}

Pilha* push_int(Pilha* pilha, int val) {
    Pilha* p = malloc(sizeof(Pilha));
    
    //falha ao alocar memória 
    if(!p) exit(1);
    
    //adicionando valores e alocando ponteiros
    p->valor = val;
    p->prox = pilha;
    
    // Retorna p como novo head
    return p;
}

Pilha* push_char(Pilha* pilha, char c) {
    Pilha* p = malloc(sizeof(Pilha));

    //falha ao alocar memória 
    if(!p) exit(1);

    //adicionando valores e alocando ponteiros
    p->caractere = c;
    p->prox = pilha;

    // Retorna p como novo head
    return p;
}

Pilha* pop_int(Pilha* pilha, int *x) {
    Pilha* aux;
    
    aux = pilha;
    
    //Erro: Pilha vazia
    if(!pilha) {
        printf("\nPilha vazia\n");
        return pilha;
    }
    
    //Removendo elemento
    pilha = pilha->prox;
    
    *x = aux->valor;
    
    free(aux);
    
    return pilha;
}

Pilha* pop_char(Pilha* pilha, char *c) {
    Pilha* aux;
    
    aux = pilha;
    
    //Erro: Pilha vazia
    if(!pilha) {
        printf("\nPilha vazia\n");
        return pilha;
    }
    
    //Removendo elemento
    pilha = pilha->prox;
    
    *c = aux->caractere;
    
    free(aux);
    
    return pilha;
}

void show_int(Pilha *pilha) {
    
    //Caso a pilha esteja vazia
    if(!pilha) {
        printf("\nPilha vazia\n");
        return;
    }

    printf("\n");
    
    while(pilha) {
        printf("%d ", pilha->valor);
        pilha = pilha->prox;
    }
    
    printf("\n");
}


void show_char(Pilha *pilha) {
    
    //Caso a pilha esteja vazia
    if(!pilha) {
        printf("\nPilha vazia\n");
        return;
    }

    printf("\n");
    
    while(pilha) {
        printf("%c ", pilha->caractere);
        pilha = pilha->prox;
    }
    
    printf("\n");
}

void liberar_pilha(Pilha *pilha) {
    Pilha *aux;

    aux = pilha;

    //caso pilha vazia
    if(!pilha) return;

    while(aux) {
        pilha = pilha->prox;
        free(aux);
        aux = pilha;
    }
}














