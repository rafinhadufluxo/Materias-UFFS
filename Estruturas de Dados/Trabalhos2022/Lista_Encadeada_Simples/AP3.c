/*
 * AP3 - Lista Simplesmente Encadeada
 *
 * GEX605  - Estruturas de Dados // 2021/2
 *  
 * Nome:      Rian Borges Barbosa
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

typedef struct
{
    int day, month, year;

} Date;

struct student

{
    char mat[10], name[11];
    Date birth;
    float avg;
    struct student *next;
};
typedef struct student Student;

Student *include(Student *head)
{

    head = (Student *)malloc(sizeof(Student));

    int day, month, year;

    scanf("%s", head->mat);
    scanf("%s", head->name);
    scanf("%d/%d/%d", &day, &month, &year);
    head->birth.day = day, head->birth.month = month, head->birth.year = year;
    scanf("%f", &head->avg);
    head->next = NULL;
    return head;
}

Student *delete (Student *insert, const char *mat)
{
    Student *aux, *prev = insert;
    for (aux = insert; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->mat, mat) == 0)
        {

            if (aux == insert)
            {
                insert = insert->next;
                free(prev);
                return insert;
            }

            prev->next = aux->next;
            free(aux);
            return insert;
        }
        prev = aux;
    }
    return insert;
}

void Studentlist(Student *insert)
{
    Student *aux;

    for (aux = insert; aux != NULL; aux = aux->next)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->mat, aux->name, aux->birth.day, aux->birth.month, aux->birth.year, aux->avg);
    }
}

int Studentcount(Student *insert)
{
    int count = 0;
    while (insert != NULL)
    {

        count++;
        insert = insert->next;
    }
    return count;
}

void reversedList(Student *insert)
{
    if (insert == NULL)
        return;
    reversedList(insert->next);
    printf("%s, %s, %d/%d/%d, %.2f\n", insert->mat, insert->name, insert->birth.day, insert->birth.month, insert->birth.year, insert->avg);
}

void exit_(Student *insert)
{
    Student *aux;
    aux = insert;
    while (aux != NULL)
    {
        Student *next = aux->next;
        free(aux);
        printf("-");
        aux = next;
    }
}
int pointers_flow(Student *insert, const char mat[10])
{

    Student *aux;
    int count = 0;
    for (aux = insert; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->mat, mat) == 0)
            count++;
        return count;
    }
}
Student *flow_update(Student *insert, Student *aux)
{
    if (insert != NULL)
        aux = insert;
    while (TRUE)
    {
        if (aux ->next == NULL)
            return aux;

        aux = aux->next;
    }

    return NULL;
}

int main()
{
    int num;
    char mat[10];

    Student *head, *aux, *insert = NULL;

    while (TRUE)
    {
        scanf("%d", &num);
        switch (num)
        {
        case 0:

            exit_(insert);
            exit(0);

            break;
        case 1:

            head = include(head);
            if (insert == NULL)
            {

                insert = head;
                aux = head;
            }

            else
            {
                aux->next = head;
                aux = head;
            }

            break;
        case 2:
            if (!Studentcount(insert))
                printf("Lista Vazia!\n");

            else
            {
                scanf("%s", mat);
                for (int i = pointers_flow(insert, mat); i > 0; i--)
                {

                    insert = delete (insert, mat);
                    aux = flow_update(insert, aux);
                }
            }

            break;

        case 3:

            if (!Studentcount(insert))
            {
                printf("Lista Vazia!\n");
            }
            else
                Studentlist(insert);

            break;

        case 4:

            if (!Studentcount(insert))
            {
                printf("Lista Vazia!\n");
            }
            else
                reversedList(insert);

            break;

        case 5:
            if (Studentcount(insert))
                printf("%d\n", Studentcount(insert));

            else
                printf("Lista Vazia!\n");

            break;
        }
    }

    return 0;
}