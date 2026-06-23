/*
Escreva uma função que recebe um elemento como parâmetro e procure-o numa árvore ABB, retornando o seu nível.
utilize o protótipo: int nivel_ABB(No* no, int x);
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int val;
    struct No *esq, *dir;
} No;

No* criar(int valor) {
    No* novo = (No*) malloc(sizeof(No));

    if(!novo) exit(1);

    novo->val = valor;
    novo->dir = novo->esq = NULL;

    return novo;
}

void limpar(No* raiz) {
    if(!raiz) return;

    limpar(raiz->esq);
    limpar(raiz->dir);

    free(raiz);
}

void pre_order(No* raiz) {
    if(!raiz) return;

    printf("%d ", raiz->val);

    pre_order(raiz->esq);
    pre_order(raiz->dir);
}

// a lógica aqui é fazer com que a função sempre retorne o subnível relativo quando o valor é encontrado, assim:
int nivel_ABB(No* raiz, int x) {
    if(!raiz) return -1;  //sendo -1 o valor de retorno quando o elemento não existe na raiz.

    //encontrou na raiz da subárvore
    if(x == raiz->val) return 0;

    int sub;

    if(x < raiz->val) {
        sub = nivel_ABB(raiz->esq, x);
    } else {
        sub = nivel_ABB(raiz->dir, x);
    }

    if(sub == -1) return -1;

    return sub + 1;
}

int main() {
    No* raiz = NULL;
    int a, b;
    /*
        árvore               
            4                          
           / \                        
          2   5                      
         / \                            
        1   3                       
    */

    raiz = criar(4);
    raiz->esq = criar(2);
    raiz->dir = criar(5);
    raiz->esq->esq = criar(1);
    raiz->esq->dir = criar(3);

    a = nivel_ABB(raiz, 5);
    
    printf("o nivel do elemento 5 eh: %d ", a);
    
    b = nivel_ABB(raiz, 19);
    
    printf("o nivel do elemento 19 eh: %d", b);

    
    limpar(raiz);

    return 0;
}