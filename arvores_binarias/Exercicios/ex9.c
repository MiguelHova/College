/*
Assumindo uma estrutura de árvore binária qualquer, implemente funções para resolver os seguintes problemas:
a. Dizer quantos nós tem, 0, 1 e 2 filhos;
b. Imprimir os dados dos nós com profundidade par;
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int dado;
    struct No *esq;
    struct No *dir;
}No;

No* cria_no(int info) {
    No* novo = (No*) malloc(sizeof(No));

    if(!novo) exit(1);

    novo->dado = info;
    novo->esq = novo->dir = NULL;

    return novo;
}

void liberar(No* raiz) {
    if(!raiz) return;

    liberar(raiz->esq);
    liberar(raiz->dir);

    free(raiz);
}

void contar_quant (No* raiz, int *zero, int *um, int *dois) {
    if(!raiz) return;

    contar_quant(raiz->esq, zero, um , dois);
    contar_quant(raiz->dir, zero, um , dois);

    if(!raiz->esq && !raiz->dir) {
        (*zero)++;
    } else if (raiz->esq && raiz->dir) {
        (*dois)++;
    } else {
        (*um)++;
    }
}

void imprimir_nos_pares(No* raiz, int profundidade) {
    if(!raiz) return;

    if(profundidade % 2 == 0) {
        printf("%d ", raiz->dado);
    }

    imprimir_nos_pares(raiz->esq, profundidade + 1);
    imprimir_nos_pares(raiz->dir, profundidade + 1);
}

int main() {
    /*
                 8
               /   \ 
              4     5
             / \   / \ 
            1   2 3   9
                     / 
                    0            
    */
    int zero, um, dois;

    zero = um = dois = 0;

    No* raiz = cria_no(8);
    
    raiz->esq = cria_no(4);
    raiz->esq->esq = cria_no(1);
    raiz->esq->dir = cria_no(2);
    raiz->dir = cria_no(5);
    raiz->dir->esq = cria_no(3);
    raiz->dir->dir = cria_no(9);
    raiz->dir->dir->esq = cria_no(0);

    contar_quant(raiz, &zero, &um, &dois);

    printf("\nzero filhos: %d\n", zero);
    printf("um filho: %d\n", um);
    printf("dois filhos: %d\n\n", dois);

    printf("\nimprimindo h par:\n");

    imprimir_nos_pares(raiz, 0);
    
    liberar(raiz);

    return 0;
}