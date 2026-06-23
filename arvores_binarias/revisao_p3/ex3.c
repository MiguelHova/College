/*
Duas árvores binárias são semelhantes espelhadas se ambas forem vazias ou se ambas forem 
não vazias e a sub-árvore a esquerda de uma for semelhante espelhada à sub-árvore direita 
de outra.

Escreva uma função para criar uma árvore binária semelhante espelhada a uma dada árvore 
binária
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No {
    char val;
    struct No* dir, *esq;
}No;

// note que nó apenas cria o valor.
No* criar(int valor) {
    No* novo = (No*) malloc(sizeof(No));

    //encerra caso erro de alocação de memória
    if(!novo) exit(1);

    novo->val = valor;
    novo->dir = novo->esq = NULL;

    return novo;
}

// libera a memória alocada da árvore
void limpar(No* raiz) {
    if(!raiz) return;

    limpar(raiz->esq);
    limpar(raiz->dir);

    free(raiz);
}

// mostra árvore com notação préfixa (nó -> esquerda -> direita);
void pre_order(No* raiz) {
    if(!raiz) return;

    printf("%c ", raiz->val);

    pre_order(raiz->esq);
    pre_order(raiz->dir);

}



// cria uma árvore semelhante espelhada.
No* semelhante_espelhada(No* raiz) {
    // caso o nó seja nulo, consequentemente retorna NULL se raiz for nula
    if(!raiz) return NULL;

    // lógica caso não seja nula.
    No* novo = criar(raiz->val);

    novo->dir = semelhante_espelhada(raiz->esq);
    novo->esq = semelhante_espelhada(raiz->dir);

    return novo;
}

int main() {
    No* raiz, *espelhado;

    raiz = espelhado = NULL;

    /*
        árvore                 resultado esperado:
            a                          a
           / \                        / \
          b   c                      c   b   
         / \                            / \
        d   e                          e   d
    */

    raiz = criar('a');
    raiz->esq = criar('b');
    raiz->dir = criar('c');
    raiz->esq->esq = criar('d');
    raiz->esq->dir = criar('e');

    espelhado = semelhante_espelhada(raiz);
    
    pre_order(raiz);

    printf("\n\n");

    pre_order(espelhado);

    return 0;
}

