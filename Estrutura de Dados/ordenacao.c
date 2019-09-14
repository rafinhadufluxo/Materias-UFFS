#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct List{
    int value;
    struct List *next, *prev;
}list;

void insertionVec(int vector[]){
    for(int i = 1; i < MAX; i++){
        int value = vector[i], j = i - 1;
        while(j >= 0 && value < vector[j]){
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = value;
    }
}

void bubbleVec(int vector[]){
    for(int i = MAX - 1; i >= 1; i--)
        for(int j = 0; j < i; j++)
            if(vector[j] > vector[j + 1]){
                int aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
}

list *bubbleList(list *mylist){
    int troca = 1, value;
    while(troca != 0){
        troca = 0;
        for(list *aux = mylist->next; aux != NULL; aux = aux->next)
            if(aux->value < aux->prev->value){
                troca = 1;
                value = aux->value;
                aux->value = aux->prev->value;
                aux->prev->value = value;
            }
    }
    return mylist;
}

list *insertionList(list *mylist){
    list *aux1 = mylist->next, *aux2;
    int chave = 0;
    for(; aux1 != NULL; aux1 = aux1->next){
        chave = aux1->value;
        aux2 = aux1->prev;
        while(aux2 != NULL && chave < aux2->value){
            aux2->next->value = aux2->value;
            aux2 = aux2->prev;
        }
        if(aux2 == NULL)
            mylist->value = chave;
        else
            aux2->next->value = chave;
    }
    return mylist;
}

list *insert(list *mylist, int value){
    list *newelement = (list*) malloc(sizeof(list));
    newelement->value = value;
    newelement->next = mylist;
    newelement->prev = NULL;
    if(mylist != NULL)
        mylist->prev = newelement;
    return newelement;
}

int main(){
    srand(time(NULL));
    list *listBu = NULL, *listIn = NULL;
    int vectorInVec[MAX], vectorBuVec[MAX];
    clock_t start, finish;
    double tempo[4];

    printf("Valores desordenados:\n");
    for(int i = 0; i < MAX; i++){
        int random = rand() % 5000;
        listIn = insert(listIn, random);
        listBu = insert(listBu, random);
        vectorBuVec[i] = vectorInVec[i] = random;
        i == MAX - 1 ? printf("%d.\n", random): printf("%d, ", random);
    }

    start = clock();
    printf("\nInsertion Sort com vetor:\n");
    insertionVec(vectorInVec);
    for(int i = 0; i < MAX; i++)
        i == MAX - 1 ? printf("%d.\n", vectorInVec[i]): printf("%d, ", vectorInVec[i]);
    finish = clock();
    tempo[0] = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

    start = clock();
    printf("\nBubble Sort com vetor:\n");
    bubbleVec(vectorBuVec);
    for(int i = 0; i < MAX; i++)
        i == MAX - 1 ? printf("%d.\n", vectorBuVec[i]): printf("%d, ", vectorBuVec[i]);
    finish = clock();
    tempo[1] = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

    start = clock();
    listIn = insertionList(listIn);
    while(listIn->prev != NULL)
        listIn = listIn->prev;
    printf("\nInsertion Sort com Lista:\n");
    for(;listIn->next != NULL; listIn = listIn->next)
        listIn->next->next != NULL ? printf("%d, ", listIn->value): printf("%d.\n", listIn->value);
    finish = clock();
    tempo[2] = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

    start = clock();
    listBu = bubbleList(listBu);
    while(listBu->prev != NULL)
        listBu = listBu->prev;
    printf("\nBubble Sort com Lista:\n");
    for(;listBu->next != NULL; listBu = listBu->next)
        listBu->next->next != NULL ? printf("%d, ", listBu->value): printf("%d.\n", listBu->value);
    finish = clock();
    tempo[3] = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

    printf("\nTempo gasto por função:\n");
    printf("\nCom vetor:\n");
    printf("Insertion Sort: %.5lf ms\n", tempo[0]);
    printf("Bubble Sort:    %.5lf ms\n", tempo[1]);
    printf("\nCom Lista:\n");
    printf("Insertion Sort: %.5lf ms\n", tempo[2]);
    printf("Bubble Sort:    %.5lf ms\n", tempo[3]);

    printf("\n");
}
