
// 1145 - Sequência Lógica 2

#include <stdio.h>
 
	int main() {
 	int num1,num2,cont1,cont2;
 	num1=0;
 	num2=0;
	cont1=1;
 	cont2=0;
	scanf("%d%d",&num1,&num2);
   if((1<num1<20)&&(num2<100000)){
     	for(cont1=1;cont1<=num2;cont1++){
		cont2++;
        	if(cont2==num1){
            	printf("%d\n",cont1);
            	cont2=0;}
          		else
				{
     	    	printf("%d ",cont1);

      			}
    	}	
	}
 } 