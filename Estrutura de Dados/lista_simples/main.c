#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

int main () {
    int option, entry, entry2, max=10, size=0;
    node *head, *tail, *temp;

    do {
        printf("Digite a opção desejada:\n1 - Inicializa fila\n2 - Inserção\n3 - Remoção\n4 - Verifica se está cheia\n5 - Verifica se está vazia\n6 - Imprime fila\n7 - Fura fila (insere no meio)\n0 - Sair\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (size == 0) {
                    head = init();
                    tail = head;
                    printf("Fila inicializada com NULL\n");
                } else {
                    printf("Fila já foi inicializada!\n");
                }
            break;
            case 2:
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
            case 3:
                if (!empty_queue(size)) {
                    head = pop(head);
                    size--;
                } else {
                    printf("Não é possível retirar: FILA VAZIA!\n");
                }
            break;
            case 4:
                if (full_queue(size, max))
                    printf("Fila está cheia\n");
                else
                    printf("Fila NÃO está cheia\n");
            break;
            case 5:
                if (empty_queue(size))
                    printf("Fila está vazia\n");
                else
                    printf("Fila NÃO está vazia\n");
            break;
            case 6:
                if (!empty_queue(size)) {
                    print_queue(head);
                } else {
                    printf("Não é possível imprimir: FILA VAZIA!\n");
                }
            break;
            case 7:
                if (!empty_queue(size)) {
                    printf("Digite [valor posicao] [valor inserido]: ");
                    scanf("%d %d", &entry, &entry2);
                    head = middlepush(head, entry, entry2);
                } else {
                    printf("Não é possível inserir no meio: FILA VAZIA!\n");
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
