#include <stdio.h>   
#include <stdlib.h>  

typedef struct Node {
    int data;          
    struct Node* next; 
} Node;

typedef struct {
    Node* head;  
    Node* tail;   
} Queue;

void initQueue(Queue* q) {
    q->head = q->tail = NULL;  
}

int isEmpty(Queue* q) {
    return (q->head == NULL);  
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));  
    newNode->data = value;  
    newNode->next = NULL;   

    if (q->tail == NULL) {  
        q->head = q->tail = newNode;  
    } else {  
        q->tail->next = newNode;  
        q->tail = newNode;        
    }
    printf("Enqueue: %d\n", value);  
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {  
        printf("Queue kosong, tidak bisa dequeue!\n");  
        return -1;  
    }

    Node* temp = q->head;  
    int data = temp->data; 

    q->head = q->head->next;  

    if (q->head == NULL) {  
        q->tail = NULL;  
    }

    free(temp);  
    return data; 
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {  
        printf("Queue kosong!\n");
        return;  
    }

    printf("Isi Queue: ");
    Node* temp = q->head;  
    while (temp != NULL) { 
        printf("%d ", temp->data);  
        temp = temp->next;  
    }
    printf("\n");  
}

int main() {
    Queue q;  
    initQueue(&q);  

    enqueue(&q, 10);  
    enqueue(&q, 20);  
    enqueue(&q, 30);  
    enqueue(&q, 40);  

    displayQueue(&q);  

    printf("Dequeue: %d\n", dequeue(&q));  
    printf("Dequeue: %d\n", dequeue(&q));  

    displayQueue(&q);  

    return 0;  
}
