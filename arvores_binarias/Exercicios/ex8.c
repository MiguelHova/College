/*
Faça uma função que retorne a soma de todos os nós de uma árvore.
Cada nó possui uma informação inteira 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int dado;
    struct No* left;
    struct No* right;
}No;

No* cria_no(int info) {
    No* novo = (No*) malloc(sizeof(No));

    if(!novo) exit(1);

    novo->dado = info;
    novo->left = novo->right = NULL;

    return novo;
}

void libera(No* raiz) {
    if(!raiz) return;

    libera(raiz->left);
    libera(raiz->right);

    free(raiz);
}

int soma(No* raiz) {
    if(!raiz) return 0;

    return raiz->dado + soma(raiz->left) + soma(raiz->right);
}

int main() {
    /*
                 8
               /   \ 
              4     5
             / \   / \ 
            1   2 3   9
    */
    No* raiz = cria_no(8);
    
    raiz->left = cria_no(4);
    raiz->left->left = cria_no(1);
    raiz->left->right = cria_no(2);
    raiz->right = cria_no(5);
    raiz->right->left = cria_no(3);
    raiz->right->right = cria_no(9);

    //soma = 32

    printf("A soma dos nos eh: %d", soma(raiz));

    libera(raiz);

    return 0;
}