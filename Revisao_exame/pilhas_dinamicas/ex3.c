/*
Utilizando as operações de manipulação de pilhas vistas em sala, uma pilha auxiliar e
uma variável do tipo TItem, escreva um procedimento que remove um item com chave c de uma posição qualquer de uma pilha. Note que você não tem acesso à estrutura interna
da pilha (Topo, Item, etc), apenas às operações de manipulação.
*/

#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

Pilha* remove_elemento(Pilha* pilha, int c);

int main() {
    Pilha* p;

    p = init();

    p = push(p, 1);
    p = push(p, 2);
    p = push(p, 3);
    p = push(p, 4);
    p = push(p, 5);
    p = push(p, 6);
    p = push(p, 7);

    show(p);

    p = remove_elemento(p, 111);

    show(p);

    return 0;
}

Pilha* remove_elemento(Pilha* pilha, int c) {
    Pilha* aux, *aux2;

    //Caso em que a pilha está vazia:
    if(!pilha) {
        printf("\npilha vazia\n");
        return NULL;
    }

    //caso em que a pilha só tem um elemento:
    if(!pilha->prox) {
        if(pilha->valor == c) {
            free(pilha);
            return NULL;
        } else {
            return pilha;
        }
    }

    //caso com 2 ou mais elementos;
    aux = pilha;
    aux2 = pilha->prox;

    while(aux2) {
        
        if(aux2->valor == c) {
            aux->prox = aux2->prox;
            free(aux2);
            return pilha;
        }

        aux = aux->prox;
        aux2 = aux->prox;
    }

    printf("O valor nao foi encontrado");

    return pilha;
}