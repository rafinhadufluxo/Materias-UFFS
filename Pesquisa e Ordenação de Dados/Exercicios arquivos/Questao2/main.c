#include <stdio.h>
#define NOME_TAM 100
#define VALUE_TAM 50
#define QTD_TAM 50


/* Para compilar o programa, siga os passos seguinte:
* 1º Compile assim "gcc main.c", logo ira gerar um arquivo "a.out"
* 2º  para executar use este comando "./a.out < entrada.txt"
* 3º Pronto, ira parecer no terminal o resultado.
*/

int main(){
  FILE *arq;
  char nome[NOME_TAM+1], value[VALUE_TAM+1], qtd[QTD_TAM+1], arq_nome[100];
  char c;

  if ((arq = fopen("entrada.txt", "r")) == NULL){
      printf("\nErro ao abrir o arquivo %s!",arq_nome);
  }

  printf("\n\nImprimindo dados do arquivo\n");
  while (!feof(arq)){  /* Enquanto nao encontra o fim do arquivo */
    
    c =0;
      /* Leitura sincronizada.. */
     
    fscanf(arq, "%s", nome);     /* Salta a palavra: 'PRODUTO:' */
    fgets(nome, NOME_TAM, arq);
    fscanf(arq, "%s", qtd);     /* Salta a palavra: 'QTD:' */
    fgets(qtd, QTD_TAM, arq);
    fscanf(arq, "%s", value);  /* Salta a palavra: 'VALOR:' */
    fgets(value, VALUE_TAM, arq);
     
    printf("\nPRODUTO:%sQTD:%sVALOR:%s\n ", nome, qtd, value);

      /* Caso alguma parte se perca, e o ponteiro no arquivo fique parado
         em alguma parte do registro, esta rotina fara a sincronizacao. */
    while(c != '-'){
      c = getc(arq);
      if (feof(arq)) break;
    }
  }
  fclose(arq);
  printf("\n\t TERMINAMOS \n");
}