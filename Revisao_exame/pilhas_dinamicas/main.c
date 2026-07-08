//testando se as funções de pilha.c estão funcionando

#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

int main() {
    Pilha* p;
    int x;

    p = init();

    p = push(p, 3);

    show(p);

    p = push(p, 4);
    p = push(p, 7);

    show(p);
   
    p = pop(p, &x);

    show(p);

    printf("\nO ultimo valor removido foi %d", x);

    return 0;
}

