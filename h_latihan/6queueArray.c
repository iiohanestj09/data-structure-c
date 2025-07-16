#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int* data;
    int head;
    int tail;
    int size;
    int capacity;
} Queue;

void init(Queue* que, int sizeX) {
    que->data = (int*) malloc(sizeX * sizeof(int));
    que->head = que->tail = -1;
    que->size = 0;
    que->capacity = sizeX;
}

void enqueue(Queue* que, int value) {
    if (que->size == que->capacity) {
        printf("Gagal Enqueue, Queue Penuh\n");
        return;
    } else {
        if (que->head == -1) {
            que->head = 0;
        }

        que->tail = (que->tail + 1) % que->capacity;
        que->data[que->tail] = value;
        que->size++;

        printf("Data berhasil ditambahkan\n");
    }
}

void dequeue(Queue* que) {
    if (que->size == 0) {
        printf("Gagal Dequeue, Queue Kosong\n");
        return;
    } else {
        if (que->size == 1) {
            que->head = que->tail = -1;
        } else {
            que->head++;
        }
        
        que->size--;
        printf("Data Berhasil dihapus\n");
    }
}

void destroy(Queue* que) {
    free(que->data);
}