/*Faça uma programa que use uma pilha para
inverter a ordem das letras da frase. Por
exemplo, dado o texto “ESTE EXERCICIO E
MUITO FACIL” a saida deve ser “LICAF OTIUM
E OICICREXE ETSE”. Use as funções push e
pop.*/

#include<stdio.h>
#include<stdlib.h>
#include "Pilha.h"

int main() {
    Pilha* p;
    char frase[] = "ESTE EXERCICIO EH MUITO FACIL";
    int i, removido;

    p = criar();

    for(i = 0; frase[i] != '\0'; i++) {
        push(p, frase[i]);
    }

    printf("\n");

    while(p->topo != -1) {
        pop(p, &removido);
        printf("%c", removido);
    }

    p = remover(p);

    return 0;
}

