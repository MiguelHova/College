/*
Implemente a função int igual_h(Arv *a, Arv *b, int h) que retorna 1 se os nós, na altura h, forem iguais
nas duas árvores, ou 0 caso contrário.

como não foi dito que tipo de árvore é no enunciado, consideraremos uma árvore binária.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

No* criar_no(int info, No* e, No* d) {
    No* novo = (No*) malloc(sizeof(No));

    if(!novo) exit(1);

    novo->dado = info;
    novo->direito = d;
    novo->esquerdo = e;

    return novo;
}

void libera_arv(No* raiz) {
    if(!raiz) return;

    libera_arv(raiz->esquerdo);
    libera_arv(raiz->direito);

    free(raiz);
}

int igual_h(No* raiz1, No* raiz2, int h) {
    
    if(!raiz1 && !raiz2) return 1;
    if(!raiz1 || !raiz2) return 0;

    if(h==0) return raiz1->dado == raiz2->dado;

    return igual_h(raiz1->esquerdo, raiz2->esquerdo, h-1) && igual_h(raiz1->direito, raiz2->direito, h-1); 
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
        criar_no(2,
            criar_no(6,NULL,NULL), 
            criar_no(3,NULL,NULL))
    );

    if(igual_h(raiz, raiz2, 0)) {
        printf("Igual");
    } else {
        printf("diferente");
    }

    libera_arv(raiz);
    libera_arv(raiz2);

    return 0;
}

