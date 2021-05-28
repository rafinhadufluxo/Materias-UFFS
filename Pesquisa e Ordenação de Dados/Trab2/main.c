#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int* a, int* b) {

    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int quickSort_is_partition(int v[], int start, int end){
	
	int pivot;
	pivot = end;
	int k = start;
	int i;

    i =  start;
	while (i< end){
		if (v[i] <= v[pivot]){
			swap(&v[k], &v[i]);
			k++;
		}
        i++;
	}
	
	if (v[k]> v[pivot]){
		swap(&v[k],&v[pivot]);
	}
	return pivot;
}

void quickSort(int v[], int start, int end){
	
	int pivot;
	if (start < end){
		pivot = quickSort_is_partition(v, start, end);
		quickSort(v, start, pivot-1);
		quickSort(v, pivot+1, end);
		
	}
}


void merge(int v[], int l, int m, int r)  {

    int i, j, k;  
    int n1 = m - l + 1;  
    int n2 = r - m;  
  
  
    int left[n1], right[n2];  
  
   
    for (i = 0; i < n1; i++)  
        left[i] = v[l + i];  
    for (j = 0; j < n2; j++)  
        right[j] = v[m + 1 + j];  
  

    i = 0; 
    j = 0;  
    k = l;   
  
    while (i < n1 && j < n2) {  
        if (left[i] <= right[j]) {  
            v[k] = left[i];  
            i++;  
        }  
        else {  
            v[k] = right[j];  
            j++;  
        }  
        k++;  
    }  
  
   
    while (i < n1) {  
        v[k] = left[i];  
        i++;  
        k++;  
    }  
  
   
    while (j < n2) {  
        v[k] = right[j];  
        j++;  
        k++;  
    }  
}  
  

void mergeSort(int v[], int l, int r)  {  

    if (l < r) {  
        
        int m = l + (r - l) / 2;  
  
        mergeSort(v, l, m);  
        mergeSort(v, m + 1, r);  
        merge(v, l, m, r);  
    }  
    
}  
  
void create_Heap(int v[], int i, int n){

  	int aux = i;
  	int left = 2*i +1;
  	int right = 2*i +2;
  	
  	if (left < n && v[left] > v[i]){
  		aux = left;
	  }
	  
  	if ( right < n && v[right] > v[aux]){
  		
  		aux = right;
  		
	}
	  
	if (aux != i){
		swap(&v[i], &v[aux]);
		create_Heap(v, aux, n);
	}

}
  
  
void heapSort(int v[], int n){
  	clock_t start, end;
  	start = clock();
  	
  	int k = 0;
  	for( k = n/2 -1; k >= 0; k--){
  		create_Heap(v, k, n);
	  }
	  
	for(k = n-1; k>=1; k--){
		swap(&v[0], &v[k]);
		create_Heap(v, 0, k);
	}
	

}
 

void quick_sort(int *v, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = v[(left + right) / 2];
     
  
    while(i <= j) {
        
        while(v[i] < x && i < right) {
            i++;
        }
        
        while(v[j] > x && j > left) {
            j--;
        }
        
        if(i <= j) {
            y = v[i];
            v[i] = v[j];
            v[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left ){
        quick_sort(v, left, j);
    }
    if(i < right) {
        quick_sort(v, i, right);
    }
}

void OrdemCrescente(int *v, int n){

    long int i = 0;    
    while (i<n){
		v[i] = i;
        i++;
	}
}

void OrdemDecrescente(int *v, int n){
	long int i, a = 0;
    i = n;
    while (i > 0){
        v[a] = i;
		a++;
        i--;
    }	
}

void OrdemAleatorio(int *v, int n){

	int i= 0;
    while (i < n){
        v[i] = rand() % n;
        i++;
    }
}

void ImprimindoArray(int v[], int size)  {  
    
    int i=0;  
    while (i < size){
        printf(" %d ", v[i]);
        i++;
    }
} 


/* Para iniciar com os metodos, analise qual o "v" está sendo usando e o metodo (Merge.Quick ou Heap) que
*  irá utilizar, mas observe que foi colocado nos vetores, os valor que foi pedido no enunciado para testar 
* o tempo de uso de cada.  E so descomentar a função que deseja descobrir o tempo de uso que, logo parece o 
* resultado. Como neste exemplo abaixo que estamos vendo o v3 esta gerando numeros aleatorio e logo 
* chama o metodo heap para ordenar dados de 100K.
*
*/


int main()  {  
    //int v1[10000];  
	//int v2[50000]; 
   int v3[100000];

    //OrdemDecrescente(v1, 10000);
	//OrdemDecrescente (v2, 50000);
	//OrdemDecrescente (v3, 100000);
	
	//OrdemCrescente(v1,10000);
	//OrdemCrescente(v2,50000);
	//OrdemCrescente(v3,100000);

	//OrdemAleatorio(v1, 10000);
	//OrdemAleatorio(v2, 50000);
	OrdemAleatorio(v3,100000);
     
    //int n = sizeof(v1) / sizeof(v1[0]);  
   	//int n = sizeof(v2) / sizeof(v2[0]); 
	int n = sizeof(v3) / sizeof(v3[0]); 
    
    
    clock_t start, end;
  	start = clock();
  	
    //quick_sort(v1, 0, n - 1);  
   	//quick_sort(v2, 0, n - 1); 
    //quick_sort(v3, 0, n - 1); 
    
 
    //mergeSort(v1, 0, n - 1);  
    //mergeSort(v2, 0, n - 1);  
    //mergeSort(v3, 0, n - 1);  
          
      
	//heapSort(v1, n);
	//heapSort(v2, n);
	heapSort(v3, n);
	

	end = clock();
    double tempo = ((double)end - start ) /CLOCKS_PER_SEC;
    
	//ImprimindoArray(v1, n);
    //ImprimindoArray(v2, n);
    ImprimindoArray(v3, n);
	
    printf("\n\n Tempo: %lf \n", tempo);
    return 0;  
}  