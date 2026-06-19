/*Implemente uma função que compare se duas árvores binárias são iguais*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int info;
    struct No* esquerda;
    struct No* direita;
}No;

No* criar_no(int in, No* e, No* d) {
    No* novo = (No*) malloc(sizeof(No));

    novo->info = in;
    novo->esquerda = e;
    novo->direita = d;

    return novo;
}

void limpar_arvore(No* raiz) {
    if (!raiz) return;

    limpar_arvore(raiz->esquerda);
    limpar_arvore(raiz->direita);

    free(raiz);
}

int compare(No* raiz, No* raiz2) {
    if (!raiz && !raiz2) {
        return 1;   
    } else if(!raiz || !raiz2) {
        return 0; 
    }

    if (raiz->info != raiz2->info) {
        return 0;
    }

    return compare(raiz->esquerda, raiz2->esquerda) && compare(raiz->direita, raiz2->direita);
}


int main() {
    /*
                 8
               /   \ 
              4     5
             / \   / \ 
            1   2 3   9
    */

    No* raiz = criar_no(8, 
        criar_no(4,
            criar_no(1, NULL, NULL),
            criar_no(2, NULL, NULL)), 
        criar_no(5,
            criar_no(3,NULL,NULL), 
            criar_no(9,NULL,NULL))
    );

    No* raiz2 = criar_no(8, 
        criar_no(4,
            criar_no(1, NULL, NULL),
            criar_no(2, NULL, NULL)), 
        criar_no(5,
            criar_no(6,NULL,NULL), 
            criar_no(9,NULL,NULL))
    );

    if (compare(raiz, raiz2)) {
        printf("As arvores sao iguais");
    } else {
        printf("As arvores sao diferentes");
    }

    return 0;
}











