#ifndef PILHA_H
#define PILHA_H

typedef struct Pilha {
    struct Pilha *prox;
    int valor;
    char caractere;
}Pilha;

Pilha* init();
Pilha* push_int(Pilha* pilha, int val);
Pilha* push_char(Pilha* pilha, char c);
Pilha* pop_int(Pilha* pilha, int *x);
Pilha* pop_char(Pilha* pilha, char *c);
void show_int(Pilha *pilha);
void show_char(Pilha *pilha);
void liberar_pilha(Pilha *pilha);

#endif
