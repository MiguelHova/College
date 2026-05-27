/*
 Um número binário b1b2...bn, em que cada bi é 0 ou 1, tem o valor decimal . 
 Esse número pbinário pode ser representado pela lista b1, b2, ..., bn. Essa lista, por sua vez, 
 pode ser representada como uma lista encadeada de nós do tipo nó. Escreva um programa que adicione 1 ao 
 número binário digitado pelo usuário. Faça o incremento recursivo. 
 Use lista circular duplamente encadeada para facilitar a implementação. 
*/

#include<stdio.h>
#include<stdlib.h>

//typedef
typedef struct lista {
    int bin;
    struct lista* prox;
    struct lista* ant;
} Lista;

//Funções adiciona nó e mostrar

    //insert adiciona sempre ao final;
Lista *insert(Lista* l, int b) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    Lista *aux;

    if(b != 0 && b != 1) {
        printf("\nDigite um numero valido\n");
        free(novo);
        return l;
    }

    novo->bin = b;
    novo->prox = NULL;    

    //Caso lista vazia
    if(!l) {
        novo->ant = NULL;
        return novo;
    }

    //aux agora tem o endereço do ultimo elemento
    for(aux = l ; aux->prox; aux = aux->prox);

    novo->ant = aux;
    aux->prox = novo;

    return l;
}

void show(Lista *l) {
    


    printf("\nBin:");

    while(l) {
        printf(" %d", l->bin);
        l = l->prox;
    }

    printf("\n");
}



//main

int main() {
    Lista *lista;
    int choice = 1;

    lista = NULL;

    printf("\n---------------------------------");
    printf("\nDigite -1 para parar de rodar");
    printf("\n---------------------------------\n\n");

    while(1) {
        
        printf("\nDigite o binario (um por um): ");
        scanf("%d", &choice);

        if(choice == -1) break;

        lista = insert(lista, choice);
    }
    
    show(lista);

    return 0;
}
