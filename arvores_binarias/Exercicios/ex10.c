/*
Considere uma árvore binária que representa expressões. As folhas da árvore armazenam operando 
e os nós internos operadores.

Escreva funções que dada raiz de uma árvore binária de expressões (pode considerar que a árvore nunca será vazia)

a. Imprima a notação pós-fixada
b. Retorne o resultado correspondente da expressão
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Arv {
    char op; //operadores
    float val;
    struct Arv *dir, *esq;
} Arv;

Arv* cria_no(int valor, char operador) {
    Arv* novo = (Arv*) malloc(sizeof(Arv));

    if(!novo) exit(1);

    novo->op = operador;
    novo->val = valor;
    novo->dir = novo->esq = NULL;

    return novo;
}

int calcula(Arv* raiz) {
    float direita, esquerda;

    if(!raiz->dir && !raiz->esq) {
        return raiz->val;
    } 

    esquerda = calcula(raiz->esq);
    direita = calcula(raiz->dir); 
    
    switch(raiz->op) {
        case '+': return esquerda + direita;
        case '-': return esquerda - direita;
        case '*': return esquerda * direita;
        case '/': return esquerda / direita;
        default:
            printf("\nOperador desconhecido..\n");
            exit(1);
    }
}

void limpa(Arv* raiz) {
    if(!raiz) return;

    limpa(raiz->esq);
    limpa(raiz->dir);

    free(raiz);
}

void pos_fix(Arv* raiz) {
    if(!raiz) return;

    pos_fix(raiz->esq);
    pos_fix(raiz->dir);

    if(!raiz->esq && !raiz->dir) {
        printf("%.2f ", raiz->val);
    } else {
        printf("%c ", raiz->op);
    }
}

int main() {
    /*
                           +
                         /   \
                        *     5
                      /   \
                     -     +
                    / \   / \    
                   6   3 4   1
    */

    Arv* raiz = cria_no( 0 , '+');
    raiz->dir = cria_no( 5, 'u');
    raiz->esq = cria_no( 0, '*');
    raiz->esq->esq = cria_no( 0, '-');
    raiz->esq->dir = cria_no(0, '+');
    raiz->esq->esq->esq = cria_no( 6, 'u');
    raiz->esq->esq->dir = cria_no( 3, 'u');
    raiz->esq->dir->esq = cria_no( 4, 'u');
    raiz->esq->dir->dir = cria_no( 1, 'u');

    pos_fix(raiz);

    printf("\nO resultado da expressao eh: %d\n", calcula(raiz));

    limpa(raiz);

    return 0;
}





