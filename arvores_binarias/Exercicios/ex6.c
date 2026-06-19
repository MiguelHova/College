/*
Implemente uma função que compare se duas árvores genéricas são iguais:
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    char dado;
    struct No* filho;
    struct No* irmao;
}No;

No* criar_no(char c) {
    No* novo = (No*) malloc(sizeof(No));

    if(!novo) exit(1);

    novo->dado = c;
    novo->filho = NULL;
    novo->irmao = NULL;

    return novo;
}

void limpa(No* raiz) {
    if(!raiz) return;

    limpa(raiz->filho);
    limpa(raiz->irmao);

    free(raiz);
}

void add_filho(No* p, No* f) {
    No* aux = p->filho;
    
    if (!p->filho) {
        p->filho = f;
        return;
    }
    
    for( ; aux->irmao; aux = aux->irmao);

    aux->irmao = f;
}

int compare(No* raiz1, No* raiz2) {
    
    if(!raiz1 && !raiz2) {
        return 1;
    } else if(!raiz1 || !raiz2) {
        return 0;
    }
    
    if(raiz1->dado != raiz2->dado) return 0;

    return compare(raiz1->filho, raiz2->filho) && compare(raiz1->irmao, raiz2->irmao);
}

int main() {
    No*raiz1, *raiz2;
    No*A1, *B1, *C1, *D1, *E1, *F1, *G1, *H1, *I1;
    No*A2, *B2, *C2, *D2, *E2, *F2, *G2, *H2, *I2;
    
    /*
                     a
               /     |    \ 
              b      c     i
             / \   / \ \
            d   e f   g h
    */

    //Criando árvore 1
    A1 = criar_no('a');
    B1 = criar_no('b');
    C1 = criar_no('c');
    D1 = criar_no('d');
    E1 = criar_no('e');
    F1 = criar_no('f');
    G1 = criar_no('g');
    H1 = criar_no('h');
    I1 = criar_no('i');

    add_filho(A1, B1);
    add_filho(A1, C1);
    add_filho(B1, D1);
    add_filho(B1, E1);
    add_filho(C1, F1);
    add_filho(C1, G1);
    add_filho(C1, H1);
    add_filho(A1, I1);
    
    
    //Criando árvore 2
    A2 = criar_no('a');
    B2 = criar_no('b');
    C2 = criar_no('c');
    D2 = criar_no('d');
    E2 = criar_no('e');
    F2 = criar_no('f');
    G2 = criar_no('g');
    H2 = criar_no('h');
    I2 = criar_no('i');

    add_filho(A2, B2);
    add_filho(A2, C2);
    add_filho(B2, D2);
    add_filho(B2, E2);
    add_filho(C2, F2);
    add_filho(C2, G2);
    add_filho(C2, H2);
    add_filho(A2, I2);

    raiz1 = A1;
    raiz2 = A2;

    if(compare(raiz1, raiz2)) {
        printf("iguais");
    } else {
        printf("diferente");
    }
    
    limpa(raiz1);
    limpa(raiz2);

    return 0;
}

