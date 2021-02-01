# Prove que o algoritmo de Prim produz uma árvore geradora mínima.

Algoritmo de prim (algoritmo guloso) é usado para encontrar uma arvoré geradora minima, que encontra um subgrafo do grafo orginal 
no qual a soma total das arestas é mimizada e todos os vertices são interligados(grafico), com isso ressatalmos que o prim é 
um algoritmo de busca para menor vertice no grafo.

Segundo Paulo Feofiloff, "No início de cada iteração do algoritmo de Prim vale a seguinte propriedade invariante:
cada aresta t de T tem custo mínimo no leque da componente conexa de T−t que contém s.
A propriedade vale trivialmente no ínicio da primeira iteração. Suponha agora que a propriedade vale no início de uma iteração 
qualquer que não a última. Nesse iteração, o algoritmo escolhe uma aresta e de custo mínimo na franja de T. Precisamos mostrar 
que, no fim dessa iteração, a propriedade invariante está satisfeita com T+e no papel de T.
Para cada aresta t de T o a componente conexa de (T+e)−t que contém s é idêntica à componente conexa de T−t que contém s e portanto 
o custo de t é mínimo no leque dessa componente por hipótese.  Resta apenas considerar o leque da componente conexa de (T+e)−e que 
contém s. Esse leque é, exatamente, a franja de T e portanto o custo de e é mínimo no leque por construção.  Isso encerra a prova 
do invariante.

No início da última iteração, T é uma árvore geradora. Graças à invariante, T satisfaz o critério de minimalidade de MSTs. Logo, T é 
uma MST."


*Referências:*<br>

https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/prim.html#prim-is-correct <br>
https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/solutions/prim00.html
