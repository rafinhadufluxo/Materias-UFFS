//URI Online Judge | 2930 --> TCC da Depressão Natalino

/* Larissa é uma acadêmica muito inteligente e estudiosa, com isso ela é engajada em 
várias atividades. Chegou o final do ano, mês da sua apresentação de TCC. Ela, muito 
atarefada, precisa saber se vai conseguir realizar sua apresentação antes do Natal! 
Mas antes de sua apresentação ela deve passar por uma verificação com sua orientadora 
oriental, a Prof.Takanada (/Tá com nada/).

    Entrada
A entrada é composta por um valor E (0 < E < 25) representando o dia que foi entregue o 
tcc pra verificação. Um valor D (0 < D < 25) que representa a data final pra entregar 
para verificação.

        Saída
Mostre, para cada caso de teste, se a acadêmica apresentará ou não. A única possibilidade 
da entrega não ser realizada na data é por falta de orientação da Takanada. Caso não seja 
possivel, imprima "Eu odeio a professora!". Caso seja entregue em até 3 dias antes do 
prazo final, imprima "Muito bem! Apresenta antes do Natal!", caso contrário, sendo muito 
próximo da data limite imprima "Parece o trabalho do meu filho!", nesse ultimo caso, é 
adicionado mais dois dias para correções, e caso a data final seja menor que a véspera do 
natal(24), ela poderá apresentar, sendo impresso "TCC Apresentado!", caso contrário 
imprima "Fail! Entao eh nataaaaal!"     */

#include <stdio.h>

void main ()
{

	int e, d; // mude as variavel aqui, e logo o uri aprova

	scanf("%d %d", &e, &d);

	if(d - e >= 3)
		printf("Muito bem! Apresenta antes do Natal!\n");
	else if (d - e < 0)
		printf("Eu odeio a professora!\n");
	else if (d - e < 3)
	{

		printf("Parece o trabalho do meu filho!\n");
		e += 2;
		if (e <= 24)
			printf("TCC Apresentado!\n");
		else
			printf("Fail! Entao eh nataaaaal!\n");

	}

}