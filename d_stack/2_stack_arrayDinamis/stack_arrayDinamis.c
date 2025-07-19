#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int size) {
    Stack* st = (Stack*) malloc(sizeof(Stack));
    st->data = (int*) malloc(size * sizeof(int));
    st->top = -1;
    st->capacity = size;
    return st;
}

void push(Stack* st, int value) {
    if (st->top == st->capacity - 1) {
        printf("Stack penuh, gagal menambahkan\n");
        return;
    }
    st->data[++st->top] = value;
    printf("Data berhasil ditambahkan\n");
}

void pop(Stack* st) {
    if (st->top == -1) {
        printf("Stack kosong, gagal menghapus\n");
        return;
    }
    st->top--;
    printf("Data berhasil dihapus\n");
}

void destroy(Stack* st) {
    free(st->data);
    free(st);
}

int main() {
    Stack* st = createStack(5);

    push(st, 10);
    push(st, 20);
    push(st, 30);
    pop(st);

    push(st, 40);
    push(st, 50);
    push(st, 60);

    pop(st);
    push(st, 70);

    destroy(st);
    return 0;
}
