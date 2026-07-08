Considere o seguinte conjunto de números 1234 e as seguintes operações:
(a) inserir o número 1 em uma pilha
(b) inserir o 2 na pilha
(c) retirar o 2 da pilha
(d) inserir o 3 na pilha
(e) inserir o 4 na a pilha
(f) retirar o 4 da pilha
(g) retirar o 3 da a pilha
(h) retirar o 1 da pilha
A sequência de saídas do procedimento acima e 2431. Considere agora a sequência
123456.
(a) Podemos obter as sequências 325641 e 154623 utilizando um processo semelhante
ao do exemplo anterior?
(b) Se I e R representam respectivamente inserção e remoção da pilha, o ex. acima
pode ser descrito como IIRIIRRR. Se possível descreva as sequências do item (a) em termos
de I e R.
(c) Qual seria uma regra simples para analisar se uma sequência de I's e R's é válida?
---------------------------------------------------------------------------------------------
RESPOSTA


a>

pode-se obter a Saída 325641 da seguinte forma:

inserir 1, inserir 2, inserir 3, retirar 3, retirar 2, inserir 4, inserir 5, retirar 5
inserir 6, retirar 6, retirar 4, retirar 1


Agora a saída 154623 não é possível (nota-se que o 3 deve ser retirado da pilha antes do 2)

inserir 1, retirar 1, inserir 2, inserir 3, inserir 4, inserir 5, retirar 5, retirar 4, inserir 6, retirar 6, retirar 3, retirar 2

b>

sequencia 325641:
IIIRRIIRIRRR

c> 

Podemos avaliar com um contador. Para cada I, incrementa-se 1, para cada R, decrementa-se 1.
A soma final deve ser 0 (se soma < 0, houve remoção vazia. Se soma > 0, há elementos pendentes para remoção).
