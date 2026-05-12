/*
Digamos que nosso alfabeto seja formado pelas letras a, b e c. Considere o seguinte conjunto de cadeias de
caracteres sobre nosso alfabeto: c, aca, bcb, abcba, bacab, aacaa, bbcbb, . . . Qualquer cadeia deste
conjunto tem a forma WcM, sendo que W é uma sequência de letras que só contém a e b e M é o
inverso de W, ou seja, M é W lido de trás para frente. Escreva um programa que determina se uma cadeia X
pertence ou não ao nosso conjunto, ou seja, determina se X é da forma WcM.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Pilha.h"

int main() {
    Pilha* p;
    char string[100], compare[100];
    int i, c;

    p = criar();

    printf("digite a string: ");
    fgets(string, 100, stdin);

    string[strcspn(string, "\n")] = '\0';

    i = 0;

    while(string[i] != 'c') {
        compare[i] = string[i];
        push(p, string[i]);
        i++;
    }
   
    compare[i] = 'c';
    
    i++;
    
    while(p->topo != -1) {
        pop(p, &c);
        compare[i] = c;
        i++;
    }
    
    compare[i] = '\0';
    
    printf("\nPrintando string original\n");

    for(i = 0; string[i] != '\0'; i++) {
        printf("%c", string[i]);
    }

    printf("\nPrintando a comparativa\n");

    for(i = 0; compare[i] != '\0'; i++) {
        printf("%c", compare[i]);
    }


    if(strcmp(string, compare) == 0) {
        printf("\nestao na forma WcM\n");
    
    } else {
        printf("\nnao estao na forma WcM\n");

    }


    return 0;
}