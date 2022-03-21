#include <stdio.h>

int main(void)
{
    int matriz[4][4];
    int i, j,k,l;

    printf("\nDigite valor para os elementos da matriz\n\n");

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            printf("\nElemento[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }

    printf("\n\n******************* Saida de Dados ********************* \n\n");

    for (k = 0; k < 4; k++){
        ///printf("\n");
        for (l= 0; l < 4; l++)
        {
            if(k == l){
              printf(" %i ", matriz[k][l]);
            }else{
                printf(" * ");
            }
        }
     printf("\n");
    }
    return (0);
}
