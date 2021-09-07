#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

void print_list(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
}

void insert_node(struct node *node, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = data;
    new_node->next = node->next;
    node->next = new_node;
}

void delete_node(struct node *node, int value_to_delete) {
    while (node != NULL && node->next->value != value_to_delete) {
        node = node->next;
    }

    if (node == NULL) return;

    if (node->next->value == value_to_delete) {
        struct node *node_to_delete = node->next;
        node->next = node->next->next;
        free(node_to_delete);
    }
}

int main() {
    return 0;
}