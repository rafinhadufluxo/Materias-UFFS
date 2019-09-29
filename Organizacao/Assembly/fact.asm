.data
.text
main:
	
	addi a0, zero, 5 #n fatorial
	jal fact
	ebreak


fact:
	beq a0, zero, fim
	addi sp, sp, -8
	sw a0, 4(sp)
	sw ra, 0(sp)
	addi a0, a0, -1
	jal fact 
	lw a0, 4(sp)
	lw ra, 0(sp)
	addi sp, sp, 8
	j multiplicando
	
multiplicando:

	add a4, zero, zero
	add a5, zero, zero
	j laco
laco:
	beq a4, a0, fim_laco
	add a5, a5, a1
	addi a4, a4, 1
	j laco
fim_laco:
	add a1, a5, zero
	ret
	
fim: 	
	addi a1, zero, 1
	ret
