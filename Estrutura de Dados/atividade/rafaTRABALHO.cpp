#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCLIENTES 100
#define MAXPRODUTOS 50

typedef struct _produto{
	char nome[30], data_fab[12], data_val[12], fornecedor[30];
	double val_venda;
}Produto;

typedef struct _compra{
	Produto produtos[20];
	double total;
	int cheque_num;
}Compra;

typedef struct _cartao{
	int numero, qtd_entradas;
	Compra compras[20];
	double total_compras;
}Cartao;

typedef struct _cliente{
	char nome[30], cpf[16], telefone[17];
	Cartao cartao;
}Cliente;

typedef struct _estoque{
	Produto produto;
	int qtd_estoque;
	double val_aquisicao;
}Estoque;

int quantidadeclientes = 0;//varia de acordo com a quantidade de clientes cadastrados
Cliente cliente[MAXCLIENTES]; //Vetor para salvar clientes
void cadastrar_cliente(){
	getchar();

	printf("Digite o nome do cliente: ");
	fgets(cliente[quantidadeclientes].nome, 30, stdin);

	printf("Digite o numero do CPF: ");
	fgets(cliente[quantidadeclientes].cpf, 16, stdin);

	printf("Digite o numero do telefone:");
	fgets(cliente[quantidadeclientes].telefone, 17, stdin);

	printf("Digite o numero do seu cartão:");
	scanf("%d", &cliente[quantidadeclientes].cartao.numero);
	cliente[quantidadeclientes].cartao.qtd_entradas = 0;
	cliente[quantidadeclientes].cartao.total_compras=0;

	quantidadeclientes++;
}
int buscar_cliente(){
	int i;
	char CPFcomparar[16];
	printf("Digite o numero do CPF:");
	getchar();
	fgets(CPFcomparar,16,stdin);
	for(i = 0; i < quantidadeclientes; i++){
		if(strcmp(CPFcomparar,cliente[i].cpf)==0){
			return i;
		}
		else printf("Cliente nao encontrado\n");
	}
}

int quantidadeproduto = 0;
Estoque estoque[MAXPRODUTOS];//Vetor para salvar produtos
int buscar_produto(){
	int i;
	char nomecomparar[30];
	printf("Digite o nome do Produto: ");
	getchar();
	fgets(nomecomparar,30,stdin);
	for(i=0; i<quantidadeproduto; i++){
		if(strcmp(nomecomparar,estoque[i].produto.nome)==0){
			return i;
		}
		else printf("Produto nao encontrado\n");
	}
}
void adicionar_prod_estoque(){
	int num,b;
	num= buscar_produto();
	printf("Digite a quatidade que deseja armazenar:");
	scanf("%d", &b);
	estoque[num].qtd_estoque += b;

}
void cadastrar_produto(){
	getchar();//limpa lixo de memoria

	do {
		printf("Digite o nome do produto: ");
		fgets(estoque[quantidadeproduto].produto.nome, 30, stdin);
	} while(strlen(estoque[quantidadeproduto].produto.nome)<2);

	printf("Digite o nome do Fonecedor: ");
	fgets(estoque[quantidadeproduto].produto.fornecedor, 30, stdin);

	printf("Digite a data de fabricacao: ");
	fgets(estoque[quantidadeproduto].produto.data_fab, 12, stdin);

	printf("Digite a data de validade:");
	fgets(estoque[quantidadeproduto].produto.data_val, 12, stdin);

	do {
		printf("Digite o valor da aquisição: ");
		scanf("%lf", &estoque[quantidadeproduto].val_aquisicao);
	} while(estoque[quantidadeproduto].val_aquisicao < 1);

	do {
		printf("Digite o valor da venda: ");
		scanf("%lf", &estoque[quantidadeproduto].produto.val_venda);
	} while(estoque[quantidadeproduto].produto.val_venda < 1);

	printf("Digite a quantidade de produto:");
	scanf("%d", &estoque[quantidadeproduto].qtd_estoque);

	quantidadeproduto++;
}
void mostrar_produto(int num){
	printf("O nome do Produto: %s\n", estoque[num].produto.nome);
	printf("O nome do Fornecedor: %s\n",estoque[num].produto.fornecedor);
	printf("Data da Fabricacao:%s\n",estoque[num].produto.data_fab);
	printf("Data de Validade:%s\n",estoque[num].produto.data_val);
	printf("Valor da venda: %.2lf\n",estoque[num].produto.val_venda);
}

Compra compras[50];
int qtd_compras = 0;

// Pagamentos
void pgto_cartao(){
	int numero, i;
	printf("Digite o numero do cartao:\n");
	scanf("%d",&numero);
	for (i=0; i<MAXCLIENTES; i++){
		if (cliente[i].cartao.numero==numero) {
			break;
		}
	}
	cliente[i].cartao.compras[cliente[i].cartao.qtd_entradas]= compras[qtd_compras];
	cliente[i].cartao.qtd_entradas++;
	cliente[i].cartao.total_compras += compras[qtd_compras].total;
}
void pgto_dinheiro(){
	double dinheiro;
	printf("valor da compra:%2lf\n", compras[qtd_compras].total);
	scanf("%lf",&dinheiro );
	printf("Troco:%2lf\n",dinheiro-compras[qtd_compras].total);
}
void pgto_cheque(){
	printf("Digite o valor do cheque:\n" );
	scanf("%d",&compras[qtd_compras].cheque_num);
}

