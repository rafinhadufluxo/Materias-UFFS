struct Node{
    int num;
    struct Node *prev;
    struct Node *next;
};
typedef struct Node node;

node* init();
int empty_queue(node *head);
node * push(node *last, int value);
node * pop(node *head);
node * middlepush(node *head, int pos, int value);
void print_queue(node *head);
