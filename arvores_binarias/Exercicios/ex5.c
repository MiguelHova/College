/*
Implemente uma função que retorne a quantidade de folhas de uma árvore com número
váriavel de filhos (árvore genérica)
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    char caractere;
    struct No* filho;
    struct No* irmao;
}No;

No* criar_no(char c) {
    No* novo = (No*) malloc(sizeof(No));

    if(!novo) exit(1);

    novo->caractere = c;
    novo->filho = NULL;
    novo->irmao = NULL;

    return novo;
}

void add_filho(No* p, No* f) {
    if(!p->filho) {
        p->filho = f; 
        return;
    }

    No* aux = p->filho;

    for( ; aux->irmao; aux = aux->irmao);

    aux->irmao = f;
}

int conta_folhas(No* raiz) {
    No* aux;
    int cont = 0;

    if(!raiz) return 0;
    if(!raiz->filho) return 1;
    
    if(!raiz->filho->irmao) return conta_folhas(raiz->filho);

    for(aux = raiz->filho; aux; aux = aux->irmao) {
        cont += conta_folhas(aux);
    }

    return cont;
}

int main() {
    No* raiz = NULL;
    No* B, *C, *D, *E, *F, *G, *H, *I;

     /*
                     a
               /     |    \ 
              b      c     i
             / \   / \ \
            d   e f   g h
    */

    raiz = criar_no('a');
    B = criar_no('b');
    C = criar_no('c');
    D = criar_no('d');
    E = criar_no('e');
    F = criar_no('f');
    G = criar_no('g');
    H = criar_no('h');
    I = criar_no('i');

    add_filho(raiz, B);
    add_filho(raiz, C);
    add_filho(B, D);
    add_filho(B, E);
    add_filho(C, F);
    add_filho(C, G);
    add_filho(C, H);
    add_filho(raiz, I);

    printf("A quantidade de folhas eh: %d", conta_folhas(raiz));

}