void cadastrar_venda(){
	int n = 0;

	int qtd_produtos = 0;
	while (1) {
		int pr = buscar_produto();
		if (estoque[pr].qtd_estoque > 0) {
			mostrar_produto(pr);
			printf("Confirma? [0/1]\n");
			scanf("%d", &n);
			if (n) {
				compras[qtd_compras].produtos[qtd_produtos] = estoque[pr].produto;
				compras[qtd_compras].total += estoque[pr].produto.val_venda;
				estoque[qtd_compras].qtd_estoque--;
			}
		}
		else printf("Produto Inexistente\n");

		printf("Continuar? [0/1]\n");
		scanf("%d", &n);
		if (!n) break;

		qtd_produtos++;
	}

	printf("Valor da Compra: %lf\n", compras[qtd_compras].total);
	printf("Forma de pagamento:\n");
	printf("1- Cartão\n");
	printf("2- Dinheiro\n");
	printf("3- Cheque\n");
	scanf("%d", &n);
	switch (n) {
		case 1: pgto_cartao();
		case 2: pgto_dinheiro();
		case 3: pgto_cartao();
	}
}

void listar_prod_fornecedor(){
	char a[10];
	int i;
	printf("Digite o nome do Fornecedor:\n");
	scanf("%s", a );
	for (i = 0; i < quantidadeproduto; i++) {
		if(strcmp(estoque[i].produto.fornecedor, a)==0){
				printf("Nome do produto: %s\n",estoque[i].produto.nome);
				printf("Valor do Produto: %2lf\n",estoque[i].produto.val_venda);
				printf("Data de Fabricacao: %s\n",estoque[i].produto.data_fab);
				printf("Data de validacao: %s\n",estoque[i].produto.data_val);
				printf("Quantidade no Estoque:%d \n", estoque[i].qtd_estoque);
		}

	}

}
void listar_prod_baixa(){
	int i;
	for (i = 0; i < quantidadeproduto; i++) {
		if(estoque[i].qtd_estoque < 10){
				printf("Nome do produto: %s\n",estoque[i].produto.nome);
				printf("Valor do Produto: %2lf\n",estoque[i].produto.val_venda);
				printf("Data de Fabricacao: %s\n",estoque[i].produto.data_fab);
				printf("Data de validacao: %s\n",estoque[i].produto.data_val);
				printf("Quantidade no Estoque:%d \n", estoque[i].qtd_estoque);
		}

	}

}
void listar_clientes(){
	int i;// percorre o for
	for(i=0; i < quantidadeclientes; i++){
		if(cliente[i].cartao.qtd_entradas > 0){
			printf("Nome do Cliente: %s",cliente[i].nome);
			printf("CPF do Cliente: %s", cliente[i].cpf);
			printf("Telefone do Cliente: %s",cliente[i].telefone);
			printf("Numero do cart�o: %d\n\n", cliente[i].cartao.numero);
		}
	}
}


int main(void){
	int opcao, num;
	do{
		printf("\tMenu de Opções:\n");
		printf("1 - Cadastrar clientes, produtos ou venda:\n");
		printf("2 - Buscar cliente:\n");
		printf("3 - Buscar produto:\n");
		printf("4 - Adicionar produto no estoque:\n");
		printf("5 - Listar produtos:\n");
		printf("6 - Listar clientes:\n");
		printf("0 - Sair do sistema:\n");
		printf("\n--> ");
		scanf("%d", &opcao);
		printf("\n");
		switch(opcao){
			case 1:
			do{
				printf("\tSubmenu de cadastro\n");
				printf("1 - Cadastrar cliente:\n");
				printf("2 - Cadastrar produto:\n");
				printf("3 - Cadastrar venda:\n");
				printf("0 - Voltar ao menu anterior\n");
				printf("\n--> ");
				scanf("%d", &opcao);
				printf("\n");
				switch(opcao){
					case 1:
					cadastrar_cliente();
					opcao = 0;
					break;
					case 2:
					cadastrar_produto();
					opcao = 0;
					break;

					case 3:
					cadastrar_venda();
					opcao = 0;
					break;
					case 0:
					break;
					default:
					printf("Opcao inválida\n\n");
					break;
				}
			}while(opcao != 0);
			opcao = 1;
			break;
			case 2:{
				num = buscar_cliente();
				printf("Nome do Cliente: %s\n",cliente[num].nome);
				printf("CPF do Cliente: %s\n", cliente[num].cpf);
				printf("Telefone do Cliente: %s\n",cliente[num].telefone);
				printf("Numero do cart�o: %d\n", cliente[num].cartao.numero);
				break;
			}
			case 3:{
				num = buscar_produto();
				mostrar_produto(num);
			}
			break;
			case 4:
			adicionar_prod_estoque();
			break;
			case 5:
			do{
				printf("\tSubmenu de produtos\n");
				printf("1 - Listar produtos por fornecedor:\n");
				printf("2 - Listar produtos em baixa no estoque:\n");
				printf("0 - Voltar ao menu anterior\n");
				printf("\n--> ");
				scanf("%d", &opcao);
				printf("\n");
				switch(opcao){
					case 1:
					listar_prod_fornecedor();
					opcao = 0;
					break;
					case 2:
					listar_prod_baixa();
					opcao = 0;
					break;
					case 0:
					break;
					default:
					printf("Opcao inválida\n\n");
					break;
				}

			}while(opcao != 0);
			opcao = 5;
			break;
			case 6:
			listar_clientes();
			break;
			case 0:
			break;
			default:
			printf("Opção inválida\n\n");
		}
	}while(opcao != 0);


	return 0;
}
