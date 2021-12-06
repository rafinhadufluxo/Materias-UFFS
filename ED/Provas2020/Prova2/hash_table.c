// Axel Igor Aviloff


#include <stdio.h>
#include <stdlib.h>

typedef int chave;

struct item{
  chave id;
  struct item *proximo;
}; 
typedef struct item Item;

typedef struct {
	Item *head;
    Item *tail;
} ItemHash;


int hashFunction(int k, int M){
	return k % M;
}

void printHashTable(ItemHash *hashTable, int M) {
    int i;
    Item *aux;
    for (i = 0; i < M; i++){
		if (hashTable[i].head == NULL){
			printf("%d -> %c\n", i, 92);
		} else{
			aux = hashTable[i].head;
			printf("%d -> ", i);
			while (aux != NULL){
				printf("%d -> ", aux->id);
				aux = aux->proximo;
			}
            printf("%c\n", 92);
		}
	}
    printf("\n");
}

int main(){

    int N, M, C, i, j, k, posHash;
	Item *aux;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d %d", &M, &C);
        ItemHash hashTable[M];


        for (j = 0; j < M; j++) {
            hashTable[j].head = NULL;
            hashTable[j].tail = NULL;
        }

        for (k = 0; k < C; k++) {
            aux = malloc(sizeof(Item));
            aux->proximo = NULL;
            scanf("%d", &aux->id);
            posHash = hashFunction(aux->id, M);

            if (hashTable[posHash].head == NULL) {
                hashTable[posHash].head = aux;
                hashTable[posHash].tail = aux;
            } else{
                hashTable[posHash].tail->proximo = aux;
                hashTable[posHash].tail = aux;

		    }
            
        }

        printHashTable(hashTable, M);
    }


	return 0;
}
