#include <stdio.h>   
#include <stdlib.h>  

typedef struct {
    int *data;      // pointer ke array dinamis untuk menyimpan elemen stack
    int top;        
    int capacity;   
} Stack;

void initStack(Stack *s, int size) {
    s->data = (int*) malloc(size * sizeof(int)); 
    s->top = -1;    
    s->capacity = size; 
}

int isEmpty(Stack *s) {
    return s->top == -1;  
}

void push(Stack *s, int value) {
    if (s->top == s->capacity - 1) {  
        s->capacity *= 2; 
        s->data = (int*) realloc(s->data, s->capacity * sizeof(int)); 
        printf("Ukuran stack bertambah menjadi %d\n", s->capacity); 
    }

    s->top++;  
    s->data[s->top] = value; 
    printf("Push: %d\n", value); 
}

int pop(Stack *s) {
    if (isEmpty(s)) { 
        printf("Stack kosong, tidak bisa pop!\n"); 
        return -1; 
    }
    
    int poppedValue = s->data[s->top]; 
    s->top--;  
    return poppedValue; 
}


int peek(Stack *s) {
    if (isEmpty(s)) { 
        printf("Stack kosong!\n"); 
        return -1; 
    }
    return s->data[s->top]; 
}

void displayStack(Stack *s) {
    if (isEmpty(s)) { 
        printf("Stack kosong!\n"); 
        return; 
    }
    
    printf("Isi Stack: "); 
    for (int i = s->top; i >= 0; i--) { 
        printf("%d ", s->data[i]); 
    }
    printf("\n"); 
}

int main() {
    Stack s; 
    initStack(&s, 5); 

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    displayStack(&s); 

    push(&s, 60); 

    printf("Pop: %d\n", pop(&s)); 
    printf("Pop: %d\n", pop(&s)); 

    displayStack(&s); 

    printf("Elemen teratas: %d\n", peek(&s)); 

    return 0;
}
