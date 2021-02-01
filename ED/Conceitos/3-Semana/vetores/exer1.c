#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    float num [6] = { 1 , 2, 3, 1, 1, 1};

    for(i=0; i<=5; i++) {
        printf("%.0f\n", num[i]);

    }
    printf("\n");

   return 0;

}