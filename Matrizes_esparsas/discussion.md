So... I'm writing this discussion because this topic is a little bit different from what I'm used to (and was expecting from DSA). 

First of all, let's explain what a sparse matrix is. To do that, imagine the following situation: you, as a developer, have a problem where you need to look for better efficiency in your code and you come across an n×n matrix where most of the elements are zero (which, in most cases, means they are not relevant). This means the algorithm is wasting a lot of memory. To solve that, sparse matrices were created.

The way they do that, is to just store the elements of the matrix with its indexes (ignoring the zeros). Usually, using tuples.

sparse.c will show a way to implement that in c lenguage, using structs and lists to store the elements.