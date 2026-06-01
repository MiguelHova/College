#ifndef SPARSE_H
#define SPARSE_H

typedef struct node {
    int column;
    int value;
    struct node *prox;
}Node;

Node** insert(Node** m, int row, int col, int val);
Node** init(int rows);
void show(Node **m, int rows);
void liberate(Node **m, int rows);

#endif




