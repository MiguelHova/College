/*Implemente uma função que retorne a quantidade de folhas de uma árvore binária*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int data;
    struct No *left;
    struct No *right;
}No;

No* cria_no(int valor) {
    No* novo = (No*) malloc(sizeof(No));

    novo->data = valor;
    novo->left = NULL;
    novo->right = NULL;

    return novo;
}

void libera_arvore (No* raiz) {
    if (raiz == NULL) return;

    libera_arvore(raiz->left);
    libera_arvore(raiz->right);
    free(raiz);
}

//folhas sao nós sem filhos
int conta_folhas(No* raiz) {
    if (raiz == NULL) return 0;

    if(raiz->left == NULL && raiz->right == NULL) return 1;

    return conta_folhas(raiz->left) + conta_folhas(raiz->right);
}


int main() {
    /*
                 8
               /   \ 
              4     5
             / \   / \ 
            1   2 3   9
    */
    int folhas;

    No* raiz = cria_no(8);
    
    raiz->left = cria_no(4);
    raiz->left->left = cria_no(1);
    raiz->left->right = cria_no(2);
    raiz->right = cria_no(5);
    raiz->right->left = cria_no(3);
    raiz->right->right = cria_no(9);

    folhas = conta_folhas(raiz);

    printf("Quantidade de folhas: %d", folhas);

    libera_arvore(raiz);

    return 0;
}


