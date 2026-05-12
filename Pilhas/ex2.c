/*
Refaça o programa anterior de forma que agora seja invertido a ordem das letras de cada palavra de
uma cadeia de caracteres, preservando a ordem das palavras. Por exemplo, dado o texto “ESTE
EXERCICIO E MUITO FACIL” a saída deve ser “ETSE OICICREXE E OTIUM LICAF”.
Use as funções push e pop.
*/

#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"

int main() {
    Pilha* p;
    int i, j, removido;
    char string[] = "ESTE EXERCICIO E MUITO FACIL ";

    p = criar();

    for (i = 0; string[i] != '\0'; i++) {   
        if((string[i] == ' ') || (string[i] == '\0')) {
            while(p->topo != -1) {
                pop(p, &removido);
                printf("%c", removido);
            }
            
            printf(" ");

        } else {
            push(p, string[i]);
        }
    }

    p = remover(p);

    return 0;
}