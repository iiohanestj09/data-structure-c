#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int* data, top, capacity;
} Stack;

void init(Stack* st, int size) {
    st->data = (int*) malloc(size * sizeof(int));
    st->top = -1;
    st->capacity = size;
}

void push(Stack* st, int value) {
    if(st->top == st->capacity - 1) {
        printf("Stack penuh, gagal menambahkan\n");
        return;
    } else {
        st->data[++st->top] = value;
        printf("Data berhasil ditambahkan\n");
    }
}

void pop(Stack* st) {
    if(st->top == -1) {
        printf("Stack kosong, gagal menghapus\n");
    } else {
        st->top--;
        printf("Data berhasil dihapus\n");
    }
}

void destroy(Stack* st) {
    free(st->data);
}
