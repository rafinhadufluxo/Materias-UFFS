.data 

	vetor: .word 1, -1, 2, -2, 5, -9
	
.text

main:
	la a0, vetor
	lw t0,0(a0) #carrega o indice 0 no t0
	add  t1,zero,t0
	addi a1, zero,6 #posições do vetor
	addi t4, zero,1 #tem 1 nesse regis
	jal procura
	nop 
	ebreak

procura:
	beq  a1,zero, fim_laco
	
	slt t2,t0,t1
	beq t2,t4, menor
	addi a1,a1,-1
	addi a0,a0,4

menor:
	addi t5,zero,6
	sub s0, t5,a1
	bne a1,zero,procura
	ret
fim_laco:
	addi a0,zero,-1 #a0 salava o indicice se encontrar ou -1 se nao encontrar
	ret
	
	
