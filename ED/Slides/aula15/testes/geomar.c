// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct
// {
//     int dia;
//     int mes;
//     int ano;
// } Data;

// struct funcionario
// {
//     int id;
//     char nome[41];
//     double salario;
//     Data nascimento;
//     struct funcionario *proximo;
// };
// typedef struct funcionario Funcionario;

// void imprimeLista(Funcionario *lista)
// {
//     Funcionario *aux;
//     if (lista == NULL)
//     {
//         printf("Lista vazia\n");
//         return;
//     }
//     for (aux = lista; aux != NULL; aux = aux->proximo)
//     {
//         printf("Registro:\n\t id: %d, \n\t nome: %s, \n\t nasc: %d/%d/%d, \n\t salario: %lf\n\n", aux->id, aux->nome, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano, aux->salario);
//     }
// }

// /*Limpa toda a lista, da free em todos os endereços de memoria.*/
// void limpaTodaLista(Funcionario *primeiro)
// {
//     Funcionario *aux;
//     while (primeiro != NULL)
//     {
//         aux = primeiro;
//         primeiro = primeiro->proximo;
//         free(aux);
//     }
// }

// int qtdElementos(Funcionario *cabeca) // quantos elementos a lista possui.
// {
//     int qtd = 0;
//     while (cabeca != NULL)
//     {
//         cabeca = cabeca->proximo;
//         qtd++;
//     }
//     return qtd;
// }

// int menorSalarioLista(Funcionario *primeiro)
// {
//     float menor = primeiro->salario;
//     Funcionario *aux = primeiro;
//     while (aux != NULL)
//     {
//         if (aux->salario < menor)
//         {
//             menor = aux->salario;
//         }
//         aux = aux->proximo;
//     }
   
//    return menor;
// }

// int funcionarioVelho(Funcionario *primeiro) //tens que retornar o funcionário, não apenas a idadde. aqui seria Funcionario *
// {
//     int maior = primeiro->nascimento.ano; //isso ideia boa. Mas como precisa retorna Funcionario, eu colocaria o primeiro dentro de funcionario
//     Funcionario *aux = primeiro;
//     while (aux != NULL)
//     {
//         if (aux->nascimento.ano < maior) //se for alterar aqui seria maior->nasciemnto.ano
//         {
//             maior = aux->nascimento.ano; //perfeito, mas como tens q retornar o Funcionário, eu colocaria maior como funcionário, e compararia maior->nascimento.ano...
//         }
//         aux = aux->proximo;
//     }
   
//    return maior;
   

// }

// int main()
// {
//     Funcionario *primeiro = NULL, *aux;
//     int n, i, qtd;
//     float salario;
//     int  maiorAno;

//     /*Lendo os valores*/
//     printf("Digite o número de valores: ");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++)
//     {
//         aux = malloc(sizeof(Funcionario));
//         printf("\nDigite o id: \n");
//         scanf("%d%*c", &aux->id); //o %*c representa ler um caractere mas não gravar, só outra forma de eliminar o '\n', pois ele atrapalha o fgets

//         printf("\nDigite o nome: ");
//         fgets(aux->nome, sizeof(aux->nome), stdin);
//         aux->nome[strcspn(aux->nome, "\n")] = '\0'; //Trocando o \n por \0;
//         printf("\nDigite a data nascimento (formato dd/mm/yyyy): ");
//         scanf("%d/%d/%d", &aux->nascimento.dia, &aux->nascimento.mes, &aux->nascimento.ano);
//         printf("\nDigite o salario: ");
//         scanf("%lf", &aux->salario);
//         aux->proximo = NULL;

//         if (primeiro == NULL)
//         { //Ele é o primeiro
//             primeiro = aux;
//         }
//         else
//         { //faz o encadeamento
//             aux->proximo = primeiro;
//             primeiro = aux;
//         }
//     }
//     /*Imprimindo a lista como a B pede*/
//     imprimeLista(primeiro);

//     qtd = qtdElementos(primeiro);

//     printf("\nO numero de elementos da lista é %d\n", qtd);

//     salario = menorSalarioLista(primeiro);

//     printf("------------------\n");
//     printf("menor salario desta lista e: %f\n", salario);
//     printf("------------------\n");
    
//     maiorAno = funcionarioVelho(primeiro);
//     printf("------------------------\n");
//     printf("Funcionario Mais Velho\n");
//     printf("Ano de nascimento: %d\n", maiorAno);
//     printf("-----------------------------\n");

//     /*Antes de acabar o programa podemos limpar nossa lista.*/
//     limpaTodaLista(primeiro);

//     printf("\nTerminamos!\n");

//     return 0;
// }