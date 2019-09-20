#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;

node * init();
node * insert(node *head, int value);
int count(node *head);
node * removeWithValue(node *head, int value);
node * copyList(node *head);
node * concat(node *list1, node *list2);
node * interc(node *list1, node *list2);
void print(node *head);

int main() {
    node *list1, *list2, *list3, *list4;

    list1 = list2 = list3 = init();

    list1 = insert(list1, 2);
    list1 = insert(list1, 3);
    list1 = insert(list1, 5);
    list1 = insert(list1, 6);
    list1 = insert(list1, 8);
    list1 = insert(list1, 10);
    list1 = insert(list1, 18);
    list1 = insert(list1, 21);
    list1 = insert(list1, 22);
    list1 = insert(list1, 222);
    list1 = insert(list1, 29);
    list1 = insert(list1, 4);
    list2 = insert(list2, 2);
    list2 = insert(list2, 3);
    list2 = insert(list2, 5);
    list2 = insert(list2, 6);
    list2 = insert(list2, 8);
    list2 = insert(list2, 10);
    list2 = insert(list2, 18);
    list2 = insert(list2, 21);
    list2 = insert(list2, 22);
    list2 = insert(list2, 222);
    list2 = insert(list2, 29);
    list2 = insert(list2, 4);
    list2 = insert(list2, 30);
    list2 = insert(list2, 31);

    printf("Valores iniciais:\n");
    print(list1);
    printf("%d\n", count(list1));
    print(list2);
    printf("%d\n", count(list2));

    printf("Valor 2 removido\n");
    list1 = removeWithValue(list1, 2);
    list2 = removeWithValue(list2, 2);
    print(list1);
    printf("%d\n", count(list1));
    print(list2);
    printf("%d\n", count(list2));

    printf("cópia de list1 em list3 e list2 em list4:\n");
    list3 = copyList(list1);
    list4 = copyList(list2);
    print(list3);
    printf("%d\n", count(list3));
    print(list4);
    printf("%d\n", count(list4));

    printf("concatenação list1 e list2\n");
    list1 = concat(list1, list2);
    print(list1);
    printf("%d\n", count(list1));

    printf("list4 e list3 intercaladas\n");
    list4 = interc(list4, list3);
    print(list4);
    printf("%d\n", count(list4));

    return 0;
}

node * init() {
    return NULL;
}

node * insert(node *head, int value) {
    node *new_node, *test = head;

    new_node = (node *) malloc(1*sizeof(node));
    new_node->data = value;
    new_node->next = head;

    if (test != NULL) {
        while (test->next != head)
            test = test->next;
    } else {
        test = new_node;
    }

    test->next = new_node;

    return new_node;
}

int count(node *head) {
    int cnt = 0;
    node *test = head;

    if (test != NULL) {
        test = test->next;
        cnt++;
        while (test != head) {
            test = test->next;
            cnt++;
        }
    }

    return cnt;
}

node * removeWithValue(node *first, int value) {
    node *prev, *temp, *test = first;

    do {
        prev = test;
        test = test->next;

        if (test->data == value) {
            prev->next = test->next;
            if (test == first)
                first = test->next;
            free(test);
        }

        test = test->next;

    } while (test != first);

    return first;
};

node * copyList(node *head) {
    node *first, *last, *current, *test = head;

    first = last = init();

    if (test != NULL) {
        first = (node *) malloc(1*sizeof(node));
        first->data = test->data;
        first->next = first;
        last = first;
        test = test->next;
        while (test != head) {
            current = (node *) malloc(1*sizeof(node));
            current->data = test->data;
            current->next = first;
            last->next = current;
            last = current;
            test = test->next;
        }
    }

    return first;
}

node * concat(node *list1, node *list2) {
    node *first1, *last1, *first2, *last2;
    first1 = last1 = list1;
    first2 = last2 = list2;

    if (first1 == NULL)
        return first2;
    if (first2 == NULL)
        return first1;
    
    while (last1->next != first1)
        last1 = last1->next;

    while (last2->next != first2)
        last2 = last2->next;

    last1->next = first2;
    last2->next = first1;

    return first1;
}

node * interc(node *list1, node *list2) {
    node *next1, *next2, *last, *test1 = list1, *test2 = list2;

    if (test1 == NULL)
        return test2;
    if (test2 == NULL)
        return test1;

    do {
        next1 = test1->next;
        next2 = test2->next;
        test1->next = test2;
        test2->next = next1;
        last = test2;
        test1 = next1;
        test2 = next2;
    } while (test1 != list1 && test2 != list2);

    if (test2 != list2) {
        last->next = test2;
        while (test2->next != list2)
            test2 = test2->next;
        test2->next = list1;
    }

    return list1;
}

void print(node *head) {
    node *test = head;

    if (test != NULL) {
        do {
            printf("%d ", test->data);
            test = test->next;
        } while (test != head);
        printf("\n");
    }
}