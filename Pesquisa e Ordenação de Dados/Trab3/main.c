#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 100

typedef struct {
    int code;
    char nameProduct[TAM];
} Product;



void countingSort(Product itens[], int n, int pos){
  Product *aux = malloc(n * sizeof(Product));
  int *count = calloc(10, sizeof(int));
  int merge, i;

  i = 0;
  while(i <n){
    merge = (itens[i].code/pos) % 10;
    count[merge]++;
    i++;
  }

  i = 1;
  while(i<10){
    count[i] = count[i] + count[i-1];
    i++;
  }

  for(int i = n-1; i>=0; i--){
    merge = (itens[i].code/pos) % 10;
    count[merge]--;
    aux[count[merge]].code = itens[i].code;
    strcpy(aux[count[merge]].nameProduct, itens[i].nameProduct);
  }

  i = 0;
  while(i < n){
    itens[i].code = aux[i].code;
    strcpy(itens[i].nameProduct, aux[i].nameProduct);
    i++;
  }

}
int getMax(Product itens[], int n){
  int max = itens[0].code;
  int i; 
  
  i = 1;
  while(i< n){
    if(itens[i].code>max){
      max = itens[i].code;
    }
    i++;
  }

  return max;
}

void radixSort(Product itens[], int n){
  int max = 0;
    
  max = getMax(itens, n);

  for(int pos = 1; max/pos > 0; pos *= 10){
    countingSort(itens, n, pos);
  }
}

int main(){
    int n = 10;
    Product item[10] = {
      {170,"computador"},
      {45,"arroz"},
      {75,"feijão"}, 
      {90,"oleo"},
      {802,"gas"}, 
      {24,"Suco"}, 
      {2,"pipoca"}, 
      {66,"BBB"} ,
      {800,"Café"},
      {12,"Maionese"}
    };

   

    radixSort(item, n);

    
    printf("\nCodigo  |   Nome\n");
    for(int i=0; i<n; i++){
        printf("%d       |   %s\n", item[i].code, item[i].nameProduct);
    }
    printf("\n");
}
