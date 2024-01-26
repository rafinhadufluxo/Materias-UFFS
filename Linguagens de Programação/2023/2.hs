fold (\x y -> x + (y * 2)) 0 [20, 30, 40]




-- execução

-- fold (\x y -> x + (y * 2)) (0 + (20 * 2)) [30, 40] (Aplicou a função à primeira elemento da lista)
-- fold (\x y -> x + (y * 2)) ((0 + (20 * 2)) + (30 * 2)) [40] (Aplicou a função ao segundo elemento da lista)
-- fold (\x y -> x + (y * 2)) (((0 + (20 * 2)) + (30 * 2)) + (40 * 2)) [] (Aplicou a função ao terceiro elemento da lista)

-- Agora, a lista está vazia, e o resultado final é o acumulador:

-- (((0 + (20 * 2)) + (30 * 2)) + (40 * 2)) = (0 + 40 + 60 + 80) = 180

-- Portanto, o resultado da expressão fold (\x y -> x + (y * 2)) 0 [20, 30, 40] é 180.