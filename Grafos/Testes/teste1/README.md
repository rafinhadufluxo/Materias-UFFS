Teste 1: 
Contagem de arestas em grafo completo.

Quantas arestas tem em um grafo completo de 10 vértices?

Quantas arestas tem em um grafo completo de n vértices?

Prove.

Respondendo essas questões.

O algoritmo de Dijkstra permite que você calcule o caminho mais curto 
entre um nó (você escolhe qual) e todos os outros nós no gráfico.

Entrada: Gráfico e um vértice de origem.
Saída: Distância mais curta para todos os vértices. Se houver 
um ciclo de peso negativo, as distâncias mais curtas não são calculadas, 
o ciclo de peso negativo é relatado.

1) Esta etapa inicializa as distâncias da fonte a todos os vértices como 
infinitas e a distância até a própria fonte como 0. Crie um array dist [] 
de tamanho | V | com todos os valores como infinitos, exceto dist [] 
onde  o vértice de origem.

2) Esta etapa calcula as distâncias mais curtas. Faça o seguinte | V | -1 
vezes onde | V | é o número de vértices em determinado gráfico.
… .. a) Faça o seguinte para cada borda uv
……………… Se dist [v]> dist [u] + peso da borda uv, então atualize dist [v]
………………… .dist [v ] = dist [u] + peso da borda uv
3)Atualize o valor da distância de todos os vértices adjacentes de u. Para 
atualizar os valores de distância, itere por todos os vértices adjacentes. 
Para cada vértice adjacente v, se a soma do valor da distância de u (da fonte) 
e o peso da aresta uv, for menor que o valor da distância de v, então atualize 
o valor da distância de v.


*Como é que isso funciona?* 

Como outros problemas de programação dinâmica, o algoritmo calcula os caminhos 
mais curtos de maneira ascendente. Ele primeiro calcula as distâncias mais 
curtas que têm no máximo uma borda no caminho. 

<p align="center">
    <img  src="Captura de tela de 2020-12-16 23-13-44.png" title="Logo do curso"><br />
   
</p>

