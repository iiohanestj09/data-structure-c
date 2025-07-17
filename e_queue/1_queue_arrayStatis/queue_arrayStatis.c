#include <stdio.h>   
#define max 5        


typedef struct queue {
    int data[max];  
    int head, rear; 
} Queue;

void initQueue(Queue *q) {
    q->head = -1;  
    q->rear = -1;  
}


int isEmpty(Queue *q) {
    return q->head == -1;  
}

int isFull(Queue *q) {
    return q->rear == max - 1;  
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {  
        printf("Queue penuh!\n");  
        return;
    }
    if (isEmpty(q))  
        q->head = 0;
    
    q->rear++;  
    q->data[q->rear] = value;  
    printf("Enqueue: %d\n", value); 
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {  
        printf("Queue kosong!\n");
        return -1;
    }
    
    int temp = q->data[q->head];  
    printf("Dequeue: %d\n", temp); 

    if (q->head == q->rear) {  
        q->head = q->rear = -1;  
    } else {
        q->head++; 
    }

    return temp;  
}

void display(Queue *q) {
    if (isEmpty(q)) {  
        printf("Queue kosong!\n");
        return;
    }
    
    printf("Isi queue: ");
    for (int i = q->head; i <= q->rear; i++) {  
        printf("%d ", q->data[i]);  
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
    enqueue(&q, 50);  

    display(&q);  

    dequeue(&q);  
    dequeue(&q);  

    display(&q);  

    return 0;  
}
