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
    }
    Node* temp = que->head;
    que->head = que->head->next;

    if (que->head == NULL) {
        que->tail = NULL;
    }

    free(temp);
    printf("Data berhasil di-Dequeue\n");
}

void destroy(Queue* que) {
    Node* current = que->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    free(que);
}

int main() {
    Queue* que = (Queue*) malloc(sizeof(Queue));
    init(que);

    enqueue(que, 101);
    enqueue(que, 202);
    enqueue(que, 303);
    dequeue(que);

    enqueue(que, 404);
    enqueue(que, 505);
    dequeue(que);

    enqueue(que, 606);
    enqueue(que, 707);

    destroy(que);

    return 0;
}