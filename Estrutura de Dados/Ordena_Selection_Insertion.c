/******** UNIVERSIDADE FEDERAL DA FRONTEIRA SUL *******
*****  CIÊNCIA DA COMPUTAÇÃO, 2º FASE
***  ALUNA:  Pâmela Gheno
** ESTRUTURA DE DADOS I

******************************************************

LISTA DUPLAMENTE ENCADEADA COM SENTINELA 
e MÉTODO DE ORDENAÇÃO INSERTION/selection SORT  */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct prod{
	int cod;
	char nome[20];
	float preco;
}tp_produto; //tipo produto;

typedef struct nodo{
	tp_produto info;
	struct nodo* prox;
	struct nodo* ant;
}tp_nodo; //lista

typedef struct cab{
	int qtd_itens;
	tp_nodo* prim;
	tp_nodo* ult;
}tp_cab; //cabeça de lista


tp_nodo* insere(tp_cab *cab){		//funçao para adicinar produto;
	tp_nodo *x = (tp_nodo*) malloc(sizeof(tp_nodo));		//cria novo nodo cada vez e preenche .

		printf("________________________________________\n\n");
		printf("Preencha as informações:\n");
		printf("Código:\n");
		scanf("%d", &(x->info.cod));
		printf("\n");
		getchar();
		printf("Nome:\n");
		fgets( (x->info).nome, 20, stdin);
		printf("\n");
		printf("Preço:\n");
		scanf("%f", &((x->info).preco));
		printf("________________________________________");
		getchar();
		printf("\n");


//reaponteira

	if(cab->prim == NULL){		//se estiver vazia, o prox e o ant serao nulos. 
		x->prox = NULL;			//e a cabeça (primeiro e ultimo) será o nodo.
		x->ant = NULL;
		cab->prim = x;
		cab->ult = x;
		cab->qtd_itens++;

	}else {						//senao, o anterior sera sempre nulo, (ele adiciona a esquerda) e o prox recebe
		x->ant = NULL;			//a  antiga cabeça (prim); o anterior dela recebe o novo nodo. e ela se atualiza 
		x->prox = cab->prim;	//com o x nodo. e incrementa qtd de itens... retona a lista preenchida.
		cab->prim->ant = x;
		cab->prim = x;
		cab->qtd_itens++;
	}

		return x;
}

//funçao que retira elementos
void tira(tp_cab *cab){
	tp_nodo* aux;			//auxiliares para reaponteirar
	tp_nodo *it;
	int codig, cnt=0;
		if(cab->prim==NULL){
			printf("LISTA VAZIA !!!\n");
		return;
		}
		else

			printf("Digite o código que deseja remover:\n");
			scanf("%d", &codig);

			//procura e remove o cod.
			for(aux = cab->prim; aux != NULL; aux = aux->prox){	// começa no cab->prim e vai até null
				if(codig == aux->info.cod){
																	//se encontrar, e for um do meio:
					if(aux->prox != NULL && aux->ant != NULL){ 		//o proximo do anterior sera o proximo do aux;
						aux->ant->prox = aux->prox;					// e o anterior do proximo será o anterior do aux;
						aux->prox->ant = aux->ant;
					}
					if(aux == cab->prim){ 						// se for o primeiro:
		                 it = cab->prim;						// salva o endereço dele em it, o primeiro recebe
		                 cab->prim = (cab->prim)->prox;			// o seu proximo, e o anterior do primeiro passa a ser NULL;
		                 it->ant = NULL;
		            }

					 else if(aux->prox == NULL){ 				//se for o ultimo:
						cab->ult = aux->ant;					//o ultimo passa a ser o penultimo item e 
						cab->ult->prox = NULL;					// o proximo  é null;
					
					}
					cab->qtd_itens--;						// quatidade itens diminui;
					printf("PRODUTO EXCLUÍDO COM SUCESSO! \n"); // e contador incrementa .
					cnt++;


				}
			}
				if(cnt == 0){ // se incrementar, significa que nao achou o elemento e retorna.
					printf("PRODUTO NÃO ENCONTRADO, por favor tente novamente.\n");
					return;
				}
					
					




}


// funçao que mostra os produtos
void display(tp_cab *cab){

	tp_nodo *x; //copia auxiliar

	for( x = cab->prim; x != NULL; x = x->prox){
		printf("________________________________________\n\n");
		printf("CÓDIGO: %d\n", x->info.cod);
		printf("\tNOME: %s\n", x->info.nome);
		printf("\tPREÇO: %.2f\n", x->info.preco);
		printf("________________________________________\n\n");
	}
		
}



void Insertion(tp_cab *cab){
	tp_nodo *i, *j,*aux;

	if(cab->prim == NULL || cab->prim->prox == NULL){ //verifica se há um ou nenhum elemento na lista.
		printf("\t\tNão há o que ordenar!\n");
		return;
	}

	for(i = cab->prim->prox; i != NULL; i = i->prox){
		for(j = i->ant; j != NULL; j = j->ant){
			aux = i; 
			
			if(aux->info.cod < j->info.cod){ //se o proximo é maior que o anterior devemos troca-los:
				
				if(cab->qtd_itens == 2){ // 2 elementos na lista.	
					j->ant = aux;
					j->prox = NULL;
					aux->prox = j;
					aux->ant = NULL;
					cab->prim  = aux;
					cab->ult = j;
				}

				else if (j->ant == NULL){ // 1º e 2º elementos
					aux->prox->ant = j;
					j->prox = aux->prox;
					aux->ant = j->ant;
					aux->prox = j;
					j->ant = aux;
					cab->prim  = aux;
				}
				
				else if(aux == cab->ult){ 	// ultimo e penultimo elementos
					
					j->prox = aux->prox;
					aux->ant = j->ant;
					aux->prox = j;
					j->ant->prox = aux;
					j->ant = aux;
					cab->ult = j;
				}
				
				else { 						// caso estejam no meio
					aux->prox->ant = j;
					j->prox = aux->prox;
					aux->ant = j->ant;
					aux->prox = j;
					j->ant->prox = aux;
					j->ant = aux;
				}




					
				
			}
		}
	}
	printf("LISTA ORDENADA COM SUCESSO!\n");
}

