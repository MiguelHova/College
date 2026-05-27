/*
Representação e multiplicação de polinômios com lista encadeada ordenada.

Estrutura escolhida: Lista Encadeada Simples Ordenada (decrescente por expoente)

Justificativa:
    - Suporta qualquer grau sem desperdício de memória (ótimo para polinômios esparsos).
    - A ordenação decrescente facilita impressão e operações algébricas.
    - Inserção ordenada mantém o invariante da estrutura automaticamente.
*/

#include <stdio.h>
#include <stdlib.h>

//typedef

typedef struct Termo {
    float        coef;   /* coeficiente  (ex: 3.0 para 3x²) */
    int          exp;    /* expoente     (ex: 2   para 3x²) */
    struct Termo *prox;  /* ponteiro para o próximo termo    */
} Termo;

typedef Termo *Polinomio;

//funções auxiliares

    // Cria um novo nó com coeficiente e expoente dados
static Termo *novo_termo(float coef, int exp) {
    Termo *t = (Termo *)malloc(sizeof(Termo));
    if (!t) { perror("malloc"); exit(EXIT_FAILURE); }
    t->coef = coef;
    t->exp  = exp;
    t->prox = NULL;
    return t;
}

    //libera memória de um polinomio
void libera(Polinomio *p) {
    Termo *atual = *p, *tmp;
    while (atual) {
        tmp   = atual->prox;
        free(atual);
        atual = tmp;
    }
    *p = NULL;
}

    //se pá que imprime o polinômio
void imprime(Polinomio p) {
    if (!p) { printf("0\n"); return; }

    Termo *t = p;
    int primeiro = 1;

    while (t) {
        if (t->coef == 0.0f) { t = t->prox; continue; }

        /* Sinal */
        if (!primeiro) {
            printf(t->coef > 0 ? " + " : " - ");
        } else if (t->coef < 0) {
            printf("-");
        }

        float abs_coef = t->coef < 0 ? -t->coef : t->coef;

        if (t->exp == 0)
            printf("%.2f", abs_coef);
        else if (t->exp == 1)
            printf("%.2fx", abs_coef);
        else
            printf("%.2fx^%d", abs_coef, t->exp);

        primeiro = 0;
        t = t->prox;
    }
    printf("\n");
}

/*
Função principal 
  - Se já existe um termo com mesmo expoente, soma os coeficientes.
  - Termos com coeficiente resultante 0 são removidos.
  - A lista permanece ordenada em ordem decrescente de expoente.
*/

void insere(Polinomio *p, float coef, int exp) {
    if (coef == 0.0f) return;   /* ignorar termos nulos */

    Termo *ant  = NULL;
    Termo *atual = *p;

    /* Avança até encontrar o lugar correto (exp >= atual->exp) */
    while (atual && atual->exp > exp) {
        ant   = atual;
        atual = atual->prox;
    }

    /* Expoente já existe → soma coeficientes */
    if (atual && atual->exp == exp) {
        atual->coef += coef;

        /* Remover nó se coeficiente zerou */
        if (atual->coef == 0.0f) {
            if (ant)  ant->prox  = atual->prox;
            else      *p         = atual->prox;
            free(atual);
        }
        return;
    }

    /* Inserir novo nó entre ant e atual */
    Termo *novo = novo_termo(coef, exp);
    novo->prox  = atual;

    if (ant) ant->prox = novo;
    else     *p        = novo;
}

    //Multiplicação de dois polinômios
Polinomio multiplica(Polinomio a, Polinomio b) {
    Polinomio resultado = NULL;

    for (Termo *ta = a; ta; ta = ta->prox)
        for (Termo *tb = b; tb; tb = tb->prox)
            insere(&resultado, ta->coef * tb->coef, ta->exp + tb->exp);

    return resultado;
}

//main

int main(void) {
    /*
    Exemplo:
    A(x) = 3x² + 2x - 1
    B(x) = x  + 4
     
    Esperado:
    A × B = 3x³ + 14x² + 7x - 4
    */

    Polinomio A = NULL, B = NULL, C = NULL;

    // Inserindo fora de ordem para testar ordenamento
    insere(&A,  2.0f, 1);   /*  2x   */
    insere(&A,  3.0f, 2);   /*  3x²  */
    insere(&A, -1.0f, 0);   /* -1    */

    
    insere(&B,  4.0f, 0);   /*  4    */
    insere(&B,  1.0f, 1);   /*  x    */

    printf("A(x) = "); imprime(A);
    printf("B(x) = "); imprime(B);

    C = multiplica(A, B);
    printf("A(x) * B(x) = "); imprime(C);

    libera(&A);
    libera(&B);
    libera(&C);

    return 0;
}