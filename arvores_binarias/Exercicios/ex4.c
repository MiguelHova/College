/*
Escreva uma função que imprima os valores associados às folhas da árvore em ordem, ou seja,
do maior para menor, podendo haver repetições  
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No {
    int info;
    struct No* esquerda;
    struct No* direita;
} No;

No* criar_no(int valor, No* e, No* d) {
    No* novo = (No*) malloc(sizeof(No));

    //Erro de alocação
    if(!novo) exit(1);

    novo->info = valor;
    novo->esquerda = e;
    novo->direita = d;

    return novo;
}

No* inserir(No* raiz, int key) {
    if(!raiz) {
        return criar_no(key, NULL, NULL);
    }

    if(key < raiz->info) {
        raiz->esquerda = inserir(raiz->esquerda, key);
    } else {
        raiz->direita = inserir(raiz->direita, key);
    }

    return raiz;
}

void limpa_arvore(No* raiz) {
    if (!raiz) return;

    limpa_arvore(raiz->esquerda);
    limpa_arvore(raiz->direita);

    free(raiz);
}



void folhas_decrescente(No* raiz) {
    if (!raiz) return;

    
    folhas_decrescente(raiz->direita);

    if (!raiz->direita && !raiz->esquerda) {
        printf("%d ", raiz->info);
    }
    
    folhas_decrescente(raiz->esquerda);
}

int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 5);

    folhas_decrescente(raiz);

    return 0;
}
