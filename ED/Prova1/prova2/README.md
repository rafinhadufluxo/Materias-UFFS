#Deque

Uma das estruturas de dados vistas em aula foi uma fila. Uma maneira alternativa de definir uma fila é dada abaixo.

Uma fila é uma estrutura de dados que consiste em uma sequência de itens tal que as operações de inserir e remover um item desta sequência são feitas da seguinte maneira:

        - inserção: sempre insere o item no fim da sequência.
        - remoção: sempre remove o item do início da sequência.

Existem algumas variações interessantes de uma fila. Uma delas, denominada deque (double-ended queue), é uma fila na qual a inserção e a remoção de um item podem ocorrer tanto no início quanto no fim da fila. Portanto, podemos realizar as seguintes quatro operações em uma deque:

        - inserir um novo item no início;
        - inserir um novo item no fim;
        - remover um item do início;
        - remover um item do fim.

Nesta tarefa de laboratório, você deve implementar uma deque cujos itens são valores inteiros. Você deve fazer isso utilizando uma lista duplamente encadeada e escrevendo as seguintes funções, que devem executar na deque as operações indicadas:

        - função insereInicioDeque: insere um novo item no início da deque;
        - função insereFimDeque: insere um novo item no fim da deque;
        - função removeInicioDeque: remove um item do início da deque;
        - função removeFimDeque: remove um item do fim da deque;
        - função inicializaDeque: inicializa a deque;
        - função liberaDeque: libera a memória alocada para a deque.

As funções removeInicioDeque e removeFimDeque, além de remover um item da deque, devem imprimir uma linha contendo apenas o item removido da deque. A função liberaDeque, além de liberar a memória alocada para a deque, deve imprimir uma linha contendo apenas a quantidade de itens que estavam presentes na deque antes da sua memória ser liberada.

*Entrada*

A primeira linha da entrada contém um inteiro N (N ≥ 2), que indica a quantidade de operações a serem executadas na deque. Cada uma das N linhas seguintes contém um inteiro O (1 ≤ O ≤ 6) e, caso O seja igual a 2 ou 3, O será seguido de um espaço em branco e um inteiro I. Os inteiros O e I representam o seguinte:

        - Se O é igual a 1, deve ser executada a operação de inicializar a deque (função inicializaDeque);
        - Se O é igual a 2, deve ser executada a operação de inserir o item I no início da deque (função insereInicioDeque);
        - Se O é igual a 3, deve ser executada a operação de inserir o item I no fim da deque (função insereFimDeque);
        - Se O é igual a 4, deve ser executada a operação de remover um item do início da deque (função removeInicioDeque);
        - Se O é igual a 5, deve ser executada a operação de remover um item do fim da deque (função removeFimDeque);
        - Se O é igual a 6, deve ser executada a operação de liberar a memória alocada para a deque (função liberaDeque);

A operação de inicializar a deque (O igual a 1) sempre será a primeira operação especificada na entrada e ocorrerá apenas uma vez. A operação de liberar a memória alocada para a deque (O igual a 6) sempre será a última operação especificada na entrada e ocorrerá apenas uma vez.

*Saída*

A saída deve consistir no seguinte:

Para cada execução da operação de remover um item do início da deque ou da operação de remover um item do fim da deque, o seu programa deve imprimir uma linha contendo o item removido da deque – isto deve ser feito dentro das funções removeInicioDeque e removeFimDeque (veja a descrição acima). Quando for executada a operação de liberar a memória alocada para a deque, o seu programa deve imprimir uma linha contendo a quantidade de itens que estavam presentes na deque antes da sua memória ser liberada – isto deve ser feito dentro da função liberaDeque (veja a descrição acima).

Exemplo de execução 1.

        8
        1
        3 63
        3 57
        3 90
        4
        4
        4
        6

Exemplo de saida da execução 1.

        63
        57
        90
        0

Exemplo de execução 2

        8
        1
        3 63
        3 57
        3 90
        5
        5
        5
        6

Exemplo de saida da execução 2.

        90
        57
        63
        0
