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

	mul a1,a1,a0
	ret
	
fim: 	
	addi a1, zero, 1
	ret