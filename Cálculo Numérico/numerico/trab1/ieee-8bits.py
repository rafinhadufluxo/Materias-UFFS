import sys, string, _tkinter

def representacao(numero) :
	expoente = 0
	if int(numero) > 0 :
		while int(numero) > 0 :
			numero = numero/10
			expoente = expoente + 1
	else :
		while int(numero) < 1:
			numero = numero*10
			expoente = expoente - 1
		numero = numero/10
	return numero, expoente

def decimal_binario(numero) :
	bit = ''
	while numero != 0 :
		numero = numero * 2
		if int(numero) : bit = bit + '1'
		else : bit = bit + '0'
		numero = numero - int(numero)
	return bit


if len(sys.argv) == 2 :

	try :
		numero = float(sys.argv[1])

	except (TypeError, NameError, ValueError) :
		print '\nValor invalidos!\n'
		exit()
		
	if numero > 0 : sinal = '0'
	else : sinal = '1'
	
	base = ['000', '001', '010', '011', '100', '101', '110', '111']
	
	mantissa, expoente = representacao(abs(numero))
	mantissa = decimal_binario(mantissa)

	print '\n', sinal+base[expoente+3]+mantissa[:4], '\n'

else :
	print '\nNao foi passado o numero de argumentos corretos\n\nFormato correto\npython ieee-8bits.py <numero>\n'
