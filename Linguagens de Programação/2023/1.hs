let my_fun 1 | null = 0
            | otherwise = (head 1) + my_func (tail 1)
    in (my_fun [42, 35, 68]) + 10


-- o main, a função my_fun é chamada com a lista [42, 35, 68]. 
-- Isso resultará na soma desses elementos, que é 42 + 35 + 68 = 145.

-- Em seguida, 10 é adicionado a esse resultado, resultando em 145 + 10 = 155.