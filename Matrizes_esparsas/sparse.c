#include<stdio.h>
#include<stdlib.h>
#include"sparse.h"

Node** insert(Node** m, int row, int col, int val) {
    Node* no;
    Node* aux1, *aux2;
    


    no = (Node*) malloc(sizeof(Node));
    
    if(!no) {
        printf("\nMemory allocation error\n");
        exit(1);
    }
    
    
    no->column = col;
    no->value = val;
    no->prox = NULL;
    
    //if row is empty;
    if(!m[row]) {
        m[row] = no;
        return m;
    }
    
    //if insertion is in the start;
    if(m[row]->column > col) {
        

        aux1 = m[row];
        m[row] = no;    
        no->prox = aux1;
        return m;
    }
    
    //insertion in the middle or end
    aux1 = m[row];
    aux2 = m[row]->prox;
    
    while(aux2) {
        
        //if you try to add in an existing node (in other words, avoids duplicates).
        if(aux2->column == col) {
            aux2->value = val;
            free(no);
            return m;
        }

        if(aux2->column > col) {
            aux1->prox = no;                          
            no->prox = aux2;
            return m;
        }
        
        aux1 = aux1->prox;
        aux2 = aux2->prox;
        
    }
    
    //this happens when the insertion is in the end
    aux1->prox = no;
    return m;
    
}


Node** init(int rows) {
    int i;
    Node** m;

    m = (Node**) malloc(rows * sizeof(Node*));      
    
    if(!m) {
        printf("\nMemory allocation error\n");
        exit(1);
    }
    
    for(i=0; i<rows; i++) {
        m[i] = NULL;
    }

    return m;
}

void show(Node **m, int rows) {
    int i;
    Node* aux;
    
    
    printf("\n");
    
    for(i = 0; i < rows; i++) {
        aux = m[i];
        
        if(!aux) continue;

        printf("\n");
        
        while(aux) {
            printf("Linha: %d, coluna: %d, valor %d\n", i+1, aux->column, aux->value);
            aux = aux->prox;    
        }
    }
}


void liberate(Node **m, int rows) {
    int i;
    Node *aux1, *aux2;
    
    for(i=0; i<rows; i++) {
        
        //if row is empty
        if(!m[i]) {
            continue;
        }

        //if row only has one element
        if(!m[i]->prox) {
            free(m[i]);
            m[i] = NULL;
            continue;
        }

        //other cases
        aux1 = m[i];
        aux2 = m[i]->prox;

        while(aux2) {

            free(aux1);

            aux1 = aux2;
            aux2 = aux2->prox;
        }

        free(aux1);
    }

    free(m);
    m = NULL;
}

