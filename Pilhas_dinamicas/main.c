#include<stdio.h>
#include<stdlib.h>
#include"pilha_dinamica.h"

int main() {
    Pilha* p;
    int removido;

    p = init();

    p = push(p, 10);
    p = push(p, 5);
    p = push(p, 4);
    p = push(p, 7);
    p = push(p, 12);

    list(p);

    p = pop(p, &removido);

    list(p);

    remover(p);
    p = NULL;
    
}