#Acadêmicas: Nubia Pontel e Rafaelle Arruda
#1- QUESTAO


.data
	vetor: 
		.word 4, 9, 2, 3, 7, 8, 1
.text
main:
	addi a1, zero, 7                           #tamanho
	la a0, vetor                               #endereço inicial do vetor
	addi a2, zero, 6                           #contador iniciado com 6 pq a primeira pos. ja está lida.
	lw t0, 0(a0)                               #primeira pos do vetor/ menor valor
	jal menor_vetor
	nop
	ebreak
menor_vetor:
	beq a2, zero, fim                         #condição parada do laço
	lw t1, 4(a0)                              #lê as pos. do vetor. Começando pela segunda.
	blt t1, t0, menor                         #testa se é menor que o valor que está em t0. 
	addi a2, a2, -1 			  #decrementa contador
	addi a0, a0, 4                            #anda 1 pos. no vetor.
	j menor_vetor 
menor:
	add t0, t1, zero                          #atualiza o menor numero em to
	add t3, zero, a1                          #tamanho do vetor em t3
	sub t3, t3, a2                            #tamanho - contador. Índice em t3
	j menor_vetor
fim:
	add a0, t3, zero                            #Índice em a0
	add a1, t0, zero                            #menor valor em t1
	ret


#2- QUESTAO

.data
	vetor:
		.word
			2, 8, 1, 3, 7, 5, 6
.text
main:
	addi t2, zero, 7                                 #tamanho
	la a0, vetor                                     #end. inicial do vetor
	addi a1, zero, 2				 #primeiro indice
	addi a2, zero, 4				 #segundo indice
	add t0, zero, zero                               #inicia o contador
	jal swap_vetor
	nop
	ebreak
swap_vetor:
	beq t0, t2, fim                                 #condição do laço
	lw t1, 0(a0)                                    #lê posição da memória e guarda em t1
	beq a1, t0, primeiro                            #teste para achar o primeiro indice
	beq a2, t0, segundo                             #teste para achar o segundo indice
	addi t0, t0, 1                                  #incrementa o cont
	addi a0, a0, 4                                  #anda uma casa no vetor
	j swap_vetor
primeiro:
	add t4, t0, zero                                #guarda o primeiro indice em t4
	add t3, t1, zero                                #guarda o primeiro valor em t3
	addi t0, t0, 1                                  #incrementa o cont
	addi a0, a0, 4                                  #anda uma casa no vetor
	j swap_vetor
segundo:
	add t5, t0, zero                                #guarda o segundo indice em t5
	add t6, t1, zero                                #guarda o segundo valor em t6
	add t0, zero, zero                              #zera o cont
	la a0, vetor					#end inicial do vetor
troca:
	beq t2, t0, fim					#condição do laço
	beq t0, t4, primeiro_ind                        #teste para achar o primeiro indice
	beq t0, t5, segundo_ind                         #teste para achar o segundo indice
	addi t0, t0, 1					#incrementa o cont
	j troca
primeiro_ind:
	sw t6, 0(a0)                                   #troca o primeiro valor pelo segundo
	addi t0, t0, 1                                  #incrementa o cont
	j troca
segundo_ind:
	sw t3, 0(a0)                                   #troca o segundo valor pelo primeiro
	j fim
fim: 





#3- QUESTAO

.data
	vetor: 
		.word 4, 9, 3, 1, 8, 6, 5
.text
main:
	la a3, vetor                                          #end inicial do vetor. 
	addi a4, zero, 7                                      #tamanho em a4. 
	addi a2, zero, 0                                      #cont
ordena:
	jal menor_vetor
	add t1, a0, zero                                     #indice do menor em t1
	add t2, a1, zero                                     #valor do menor em t2
teste:
	beq a2, a4, exit
	beq a2, t1, troca
	addi a2, a2, 1                                      #cont + 1
	j teste
troca:
	sw t2, 0(a3)                                        #escreve nas posições do vetor, em ordem.
	addi a3, a3, 4                                      
	addi a2, zero, 0                                    #zera o cont
	j teste
exit:
	nop
	ebreak
	
	
	
	

menor_vetor:
	beq a2, zero, fim                         #condição parada do laço
	lw t1, 4(a0)                              #lê as pos. do vetor. Começando pela segunda.
	blt t1, t0, menor                         #testa se é menor que o valor que está em t0. 
	addi a2, a2, -1 			  #decrementa contador
	addi a0, a0, 4                            #anda 1 pos. no vetor.
	j menor_vetor 
menor:
	add t0, t1, zero                          #atualiza o menor numero em to
	add t3, zero, a1                          #tamanho do vetor em t3
	sub t3, t3, a2                            #tamanho - contador. Índice em t3
	j menor_vetor
fim:
	add a0, t3, zero                            #Índice em a0
	add a1, t0, zero                            #menor valor em t1
	ret




	
