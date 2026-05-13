/*
Faça uma função que receba 3 filas (f, f_pares, f_impares) e separe todos os valores guardados
em f de tal forma que os valores pares sejam movidos para f_pares e os valores impares sejam
movidos para f_impares. No final f deve estar vazia, considere que f_pares e f_impares ainda
nao existem
*/

#include<stdio.h>
#include<stdlib.h>
#include"filas_dinamicas.h"

void par_impar(Fila* f, Fila* par, Fila* impar);

int main() {
    Fila *f, *f_pares, *f_impares;
    
    f = init();
    f_pares = init();
    f_impares = init();
    
    f = insert(f, 1);
    f = insert(f, 2);
    f = insert(f, 3);
    f = insert(f, 4);
    f = insert(f, 5);
    f = insert(f, 6);
    f = insert(f, 7);
    f = insert(f, 8);
    f = insert(f, 9);
    f = insert(f, 10);

    list(f);

    par_impar(f, f_pares, f_impares);

    list(f);
    list(f_pares);
    list(f_impares);

}

void par_impar(Fila* f, Fila* par, Fila* impar) {
    int n;

    while (f->inicio) {
        if ((f->inicio->info % 2) == 0) {
            par = insert(par, f->inicio->info);
        } else {
            impar = insert(impar, f->inicio->info);
        }

        remover(f, &n);
    }
}







