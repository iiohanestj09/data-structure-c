#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
} Stack;

void init(Stack* st) {
    st->top = NULL;
}

void push(Stack* st, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = st->top;
    st->top = newNode;

    printf("Data berhasil ditambahkan\n");
}

void pop(Stack* st) {
    if(st->top == NULL) {
        printf("Stack Kosong, Gagal Menghapus\n");
    } else {
        Node* temp = st->top;
        st->top = st->top->next;
        free(temp);

        printf("Data berhasil di-Pop\n");
    }
}

void destroy(Stack* st) {
    while(st->top != NULL) {
        pop(&st);
    }
    free(st);
}