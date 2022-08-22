/* Rian Barbosa e Daniele Karoline
   Matrícula: 2111100028     Matrícula: 2111100020


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct site
{
    char dom[61];
    struct site *next;
};
typedef struct site Site;

typedef struct
{
    Site *top;
} Stack;

int isEmpty(Stack *stack);

void push(Stack *stack, char dom[61]);

void freeStack(Stack *stack, char *dom);

int pop(Stack *stack, char *dom);


int main()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;

    while (1)
    {
        char dom[61];
        scanf("%s", dom);

        if (strcmp(dom, "E") == 0)
        {
            freeStack(stack, dom);
            break;
        }
        else if (strcmp(dom, "B") == 0)
        {

            if (!isEmpty(stack))
                pop(stack, dom);
        }
        else
            push(stack, dom);
    }

    return 0;
}

void push(Stack *stack, char *dom)
{

    Site *newElement = malloc(sizeof(Site));

    newElement->next = NULL;
    strcpy(newElement->dom, dom);
    newElement->next = stack->top;
    stack->top = newElement;
}

int isEmpty(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Vazio!\n");
        return 1;
    }
    return 0;
}

int pop(Stack *stack, char *dom)
{
    Site *aux;
    char *aux2;

    aux = stack->top;
    stack->top = stack->top->next;
    aux2 = aux->dom;
    printf("%s\n", aux2);
    free(aux);
    return *aux2;
}

void freeStack(Stack *stack, char *dom)
{
    Site *aux = stack->top, *prev;

    while (aux != NULL)
    {
        prev = aux;
        aux = aux->next;
        free(prev);
    }

    if (stack->top != NULL)
    {
        for (aux = stack->top; aux != NULL; aux = aux->next)
        {
            printf("@\n");
        }
        free(stack);
    }
    else
        printf("!\n");
}