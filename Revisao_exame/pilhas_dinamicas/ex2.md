Discuta como implementar uma pilha usando duas filas. Qual é o tempo de execução das
operações de inserção e remoção na fila nesse caso ?


-------------------------------------------------------------------------------

Temos duas formas principais:

1. push barato, pop caro

adicionamos os elementos na fila normalmente 

ex: 1 <- 2 <- 3 <- 4 <- 5 <- 6 <- 7

Na estrutura fila FIFO, o elemento 1 seria removido primeiro. porém queremos remover o 7.
Para isso copiamos a lista 1 em outra, porém sem copiar o elemento 7, assim o Push tem execução de O(1) e o pop O(n);

2. pop barato, push caro.

Seguimos a mesmo lógica nesse caso, em que ao adicionar um elemento, adicionamos o elemento escolhido e depois copiamos a lista.

O pop apenas removeria o primeiro elemento da fila

Logo, o tempo de execução de push seria O(n) e o do pop seria O(1);
