#include <stdio.h>
#include <stdlib.h>

typedef struct ArvoreBinaria
{
    int chave;
    struct ArvoreBinaria *esq;
    struct ArvoreBinaria *dir;
} NO;


NO* construir_arvore(char* str, int* ini, int fim);
void PreOrdem(NO *raiz);
void EmOrdem(NO *raiz);
void PosOrdem(NO *raiz);
NO *insere(NO *no, int chave);


NO *novoNo(int item)
{
    NO *aux = (NO *)malloc(sizeof(NO));
    aux->chave = item;
    aux->esq = aux->dir = NULL;
    return aux;
}

NO* construir_arvore(char* str, int* ini, int fim)
{
    if(*ini < fim)
    {
        char chave = str[*ini];
        char flag_esq = str[*ini + 1];
        char flag_dir = str[*ini + 2];
        NO* arv = novoNo(chave);
        *ini += 3;
        if(flag_esq == '1')
        {
            arv->esq = construir_arvore(str, ini, fim);
        }
        if(flag_dir == '1')
        {
            arv->dir = construir_arvore(str, ini, fim);
        }
        return arv;
    }
    return NULL;
}

void PreOrdem(NO *raiz)
{
    if (raiz != NULL)
    {
        printf("%c", raiz->chave);
        PreOrdem(raiz->esq);
        PreOrdem(raiz->dir);
    }
}


void EmOrdem(NO *raiz)
{
    if (raiz != NULL)
    {
        EmOrdem(raiz->esq);
        printf("%c", raiz->chave);
        EmOrdem(raiz->dir);
    }
}

void PosOrdem(NO *raiz)
{
    if (raiz != NULL)
    {
        PosOrdem(raiz->esq);
        PosOrdem(raiz->dir);
        printf("%c", raiz->chave);
    }
}


NO *insere(NO *no, int chave)
{
    // Se a �rvore estiver vazia, retorne um novo n�
    if (no == NULL)
        return novoNo(chave);

    // Caso contr�rio, volte pela �rvore
    if (chave < no->chave)
        no->esq = insere(no->esq, chave);
    else if (chave > no->chave)
        no->dir = insere(no->dir, chave);

    // retorna o ponteiro do n� (inalterado)
    return no;
}

void libera(NO *raiz)
{
    if (raiz != NULL)
    {
        libera(raiz->esq);
        libera(raiz->dir);
        free(raiz);
        raiz = NULL;
        printf("0");
    }
    
}

int main()
{
    int cont;
    int ini = 0;
    char str[3001];
    scanf("%d", &cont);
    scanf("%s%*c", str);
    NO* a = construir_arvore(str, &ini, cont*3);
    EmOrdem(a);
    printf("\n");
    PosOrdem(a);
    printf("\n");
    libera(a);
    printf("\n");
    
    return 0;
}
