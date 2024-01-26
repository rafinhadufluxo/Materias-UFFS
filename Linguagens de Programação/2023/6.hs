{-- 
a) Para calcular a soma de todos os pagamentos em dinheiro realizados, 
você pode usar a função foldl para percorrer o relatório e acumular os valores dos pagamentos em dinheiro. 
Aqui está a função somaPgtoDinheiro:

--}

somaPgtoDinheiro :: Relatorio -> Double
somaPgtoDinheiro relatorio = foldl (\acc (_, desc, valor) -> if desc == PgtoDinheiro then acc + valor else acc) 0 relatorio

{-- 
b) Para retornar apenas os registros de pagamento através de cartão realizados, 
você pode usar a função filter em conjunto com uma função que verifica se a descrição é igual a PgtoCartao. 
Aqui está a função:
--}

pagamentosCartao :: Relatorio -> Relatorio
pagamentosCartao relatorio = filter (\(_, desc, _) -> desc == PgtoCartao) relatorio

{-- 
c) Para criar um tipo de dado Filial que associe um código numérico com o relatório de movimentações, 
você pode definir o tipo Filial da seguinte forma:
--}

type Filial = (Int, Relatorio)

{-- 
d) Agora, para calcular a diferença entre o valor total de pagamentos (em dinheiro e cartão) 
e o valor total de sangrias realizadas para cada filial, você pode criar uma função que percorre a 
lista de filiais e calcula essa diferença para cada uma. Aqui está a função:
--}

diferencaValores :: [Filial] -> [(Int, Double)]
diferencaValores filiais = map (\(codigo, relatorio) -> (codigo, calculaDiferenca relatorio)) filiais
  where
    calculaDiferenca relatorio = totalPagamentos relatorio - totalSangrias relatorio
    totalPagamentos relatorio = foldl (\acc (_, desc, valor) -> if desc == PgtoDinheiro || desc == PgtoCartao then acc + valor else acc) 0 relatorio
    totalSangrias relatorio = foldl (\acc (_, desc, valor) -> if desc == Sangria then acc + valor else acc) 0 relatorio


{-- 

6. Em uma aplicação que simula um caixa de supermercado, um relatório de movimentos é representado por uma lista. 
Cada movimento tem uma data (uma string), uma descrição 
(Sangria, para retirada de dinheiro e PgtoDinheiro e PgtoCartao para pagamentos em dinheiro e cartão), 
o valor e o total movimentado (antes da movimentação).

data DescMov = Sangria | PgtoDinheiro | PgtoCartao
type Data = String
type Movimento = (Data, DescMov, Double) DoWBLE)
type Relatorio = [ Movimento ]

Exemplo de histórico de movimento:
exemplo :: Relatorio

exemplo = [ ("1/10/23", PgtoDinheiro, 100, 1000),
("1/10/23", PgtoCartao, 20, 1100), 
("2/10/23", Sangria, 500, 1120),
("3/10/23", PgtoDinheiro, 50, 620), 
("5/10/23", PgtoDinheiro, 10, 670),
("5/10/23", PgtoCartao, 100, 680)

a) Escreva uma função somaPgtoDinheiro :: Relatorio -> Double 
    que recebe um relatório de movimento e resulta na soma de todos os pagamentos em dinheiro realizados.

b) Utilize uma função de alta ordem para retornar apenas os registros de pagamento através de cartão realizados.

c) Crie outro tipo de dado Filial que associe uma filial (código numérico) com o relatório de movimentações.

d)Faça uma função que receba uma lista de Filiais ([Filial] - criada no item c) 
    e apresente, para cada uma, a diferença entre o valor total de pagamentos (em dinheiro e cartão) 
    e o valor total de sangrias realizadas. Se preciso, utilize definições locais, 
    outras funções, ou funções de alta ordem para auxiliar no processo.

--}