void Selection(tp_cab *cab){
	tp_nodo *i, *j, *menor, *next1, *next2, *prev1, *prev2;

	if(cab->prim == NULL || cab->prim->prox == NULL){ //verifica se há um ou nenhum elemento na lista.
		printf("\t\tNão há o que ordenar!\n");
		return;
	}

	for(i = cab->prim; i!= NULL; i = i->prox){ //começa com o menor sendo a primeira posiçao
		menor = i;
		for(j = i->prox; j!= NULL; j = j->prox){	//identifica se há alguma outra com indice menor do 
			if(j->info.cod < menor->info.cod)		//que o já identificado.
				menor = j;
		}
													// caso haja, é necessário muda-los de posição:
		if(i->info.cod > menor->info.cod){
			next1 = i->prox; //variaveis para auxiliar em aponteiramentos mais complexos
			next2 = menor->prox;
			prev1 = i->ant;
			prev2 = menor->ant;
			
			if(cab->qtd_itens == 2){ // somente dois elementos na lista
				i->prox = menor->prox;
				i->ant = menor;
				menor->prox = i;
				menor->ant = NULL;
				cab->prim = menor; //atualiza a sentinela 
				cab->ult = i;
				i = menor; //verifica novamente a partir da proxima posiçao não ordenada.
			}
						
			else if(i == cab->prim && i->prox == menor){ // primeiro e segundo elementos
				i->prox = menor->prox;
				menor->ant = i->ant;
				menor->prox->ant = i;
				menor->prox = i;
				cab->prim = menor;	
				i = menor; 
			}

			else if(i == cab->prim && i->prox != menor && menor->prox != NULL){	//primeiro e um do meio
				i->prox = menor->prox;
				menor->prox->ant = i;
				i->ant = menor->ant;
				menor->ant->prox = i;
				menor->prox = next1;
				next1->ant = menor;
				menor->ant = NULL;
				cab->prim = menor;	
				i = menor; 
			}

			else if(i->ant == NULL &&  menor->ant != i && menor->prox == NULL){ //primeiro e ultimo 
				i->prox = NULL;
				i->ant = menor->ant;
				menor->ant->prox = i;
				menor->ant = NULL;
				menor->prox = next1;
				next1->ant = menor;
				cab->prim = menor;
				cab->ult = i;		
				i = menor; 
			}

			else if(i != cab->prim && i->prox == menor && menor != cab->ult){ //elementos do meio em sequencia
				i->prox = menor->prox;										
				menor->prox->ant = i;
				i->ant = menor;
				menor->prox = i;
				next1 ->ant = menor;
				menor->ant = prev1;
				prev1->prox = menor;
				i = menor;
			}
			
			else if(i->prox == menor && menor == cab->ult){ //ultimo e anterior				
				i->prox = menor->prox;				
				i->ant = menor;				
				menor->prox = i;				
				prev1->prox = menor;				
				menor->ant = prev1;		
				cab->ult = i;
				i = menor;
			}

			else if(menor == cab->ult && menor->ant != i){ //ultimo e um do meio			
				i->prox = menor->prox;				
				i->ant = menor->ant;				
				menor->ant->prox = i;				
				menor->prox = next1;				
				next1->ant = menor;				
				menor->ant = prev1;
				prev1->prox = menor;
				cab->ult = i;
				i = menor;
			}

			else if(menor != cab->ult && i != cab->prim && i->prox != menor){ //dois elem. no meio, fora de sequencia				
				i->prox = menor->prox;				
				menor->prox->ant = i;				
				menor->ant->prox = i;				
				i->ant = prev2;				
				menor->prox = next1;				
				next1->ant = menor;	
				menor->ant = prev1;				
				prev1->prox = menor;
				i = menor;
			}

		}

	}

	printf("Lista ordenada com sucesso !\n");
	
}



int main(){
	int op;
	//declara lista e cabeça, inicia o resto em null e 0;
	tp_nodo *u = NULL;
	tp_cab *cab = (tp_cab*) malloc(sizeof(tp_cab));
	cab->prim = NULL;
	cab->ult  = NULL;
	cab->qtd_itens = 0;

do{
		printf("\t____________________________________________________\n");
		printf("\n\t\t EM QUE POSSO LHE AJUDAR? \n");
		printf("\t____________________________________________________\n\n");
		printf("\t|1| \e[94m'Cadastrar produto'\e[0m\n");
		printf("\t|2| \e[95m'Remover produto'\e[0m\n");
		printf("\t|3| \e[1;32m'Exibir produto'\e[0m\n");
		printf("\t|4| \e[1;94m'Ordenar via Insertion Sort'\e[0m\n");
		printf("\t|5| \e[1;91m'Ordenar via Selection Sort'\e[0m\n");
		printf("\t|0| 'Sair'\n");
		printf("\t____________________________________________________\n\n");
		scanf("%d", &op);

		system("clear");

		switch (op){

			case 1:
				u = insere(cab);
			break;

			case 2:
				tira(cab);
			break;

			case 3:
				display(cab);
				printf("T O T A L :  %d\n", cab->qtd_itens);
			break;
			case 4:
				Insertion(cab);
			break;
			case 5:
				Selection(cab);
			break;
		}

	}while (op != 0);

	free(u); //libera memoria alocada para a lista
	free(cab);

	return 0;
}
