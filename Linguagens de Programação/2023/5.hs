let x = 3 * 3
    in case ((even . succ) x, odd (x - 1)) of
        (False, True) -> x - 5
        (True, False) -> 5 - x
        (True, True) -> 3 - x
        _ -> x - 3


-- let x = 3 * 3 atribui o valor 9 à variável x.

-- in case ((even . succ) x, odd (x - 1)) of 
-- começa um caso que verifica as condições com base nos valores de even . succ x e odd (x - 1).

-- (False, True) é o resultado da avaliação dessas condições com os valores de x.

-- No caso do (False, True), a primeira cláusula (False, True) -> x - 5 é correspondida, 
-- o que significa que o valor de x (que é 9) será subtraído por 5, resultando em 4.

-- Portanto, o resultado da execução desta linha é 4.