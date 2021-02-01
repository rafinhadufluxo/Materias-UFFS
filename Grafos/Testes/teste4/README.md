# Prove que o algoritmo de Kruskal produz uma árvore geradora mínima.

- O algoritmo de Kruskal busca uma arvore geradora minima para um grafo relacionado com peso, podendo ser encontrado 
como um subconjunto de arestas que forma uma arvore que inclui vertices, mostrando o peso total e dados de somatoria 
do peso das arestas, mas seu objetivo e selecionar arestas de menor custo de um grafo conexo com custo, mas não gera 
circuitos, pois a arvore tenha sido criada. Para estrutura de dados usando o Kruskal, podemos ver a complexidade de 
tempo igual a O(m log n), pois m representa o numero de arestas e n mostra numero de vertices.

- Desde a T é um MST, temos que w ( e ) ≥ w ( f). Além disso, desde e foi escolhido pelo 
algoritmo de Kruskal, deve ter peso mínimo, então w ( e ) ≤ w ( f), o que por sua vez 
implica que w ( e ) = w ( f). Conseqüentemente,T′ também é um MST, mas tem mais uma 
vantagem em comum com S do que faz T, mas tínhamos escolhido T de modo que tinha o 
maior número de arestas em comum com S, então chegamos a uma contradição. Concluimos 
que S é mínimo.
