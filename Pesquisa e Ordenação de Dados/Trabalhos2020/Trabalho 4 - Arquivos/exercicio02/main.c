#include <stdio.h>

int main() {

    int quantidade;
    double valorProduto;
    double totalProduto;
    double totalCompra = 0;
    char nome[50];
    
    FILE *fp = fopen("arquivo.txt", "r");

    if (fp == NULL) {
        exit(1);
    }

    while (fscanf(fp, "%s %d %lf\n", nome, &quantidade, &valorProduto) != EOF) {
        totalProduto = valorProduto * quantidade;
        printf("%s - total = R$%.2lf\n", nome, totalProduto);
        totalCompra += totalProduto;      
    }

    printf("Total da compra = R$%.2lf\n", totalCompra);
    

    fclose(fp);


    return 0;
}