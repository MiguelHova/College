/*
O seguinte método para codificar despachos diplomáticos foi adotado: primeira etapa –
todas sequências não-vogais incluindo o espaço em branco e os caracteres de pontuação
são invertidas; segunda etapa - a mensagem inteira resultante é invertida dando origem à
mensagem codificada. Por exemplo, a mensagem original
PROBLEMAS HIPER-INTERESSANTES.
passa a ser:
RPOLBEMAH SIPE-RITNERESSATNE.S
após a primeira etapa. A seguir, na segunda etapa ela é codificada como:
S.ENTASSERENTIR-EPIS HAMEBLOPR
Faça um programa que contenha funções para codificar e decodificar mensagens
recebidas. O usuário deverá escolher o que deseja fazer, ou seja, ele pode entrar com uma
mensagem sem codificação e o programa devolverá a mensagem codificada, ou entrar
com uma mensagem codificada como a mensagem abaixo:

TS.ECOXES ES TRIAR MAMPRO CEUGENSO CE SE. VENTERGU
e o programa devolvê-la decodificada. Use alocação dinâmica (cada nó deverá conter um
caractere no campo de info), pois o embaixador não sabe a priori o tamanho da
mensagem.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include"pilha.h"

Pilha* string_em_pilha(char *c);
void coder(Pilha* p);
void decoder(Pilha* p);
int eh_vogal(char c);

int main() {
    Pilha *p = init();
    Pilha *f = init();

    char* string_decodificada = "PROBLEMAS HIPER-INTERESSANTES.";
    char* string_codificada = "S.ENTASSERENTIR-EPIS HAMEBLOPR";

    p = string_em_pilha(string_decodificada);

    coder(p);

    f = string_em_pilha(string_codificada);

    decoder(f);

    return 0;
}

int eh_vogal(char c) {
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void coder(Pilha* p) {
    Pilha* aux, *aux2;
    char c;

    //inicializando pilha auxiliar
    aux = aux2 = init();
   
    while(p) {
        if(eh_vogal(p->caractere)) {
            while(aux) {
                aux = pop_char(aux, &c);
                aux2 = push_char(aux2, c);
            }

            p = pop_char(p, &c);
            aux2 = push_char(aux2, c);

        } else{
            p = pop_char(p, &c);
            aux = push_char(aux, c);

        }
    }

    while(aux) {
        aux = pop_char(aux, &c);
        aux2 = push_char(aux2, c);
    }

    while(aux2) {
        aux2 = pop_char(aux2, &c);
        aux = push_char(aux, c);
    }

    printf("\n");
    printf("Mensagem codificada: ");

    while(aux) {
        aux = pop_char(aux, &c);
        printf("%c", c);
    }

    printf("\n");
}

void decoder(Pilha* p) {
    Pilha* aux1, *aux2;
    char c;

    aux1 = aux2 = init();

    //transforma aux1 no passo 2:
    while(p) {
        p = pop_char(p, &c);
        aux1 = push_char(aux1, c);
    }

    //aux2 fica com o passo 1 invertido (igual a saida correta)
    while(aux1) {
        if(eh_vogal(aux1->caractere)) {
            while(aux2) {
                aux2 = pop_char(aux2, &c);
                p = push_char(p, c);
            }

            aux1 = pop_char(aux1, &c);
            p = push_char(p, c);

        } else {
            aux1 = pop_char(aux1, &c);
            aux2 = push_char(aux2, c);
        }

    }

    while(aux2) {
        aux2 = pop_char(aux2, &c);
        p = push_char(p, c);
    }

    printf("\n");
    printf("Mensagem decodificada: ");

    while(p) {
        p = pop_char(p, &c);
        printf("%c", c);
    }
 
    printf("\n");
}

Pilha* string_em_pilha(char *c) {
    Pilha* p = init();
    int i = 0;

    //string vazia
    if(c[0] == '\0') return NULL;

    while(c[i] != '\0') {
        p = push_char(p, c[i]);
        i++;
    }

    return p;
}


