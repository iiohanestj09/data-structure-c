#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* head;
    Node* tail;
} Queue;

void init(Queue* que) {
    que->head = que->tail = NULL;
}

void enqueue(Queue* que, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (que->head == NULL) {
        que->head = que->tail = newNode;
    } else {
        que->tail->next = newNode;
        que->tail = newNode;
    }

    printf("Data Berhasil ditambahkan\n");
}

void dequeue(Queue* que) {
    if (que->head == NULL) {
        printf("Gagal dequeue, Queue Kosong\n");
        return;
    } else {
        Node* temp = que->head;
        que->head = que->head->next;

        if(que->head == NULL) {
            que->tail = NULL;
        }

        free(temp);
    }
}

void destroy(Queue* que) {
    while(que->head != NULL) {
        dequeue(&que);
    }

    free(que);
}