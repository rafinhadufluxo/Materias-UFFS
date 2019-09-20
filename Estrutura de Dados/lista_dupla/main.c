#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

int main () {
    int option, option2, entry, entry2;
    node *head, *tail, *temp;

    head = init();
    tail = head;

    do {
        printf("Digite a opção desejada:\n1 - Inserção\n2 - Remoção\n3 - Verifica se está vazia\n4 - Imprime fila\n0 - Sair\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (!full_queue(size, max)) {
                    printf("Digite um valor: ");
                    scanf("%d", &entry);
                    temp = push(tail, entry);
                    if (temp != NULL) {
                        tail = temp;
                        if (empty_queue(size)) {
                            head = tail;
                        }
                        size++;
                    } else {
                        printf("Erro de alocação!\n");
                    }
                } else {
                    printf("Não é possível adicionar: FILA CHEIA!\n");
                }
            break;
            case 2:
                if (!empty_queue(size)) {
                    head = pop(head);
                    size--;
                } else {
                    printf("Não é possível retirar: FILA VAZIA!\n");
                }
            break;
            case 3:
                if (empty_queue(head))
                    printf("Fila está vazia\n");
                else
                    printf("Fila NÃO está vazia\n");
            break;
            case 4:
                if (!empty_queue(size)) {
                    print_queue(head);
                } else {
                    printf("Não é possível imprimir: FILA VAZIA!\n");
                }
            break;
            case 0:
                printf("Encerrando...");
            break;
            default:
                printf("Opção inválida!\n");
        }

    } while (option != 0);

    return 0;
}
