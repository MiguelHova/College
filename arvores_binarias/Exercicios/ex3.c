/*
Escreva uma função que retorne o número de ocorrências de um dado valor x na árvore
A função deve tirar proveito da ordenação da árvore
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No {
    int info;
    struct No* direita;
    struct No* esquerda;
} No;

No* criar(int valor, No* e, No* d) {
    No* novo = (No*) malloc(sizeof(No));

    novo->info = valor;
    novo->esquerda = e;
    novo->direita = d;

    return novo;
}

No* inserir(No* raiz, int valor) {
    if(raiz == NULL) return criar(valor, NULL, NULL);

    if(valor < raiz->info) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } 

    if(valor >= raiz->info) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

void liberar(No* raiz) {
    if (!raiz) return;

    liberar(raiz->esquerda);
    liberar(raiz->direita);

    free(raiz);
}

int ocorrencias(No* raiz, int x) {
    if(!raiz) return 0;

    if(x < raiz->info) return ocorrencias(raiz->esquerda, x);

    if(x > raiz->info) return ocorrencias(raiz->direita, x);

    return 1 + ocorrencias(raiz->direita, x);
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

    printf("Ocorrencias de 8: %d", ocorrencias(raiz, 8));

    return 0;
}




