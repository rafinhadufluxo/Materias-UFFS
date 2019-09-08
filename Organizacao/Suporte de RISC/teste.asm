.data
	#imprimindo uma String
	myMessage:  .asciiz "Hello World\n"
	
	#imprimindo um Caracter
	myCharacter: .byte 'M'
	
	#imprimindo um Inteiro
	age: .word 23
	
.text

	li $v0,4 	# $v0, 4 é utilizado para imprimir String
	la $a0, myMessage
	syscall
	
	li $v0,4	# $v0, 4 é utilizado para imprimir String
	la $a0, myCharacter
	syscall
	
	li $v0,1	# $v0, 1 é utilizado para imprimir Inteiro
	la $a0, age
	syscall