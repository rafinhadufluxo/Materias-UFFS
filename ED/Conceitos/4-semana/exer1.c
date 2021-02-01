#include<stdio.h>


void subtracao(int *a, int b){
    
    a = a- b;

    printf("%d = %d\n",b,a);

    return;
}


int main(){
    int a, b;
    int *p1;

    scanf("%d %d", &a,&b);
    p1 = &a;
    
    printf("\r %d - ", *p1); // usei o \r para imprimir na mesma linha o resultado, 
                             //talvez seja um gambiarra linda

    subtracao(a,b);
}