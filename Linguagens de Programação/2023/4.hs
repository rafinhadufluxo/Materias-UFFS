sum (map ((+2) . (**3)) [2, 3, 4])

-- map ((+2) . (**3)) [2, 3, 4] aplica a função ((+2) . (**3)) a cada elemento da lista.
-- Para 2: ((+2) . (**3)) 2 resulta em (+2) (2 ** 3) que é 2 + 8 igual a 10.
-- Para 3: ((+2) . (**3)) 3 resulta em (+2) (3 ** 3) que é 2 + 27 igual a 29.
-- Para 4: ((+2) . (**3)) 4 resulta em (+2) (4 ** 3) que é 2 + 64 igual a 66.

-- A lista resultante é [10, 29, 66].

-- sum [10, 29, 66] calcula a soma dos elementos da lista, que é 10 + 29 + 66 igual a 105.