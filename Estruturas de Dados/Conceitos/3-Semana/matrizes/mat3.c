#include <stdio.h>

int main(void)
{
    int matriz[5][5];
    int i, j,k,l;

    printf("\nDigite valor para os elementos da matriz\n\n");

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
        {
            printf("\nElemento[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }

    printf("\n\n******************* Saida de Dados ********************* \n\n");

    for (k = 0; k < 5; k++){
        ///printf("\n");
        for (l= 0; l < 5; l++)
        {
            if(k == l){
              printf("1 ");
            }else{
                printf("0 ");
            }
        }
     printf("\n");
    }
    return (0);
}
