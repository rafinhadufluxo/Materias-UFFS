#include <stdio.h>
/*
 * AP3 - Lista Duplamente Encadeada
 *
 * GEX605  - Estruturas de Dados // 2021/2
 *
 * Nome:      Rian Borges Barbosa
 *
 */
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
// Birth data for the student
typedef struct date
{
    int day, month, year;
} Date;

// students data
struct students
{
    char subj[10];
    char name[40];
    float avg;
    Date birth;
    struct students *next;
    struct students *prev;
};
typedef struct students Students;

Students *switches(Students *last, const char prev_subj[10])
{
    Students *aux;
    aux = last;

    if (strcmp(prev_subj, aux->subj) == 0)
        return aux;

    for (aux = last; aux->prev != NULL; aux = aux->prev)
    {
        if (strcmp(prev_subj, aux->prev->subj) == 0)
            return aux->prev;
    }
    return NULL;
}

Students *include(Students *prev, Students *next, char prev_subj[10], Students *birth, Students *last, Students *first)
{
    Students *current;

    int day, month, year;
    current = malloc(sizeof(Students));

    scanf("%s", prev_subj);
    scanf("%s", current->subj);
    scanf("%s", current->name);
    scanf("%d/%d/%d", &day, &month, &year);
    current->birth.day = day, current->birth.month = month, current->birth.year = year;
    scanf("%f", &current->avg);
    current->next = NULL;
    current->prev = NULL;
}

void exit_(Students *first)
{
    Students *aux;
    for (aux = first; aux != NULL; aux = aux->next)
    {

        free(aux);
        printf("* ");
    }
}

void show_Students(Students *first)
{
    Students *aux;

    for (aux = first; aux != NULL; aux = aux->next)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->subj, aux->name, aux->birth.day, aux->birth.month, aux->birth.year, aux->avg);
    }
}

void reverse_Students(Students *last)
{
    Students *aux;

    for (aux = last; aux != NULL; aux = aux->prev)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->subj, aux->name, aux->birth.day, aux->birth.month, aux->birth.year, aux->avg);
    }
}

int isEmpty(Students *first)
{
    if (first != NULL)
        return TRUE;
    printf("Lista Vazia!\n");
    return FALSE;
}
int Students_count(Students *first, const char prev_subj[10])
{
    Students *aux;

    int counter = 0;
    for (aux = first; aux != NULL; aux = aux->next)
    {
        if ((strcmp(prev_subj, aux->subj)) == 0)
            counter++;
    }
    return counter;
}

Students *delete (Students *first, char prev_subj[10], Students *last)
{
    Students *newaux;
    scanf("%s", prev_subj);
    for (int i = Students_count(first, prev_subj); i > 0; i--)
    {
        for (newaux = first; newaux != NULL; newaux = newaux->next)
        {
            if ((strcmp(prev_subj, newaux->subj)) == 0)
            {
                if (newaux == first)
                {
                    first = newaux->next;
                    if (first != NULL)
                        first->prev = NULL;
                }
                else if (newaux == last)
                {
                    last = newaux->prev;
                    last->next = NULL;
                }
                else
                {
                    newaux->prev->next = newaux->next;
                    newaux->next->prev = newaux->prev;
                }
                free(newaux);
            }
        }
    }
}
int main()
{
    int n;
    Students *last = NULL, *first = NULL, *birth, *next, *prev, *current;
    char prev_subj[10];

    while (TRUE)
    {
        scanf("%d", &n);
        switch (n)
        {
        case 0:
            exit_(first);
            printf("\n");
            exit(0);
            break;
        case 1:

            current = include(prev, next, prev_subj, birth, last, first);
            if (first == NULL)
            {
                first = current;
                last = first;
            }

            else
            {
                Students *aux = switches(last, prev_subj);
                if (aux == NULL) // first
                {
                    first->prev = current;
                    current->next = first;
                    current->prev = NULL;
                    first = current;
                }

                else if (aux == last) // last
                {
                    aux->next = current;
                    current->prev = aux;
                    current->next = NULL;
                    last = current;
                }
                else
                {

                    Students *nex = aux->next;
                    aux->next = current;

                    current->prev = aux;
                    current->next = nex;
                    nex->prev = current;
                }
            }
            break;

        case 2:
            if (isEmpty(first))
            {
                delete (first, prev_subj, last);
            }

            break;
        case 3:
            if (isEmpty(first))
                show_Students(first);
            break;
        case 4:
            if (isEmpty(first))
                reverse_Students(last);
            break;
        default:
            break;
        }
    }

    return 0;
}