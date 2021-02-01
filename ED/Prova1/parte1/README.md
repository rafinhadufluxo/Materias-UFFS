# Brinde FACE

A FACE em 2015 está apoiando a terceira edição da Maratona de Programação, mas desta vez a organização solicitou sua ajuda para criar um sistema de sorteio utilizando as letras da palavra FACE. Como a feira utiliza uma proposta diferenciada e alegre, cada participante que entra na feira ganha 4 letras, uma de cada cor e em formato de bloco de madeira, conforme Figura 1, e deve inseri-las num painel. Se, no momento da inserção, as 4 letras formarem o contrário das 4 últimas letras, o visitante ganhará um brinde.

Por exemplo: suponha que já tiveram 3 participantes que entraram na feira e o painel ficou da seguinte forma: F A C E E C F A A C F E A C E F. Note que sempre que o painel fica vazio, assim como no início do evento, as letras F A C E são inseridas pela organização do evento. Agora, na entrada do quarto participante, ele inseriu as letras F E C A e, com isso, receberá um brinde por fechar o contrário de A C E F. Após essa situação, o painel deve ficar F A C E E C F A A C F E.

Escreva um algoritmo que, dadas as letras recebidas e inseridas pelos participantes, diga quantos participantes ganharam brindes. Lembre-se que sempre que o painel fica vazio as letras F A C E são inseridas pela organização do evento.

Sugestão: Para representar as letras recebidas por um participante da feira, use uma struct que contenha 4 membros do tipo char.

*Entrada*

A primeira linha de cada caso de teste contém um inteiro N (1 ≤ N ≤ 100), representando o número de visitantes que vão receber as letras. Em cada uma das N linhas seguintes deve ser informada a combinação das 4 letras que o visitante deseja inserir no painel, separadas por espaço.

*Saída*

Para cada grupo de visitantes, deve ser informado quantos destes receberão brindes.

*Exemplo de execução 1*

        4
        E C F A
        A C E F
        F E C A
        A F C E

*Exemplo de saida da execução 1*

        2

*Exemplo de execução 2*

        3
        E A C F
        A F C E
        E F C A

*Exemplo de saida da execução 2*

        0

