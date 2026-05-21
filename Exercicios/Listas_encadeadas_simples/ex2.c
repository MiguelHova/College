/* 
Intercalação de Listas. Dadas duas listas simplesmente encadeadas, faça uma função que intercale as listas. 
A intercalação deve ser feita sem criar uma nova lista (L1 será a lista intercalada). 
Utilize apenas manipulação de ponteiros.

Exemplo:
    Entrada:
    o L1: A → B → C
    o L2: 1 → 2 → 3 → 4
    
     Saída:
    o A → 1 → B → 2 → C → 3 → 4
*/

#include<stdio.h>
#include<stdlib.h>

//typedef
typedef struct Lista {
    int dado;
    struct Lista *prox;
} Lista;

//funções init, show e add da lista encadeada
Lista *init();
Lista *add(Lista* l, int v);
Lista *pos(Lista *l, Lista *aux, int v);
void show(Lista* l);

int main() {
    Lista *l1, *l2, *aux1, *aux2;

    l1 = init();
    l2 = init();

    l1 = add(l1, 'A');
    l1 = add(l1, 'B');
    l1 = add(l1, 'C');
    
    // note que no terminal a printf mostraria apenas numeros por conta da lógica da função show();
    show(l1);
    
    l2 = add(l2, 1);
    l2 = add(l2, 2);
    l2 = add(l2, 3);
    l2 = add(l2, 4);
    
    show(l2);

    aux1 = l1;
    aux2 = l2;

    //lógica de intercalação;
    while(aux1 != NULL || aux2 != NULL) {
        Lista *novo, *temp;

        novo = (Lista*) malloc (sizeof(Lista));

        //tratamento de erro malloc
        if(!novo) {
            printf("\nErro ao alocar memoria\n");
            exit(1);
        }
       
        //Se L1 está vazia, printa o resto de L2 no fim, não é necessário fazer com l1 pois já estamos mexendo com a lista l1
        if(!aux1) {
            while(aux2) {
                l1 = add(l1, aux2->dado);
                aux2 = aux2->prox;
            }

            break;
        }

        if(!aux2) break;

        
        novo->dado = aux2->dado;
        novo->prox = aux1->prox;
        aux1->prox = novo;
        
        temp = aux2;
        
        aux2 = aux2->prox;
        aux1 = novo->prox;

        free(temp);
        temp = NULL;
    }

    show(l1);

    return 0;
}

//definições init, add e show da lista encadeada

Lista *init() {
    return NULL;
}

//Função add só precisa adicionar no final, por isso foi feito dessa forma
Lista *add(Lista* l, int v) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    Lista *aux;

    if(!novo) {
        printf("\nErro ao alocar memoria\n");
        exit(1);
    }

    novo->dado = v;
    novo->prox = NULL;

    aux = l;

    //Caso lista vazia
    if(!l) {
        return novo;
    }

    for(; aux->prox != NULL; aux = aux->prox);

    aux->prox = novo;

    return l;
}

//Não funciona com listas vazias
void show(Lista* l) {
    Lista* aux;

    aux = l;

    if(!aux) {
        printf("\nLista vazia...\n");
        return;
    }

    printf("\nPrintando lista....\n");
    
    while(aux) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }

    printf("\n");
}
