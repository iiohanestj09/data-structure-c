#include <stdio.h>   
#include <stdlib.h>  

typedef struct {
    int *data;     
    int head;     
    int tail;     
    int capacity; 
} Queue;

void initQueue(Queue *q, int size) {
    q->data = (int*) malloc(size * sizeof(int));  
    q->head = q->tail = -1;  
    q->capacity = size;      
}

int isEmpty(Queue *q) {
    return (q->head == -1 || q->head > q->tail);  
}

void enqueue(Queue *q, int value) {
    if (q->tail == q->capacity - 1) {  
        q->capacity *= 2;  
        q->data = (int*) realloc(q->data, q->capacity * sizeof(int));  
        printf("Ukuran queue bertambah menjadi %d\n", q->capacity);  
    }

    if (q->head == -1) q->head = 0;  
    q->tail++;  
    q->data[q->tail] = value;  
    printf("Enqueue: %d\n", value);  
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {  
        printf("Queue kosong, tidak bisa dequeue!\n");  
        return -1;  
    }
    
    int temp = q->data[q->head];  
    q->head++;  

    if (q->head > q->tail) {
        q->head = q->tail = -1;  
    }

    return temp;  
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {  
        printf("Queue kosong!\n");  
        return; 
    }

    printf("Isi Queue: ");  
    for (int i = q->head; i <= q->tail; i++) {  
        printf("%d ", q->data[i]);  
    }

    printf("\n");
}

int main() {
    Queue q;  
    initQueue(&q, 5);  

    enqueue(&q, 10); 
    enqueue(&q, 20); 
    enqueue(&q, 30); 
    enqueue(&q, 40); 
    enqueue(&q, 50); 
    
    displayQueue(&q);  

    enqueue(&q, 60);  

    printf("Dequeue: %d\n", dequeue(&q));  
    printf("Dequeue: %d\n", dequeue(&q));  

    displayQueue(&q);  

    return 0;  
}