#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct linkedList {
    Node* head;
} LinkedList;

void init(LinkedList* li) {
    li -> head = NULL;
}

void insert(LinkedList* li, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = li->head;
    li->head = newNode;
    printf("Data Berhasil Di-insert\n");
}

void delete(LinkedList* li) {
    if (li->head == NULL) {
        printf("Linked List Kosong, Tidak ada yang bisa di-delete!\n");
        return;
    }
    Node* temp = li->head;
    li->head = temp -> next;
    free(temp);

    printf("Data Berhasil Di-delete\n");
}

void destroy(LinkedList* li) {
    Node* temp = li->head;
    while(temp != NULL) {
        li->head = temp->next;
        free(temp);
        temp = li->head;
    }
}