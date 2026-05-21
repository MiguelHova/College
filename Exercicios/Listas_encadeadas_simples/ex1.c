/*
Compactação de lista, removendo nós adjacentes duplicados, para eliminar
dados redundantes. Percorrer a lista em uma única passagem.
Exemplo:
 Entrada: A → A → B → B → B → C → A
 Saída: A → B → C → A
*/

#include<stdio.h>
#include<stdlib.h>

//Criando structs
typedef struct Lista {
    char c;
    struct Lista *prox;
} Lista; 

//declaracao funcoes da lista

//para esse exercicio, add adicionará o nó no final da lista;
//Não foi criado a função del pois esta lógica foi adicionada em main();

Lista* init();
Lista* add(Lista* l, char c);
void show(Lista* l);

int main() {
    Lista *entrada, *p, *aux;

    entrada = init();
    

    entrada = add(entrada, 'A');
    entrada = add(entrada, 'A');
    entrada = add(entrada, 'B');
    entrada = add(entrada, 'B');
    entrada = add(entrada, 'B');
    entrada = add(entrada, 'C');
    entrada = add(entrada, 'A');

    show(entrada);
 
    aux = entrada;

    while(aux != NULL && aux->prox != NULL) {
        Lista *temp;
        
        temp = aux->prox;

        if(aux->c == temp->c){
            aux->prox= temp->prox;
            free(temp);
            continue;
        }
        
        aux = aux->prox;
    }

    show(entrada);

    return 0;
}

//definicao funcoes da lista

Lista* init() {
    return NULL;
}


Lista* add(Lista* l, char c) {
    Lista* novo, *aux;

    novo = (Lista*) malloc(sizeof(Lista));

    novo->c = c;
    novo->prox = NULL;

    aux = l;

    //Caso em que a lista está vazia
    if(!aux) {
        return novo;
    }


    for( ;aux->prox != NULL; aux = aux->prox);

    aux->prox = novo;


    return l;
}

void show(Lista* l) {
    Lista* aux;

    aux = l;

    if(!aux) {
        printf("\nLista vazia...\n");
        return;
    }

    printf("\nPrintando lista....\n");
    
    while(aux) {
        printf("%c ", aux->c);
        aux = aux->prox;
    }

    printf("\n");

}


